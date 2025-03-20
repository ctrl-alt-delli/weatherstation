<template>
  <v-container fluid class="bg-surface justify-center">
    <h2>Live Weather Dashboard</h2>
    <p>Monitor real-time air temperature, heat index, humidity, and other environmental factors. The data updates automatically to keep you informed.</p>
    <v-row>
      <!-- Temperature and Heat Index Chart -->
      <v-col cols="12" md="6">
        <figure class="highcharts-figure" style="max-width: 1200px; height: 400px;">
          <div id="container" style="height: 100%;"></div>
        </figure>
      </v-col>
      <!-- Humidity Chart -->
      <v-col cols="12" md="6">
        <figure class="highcharts-figure" style="height: 400px;">
          <div id="container1" style="height: 100%;"></div>
        </figure>
      </v-col>
    </v-row>

    <v-row>
      <!-- Air Pressure Chart -->
      <v-col cols="12" md="6">
        <figure class="highcharts-figure" style="max-width: 1200px; height: 400px;">
          <div id="container2" style="height: 100%;"></div>
        </figure>
      </v-col>
      <!-- Altitude Chart -->
      <v-col cols="12" md="6">
        <figure class="highcharts-figure" style="height: 400px;">
          <div id="container3" style="height: 100%;"></div>
        </figure>
      </v-col>
    </v-row>

    <v-row>
      <!-- Soil Moisture Chart -->
      <v-col cols="12" md="6">
        <figure class="highcharts-figure" style="max-width: 1200px; height: 400px;">
          <div id="container4" style="height: 100%;"></div>
        </figure>
      </v-col>
    </v-row>
  </v-container>
</template>
  
<script setup>
import { ref,reactive,watch ,onMounted, onBeforeUnmount,computed } from "vue";  
import { useRoute ,useRouter } from "vue-router";
import { useMqttStore } from '@/store/mqttStore'; // Import Mqtt Store 
import { storeToRefs } from "pinia"; 
import { useAppStore } from "@/store/appStore";
// Highcharts, Load the exporting module and Initialize exporting module.
import Highcharts from 'highcharts';
import more from 'highcharts/highcharts-more';
import Exporting from 'highcharts/modules/exporting';
Exporting(Highcharts);
more(Highcharts);

// VARIABLES
const router      = useRouter();
const route       = useRoute();  
const Mqtt          = useMqttStore(); 
const AppStore = useAppStore();
const { payload, payloadTopic } = storeToRefs(Mqtt); 
const points = ref(10); // Specify the quantity of points to be shown on the live graph simultaneously.
const shift = ref(false);

// Chart references
const tempHiChart = ref(null);
const humidHiChart = ref(null);
const pressureHiChart = ref(null);
const altitudeHiChart = ref(null);
const soilHiChart = ref(null);

const temperature = computed(()=>{
  if(!!payload.value){
  return `${payload.value.temperature.toFixed(2)} °C`;
  }
  });
  
  const heatindex = computed(()=>{
  if(!!payload.value){
  return `${payload.value.heat_index.toFixed(2)} °C`;
  }
  });
  
  const humidity = computed(()=>{
  if(!!payload.value){
  return `${payload.value.humidity.toFixed(2)} %`;
  }
  });

  const pressure = computed(() =>{
    if(!!payload.value){
  return `${payload.value.pressure.toFixed(2)} %`;
  }
  });

  const altitude = computed(() =>{
    if(!!payload.value){
  return `${payload.value.altitude.toFixed(2)} %`;
  }
  });

  const soil = computed(() =>{
    if(!!payload.value){
  return `${payload.value.soil.toFixed(2)} %`;
  }
  });
  
  const CreateCharts = async () => {
  // TEMPERATURE CHART
  tempHiChart.value = Highcharts.chart('container', {
  chart: { zoomType: 'x' },
  title: { text: 'Air Temperature and Heat Index Analysis', align: 'left' },
  yAxis: {
  title: { text: 'Air Temperature & Heat Index' , style:{color:'#000000'}},
  labels: { format: '{value} °C' }
  },
  
  xAxis: {
  type: 'datetime',
  title: { text: 'Time', style:{color:'#000000'} },
  },
  
  tooltip: { shared:true, },
  
  series: [
  {
  name: 'Temperature',
  type: 'spline',
  data: [],
  turboThreshold: 0,
  color: '#F8C8DC'
  },
  {
  name: 'Heat Index',
  type: 'spline',
  data: [],
  turboThreshold: 0,
  color: '#E30B5C'
  } ],
  });
  
  // HUMIDITY CHART
  humidHiChart.value = Highcharts.chart('container1', {
  chart: { zoomType: 'x' },
  title: { text: 'Humidity Analysis', align: 'left' },
  yAxis: {
  title: { text: 'Humidity Analysis' , style:{color:'#000000'}},
  labels: { format: '{value} %' }
  },
  
  xAxis: {
  type: 'datetime',
  title: { text: 'Time', style:{color:'#000000'} },
  },
  
  tooltip: { shared:true, },
  
  series: [
  {
  name: 'Humidity',
  type: 'spline',
  data: [],
  turboThreshold: 0,
  color: '#E30B5C'
  }],
  });

  // AIR PRESSURE CHART
  pressureHiChart.value = Highcharts.chart('container2', {
  chart: { zoomType: 'x' },
  title: { text: 'Air Pressure Analysis', align: 'left' },
  yAxis: {
  title: { text: 'Air Pressure' , style:{color:'#000000'}},
  labels: { format: '{value} hPa' }
  },
  
  xAxis: {
  type: 'datetime',
  title: { text: 'Time', style:{color:'#000000'} },
  },
  
  tooltip: { shared:true, },
  
  series: [
  {
  name: 'Air Pressure',
  type: 'spline',
  data: [],
  turboThreshold: 0,
  color: '#E30B5C'
  }],
  }),

  altitudeHiChart.value = Highcharts.chart('container3', {
  chart: { zoomType: 'x' },
  title: { text: 'Altitude Analysis', align: 'left' },
  yAxis: {
  title: { text: 'Altitude' , style:{color:'#000000'}},
  labels: { format: '{value} m' }
  },
  
  xAxis: {
  type: 'datetime',
  title: { text: 'Time', style:{color:'#000000'} },
  },
  
  tooltip: { shared:true, },
  
  series: [
  {
  name: 'Altitude',
  type: 'spline',
  data: [],
  turboThreshold: 0,
  color: '#E30B5C'
  }],
  }),

  soilHiChart.value = Highcharts.chart('container4', {
  chart: { zoomType: 'x' },
  title: { text: 'Soil Moisture Analysis', align: 'left' },
  yAxis: {
  title: { text: 'Soil Moisture' , style:{color:'#000000'}},
  labels: { format: '{value} %' }
  },
  
  xAxis: {
  type: 'datetime',
  title: { text: 'Time', style:{color:'#000000'} },
  },
  
  tooltip: { shared:true, },
  
  series: [
  {
  name: 'Soil Moisture',
  type: 'spline',
  data: [],
  turboThreshold: 0,
  color: '#E30B5C'
  }],
  }
);
  
  };
  
  watch(payload,(data)=> {
  console.log(data);
  if(points.value > 0){ points.value -- ; }
  else{ shift.value = true; }
  
  tempHiChart.value.series[0].addPoint({y:parseFloat(data.temperature.toFixed(2)) ,x: data.timestamp * 1000 },
  true, shift.value);
  
  tempHiChart.value.series[1].addPoint({y:parseFloat(data.heat_index.toFixed(2)) ,x: data.timestamp * 1000 },
  true, shift.value);
  
  // Update Humidity chart
  humidHiChart.value.series[0].addPoint({ y: parseFloat(data.humidity.toFixed(2)), x: data.timestamp * 1000 },
  true, shift.value);

  // Update Air Pressure chart
  pressureHiChart.value.series[0].addPoint({ y: parseFloat(data.pressure.toFixed(2)), x: data.timestamp * 1000 },
  true, shift.value);

  altitudeHiChart.value.series[0].addPoint({ y: parseFloat(data.altitude.toFixed(2)), x: data.timestamp * 1000 },
  true, shift.value);

  soilHiChart.value.series[0].addPoint({ y: parseFloat(data.soil_moisture.toFixed(2)), x: data.timestamp * 1000 },
  true, shift.value);
  
  })
  
  
  const updateLineCharts = async ()=>{
  if(!!start.value && !!end.value){
  // Convert output from Textfield components to 10 digit timestamps
  let startDate = new Date(start.value).getTime() / 1000;
  let endDate = new Date(end.value).getTime() / 1000;
  
  // Fetch data from backend
  const data = await AppStore.getAllInRange(startDate,endDate);
  
  // Create arrays for each plot
  let temperature = [];
  let heatindex = [];
  
  // Iterate through data variable and transform object to format recognized by highcharts
  data.forEach(row => {
  temperature.push({"x": row.timestamp * 1000, "y": parseFloat(row.temperature.toFixed(2)) });
  heatindex.push({ "x": row.timestamp * 1000,"y": parseFloat(row.heatindex.toFixed(2)) });
  console.log(temperature);
  });
  }
  }
  
  // FUNCTIONS
  onMounted(()=>{
  // THIS FUNCTION IS CALLED AFTER THIS COMPONENT HAS BEEN MOUNTED
  CreateCharts();
  Mqtt.connect(); // Connect to Broker located on the backend 
  
  setTimeout( ()=>{ 
  // Subscribe to each topic 
  Mqtt.subscribe("620157584"); 
  console.log('Subscribed to topic 620157584');
  },3000); 
  });
  
  
  onBeforeUnmount(()=>{
  // THIS FUNCTION IS CALLED RIGHT BEFORE THIS COMPONENT IS UNMOUNTED
  // unsubscribe from all topics 
  Mqtt.unsubcribeAll(); 
  });
  
  
  </script>
  
  
<style scoped>
@import url('https://fonts.googleapis.com/css2?family=Great+Vibes&display=swap');
figure {
  border: 2px solid black;
}

h2 {
  font-family: 'Great Vibes', cursive;
  font-size: 2.5rem; /* Adjusted for better responsiveness */
}
</style>