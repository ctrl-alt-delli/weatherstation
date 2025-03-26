<template>
  <v-container fluid class="bg-surface">
    <h2 class="text-center">Temperature and Humidity Analysis</h2>
    <!-- First Row -->
    <v-row max-width="1200px" class="py-1">
      <!-- First Column -->
      <v-col>
        <v-sheet class="pa-2" height="250">
          <p class="pink-text">Enter date range for Analysis</p>
          <v-divider color="#E30B5C"></v-divider>
          <v-text-field
            label="Start date"
            type="date"
            density="compact"
            variant="solo-inverted"
            style="max-width: 300px;"
            class="mr-5"
            flat
            v-model="start"
          ></v-text-field>
          <v-text-field
            label="End date"
            type="date"
            density="compact"
            variant="solo-inverted"
            style="max-width: 300px;"
            flat
            v-model="end"
          ></v-text-field>
          <v-spacer></v-spacer>
          <v-btn @click="updateLineCharts(),updateCards(),updateHistogramCharts(),updateScatterPlots();" class="text-caption" color="#E30B5C" variant="tonal">Analyze</v-btn>
        </v-sheet>
      </v-col>

      <!-- Second Column -->
      <v-col cols="3">
        <v-card
          width="250"
          variant="outlined"
          color="primary"
          density="compact"
          rounded="lg">
        <v-card-item style="padding-bottom: 0; margin-bottom: -8px">
          <span style="font-size: 0.8rem; display: flex; justify-content: center; align-items: center; color: #E30B5C; margin-bottom: 4px">Temperature</span>
            <div style="display: flex; justify-content: space-evenly; width: 100%;">
              <!-- Min Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Min</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ temperature.min }}
                </v-chip>
              </div>
              
              <!-- Range Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Range</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ temperature.range }}
                </v-chip>
              </div>
              
              <!-- Max Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Max</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ temperature.max }}
                </v-chip>
              </div>
            </div>
          </v-card-item>

          <v-card-item class="text-center">
            <span class="text-h1 text-primary font-weight-bold pink-text">{{ temperature.avg }}</span>
          </v-card-item>
        </v-card>
      </v-col>

      <!-- Column 2: Humidity Card (similar to Temperature Card) -->
      <v-col cols="3">
        <v-card
          width="250"
          variant="outlined"
          color="primary"
          density="compact"
          rounded="lg"
        >
        <v-card-item style="padding-bottom: 0; margin-bottom: -8px">
          <span style="font-size: 0.8rem; display: flex; justify-content: center; align-items: center; color: #E30B5C; margin-bottom: 4px">Humidity</span>
            <div style="display: flex; justify-content: space-evenly; width: 100%;">
              <!-- Min Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Min</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ humidity.min }}
                </v-chip>
              </div>
              
              <!-- Range Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Range</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ humidity.range }}
                </v-chip>
              </div>
              
              <!-- Max Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Max</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ humidity.max }}
                </v-chip>
              </div>
            </div>
          </v-card-item>

          <v-card-item class="text-center">
            <span class="text-h1 text-primary font-weight-bold pink-text">{{ humidity.avg }}</span>
          </v-card-item>
        </v-card>
      </v-col>
    </v-row>

    <!-- Second Row -->
    <v-row max-width="1200px">
      <!-- First Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container"></div>
        </figure>
      </v-col>

      <!-- Second Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container0"></div>
        </figure>
      </v-col>
    </v-row>

    <!-- Third Row -->
    <v-row max-width="1200px">
      <!-- First Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container1"></div>
        </figure>
      </v-col>

      <!-- Second Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container2"></div>
        </figure>
      </v-col>

      <!-- Third Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container3"></div>
        </figure>
      </v-col>
    </v-row>
  </v-container>

  <v-container fluid class="bg-surface">
    <h2 class="text-center">Altitude and Air Pressure Analysis</h2>
    <!-- First Row -->
    <v-row max-width="1200px" class="py-1">
      <!-- First Column -->
      <v-col>
        <v-sheet class="pa-2" height="250">
          <p class="pink-text">Enter date range for Analysis</p>
          <v-divider color="#E30B5C"></v-divider>
          <v-text-field
            label="Start date"
            type="date"
            density="compact"
            variant="solo-inverted"
            style="max-width: 300px;"
            class="mr-5"
            flat
            v-model="start"
          ></v-text-field>
          <v-text-field
            label="End date"
            type="date"
            density="compact"
            variant="solo-inverted"
            style="max-width: 300px;"
            flat
            v-model="end"
          ></v-text-field>
          <v-spacer></v-spacer>
          <v-btn @click="updateLineCharts(),updateCards(),updateHistogramCharts(),updateScatterPlots();" class="text-caption" color="#E30B5C" variant="tonal">Analyze</v-btn>
        </v-sheet>
      </v-col>

      <!-- Second Column -->
      <v-col cols="3">
        <v-card
          width="250"
          variant="outlined"
          color="primary"
          density="compact"
          rounded="lg"
        >
        <v-card-item style="padding-bottom: 0; margin-bottom: -8px">
          <span style="font-size: 0.8rem; display: flex; justify-content: center; align-items: center; color: #E30B5C; margin-bottom: 4px">Air Pressure</span>
            <div style="display: flex; justify-content: space-evenly; width: 100%;">
              <!-- Min Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Min</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ pressure.min }}
                </v-chip>
              </div>
              
              <!-- Range Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Range</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ pressure.range }}
                </v-chip>
              </div>
              
              <!-- Max Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Max</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ pressure.max }}
                </v-chip>
              </div>
            </div>
          </v-card-item>

          <v-card-item class="text-center">
            <span class="text-h1 text-primary font-weight-bold pink-text">{{ pressure.avg }}</span>
          </v-card-item>
        </v-card>
      </v-col>

      <!-- Column 2: Humidity Card -->
      <v-col cols="3">
        <v-card
          width="250"
          variant="outlined"
          color="primary"
          density="compact"
          rounded="lg"
        >
        <v-card-item style="padding-bottom: 0; margin-bottom: -8px">
          <span style="font-size: 0.8rem; display: flex; justify-content: center; align-items: center; color: #E30B5C; margin-bottom: 4px">Altitude</span>
            <div style="display: flex; justify-content: space-evenly; width: 100%;">
              <!-- Min Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Min</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ altitude.min }}
                </v-chip>
              </div>
              
              <!-- Range Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Range</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ altitude.range }}
                </v-chip>
              </div>
              
              <!-- Max Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Max</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ altitude.max }}
                </v-chip>
              </div>
            </div>
          </v-card-item>

          <v-card-item class="text-center">
            <span class="text-h1 text-primary font-weight-bold pink-text">{{ altitude.avg }}</span>
          </v-card-item>
        </v-card>
      </v-col>
    </v-row>

    <!-- Second Row -->
    <v-row max-width="1200px">
      <!-- First Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container4"></div>
        </figure>
      </v-col>

      <!-- Second Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container5"></div>
        </figure>
      </v-col>
    </v-row>

    <!-- Third Row -->
    <v-row max-width="1200px">
      <!-- First Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container6"></div>
        </figure>
      </v-col>

      <!-- Second Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container7"></div>
        </figure>
      </v-col>
    </v-row>
  </v-container>

  <v-container fluid class="bg-surface">
    <h2 class="text-center">Soil Moisture Analysis</h2>
    <!-- First Row -->
    <v-row max-width="1200px" class="py-1">
      <!-- First Column -->
      <v-col>
        <v-sheet class="pa-2" height="250">
          <p class="pink-text">Enter date range for Analysis</p>
          <v-divider color="#E30B5C"></v-divider>
          <v-text-field
            label="Start date"
            type="date"
            density="compact"
            variant="solo-inverted"
            style="max-width: 300px;"
            class="mr-5"
            flat
            v-model="start"
          ></v-text-field>
          <v-text-field
            label="End date"
            type="date"
            density="compact"
            variant="solo-inverted"
            style="max-width: 300px;"
            flat
            v-model="end"
          ></v-text-field>
          <v-spacer></v-spacer>
          <v-btn @click="updateLineCharts(),updateCards(),updateHistogramCharts(),updateScatterPlots();" class="text-caption" color="#E30B5C" variant="tonal">Analyze</v-btn>
        </v-sheet>
      </v-col>

      <!-- Second Column -->
      <v-col cols="3">
        <v-card
          width="250"
          variant="outlined"
          color="primary"
          density="compact"
          rounded="lg"
        >
        <v-card-item style="padding-bottom: 0; margin-bottom: -8px">
          <span style="font-size: 0.8rem; display: flex; justify-content: center; align-items: center; color: #E30B5C; margin-bottom: 4px">Soil Moisture</span>
            <div style="display: flex; justify-content: space-evenly; width: 100%;">
              <!-- Min Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Min</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ soil_moisture.min }}
                </v-chip>
              </div>
              
              <!-- Range Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Range</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ soil_moisture.range }}
                </v-chip>
              </div>
              
              <!-- Max Value with Label -->
              <div style="display: flex; flex-direction: column; align-items: center; justify-content: center; width: 100%">
                <span style="font-size: 0.75rem; color: #666; margin-bottom: 4px">Max</span>
                <v-chip style="background-color: #E18AAA; width: 100%; justify-content: center; color: white;">
                  {{ soil_moisture.max }}
                </v-chip>
              </div>
            </div>
          </v-card-item>

          <v-card-item class="text-center">
            <span class="text-h1 text-primary font-weight-bold pink-text">{{ soil_moisture.avg }}</span>
          </v-card-item>
        </v-card>
      </v-col>
    </v-row>

    <!-- Second Row -->
    <v-row max-width="1200px">
      <!-- First Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container8"></div>
        </figure>
      </v-col>

      <!-- Second Column -->
      <v-col cols="12">
        <figure class="highcharts-figure">
          <div id="container9"></div>
        </figure>
      </v-col>
    </v-row>
  </v-container>
  <v-container class="bg-surface">
    <v-row class="d-flex justify-center">
      <v-col class="text-center">
        <v-btn href="/privacy">Privacy Policy</v-btn>
        <v-btn href="/contact">Contact</v-btn>
      </v-col>
      <v-col class="text-center">
        <v-btn icon href="https://facebook.com">
          <v-icon>mdi-facebook</v-icon>
        </v-btn>
        <v-btn icon href="https://twitter.com">
          <v-icon>mdi-twitter</v-icon>
        </v-btn>
        <v-btn icon href="https://instagram.com">
          <v-icon>mdi-instagram</v-icon>
        </v-btn>
      </v-col>
      <v-col class="text-center">
        <p>© 2025 Your Weather Station</p>
      </v-col>
    </v-row>
    <VRow class="d-flex align-center justify-center">
    <!-- Components Button -->
    <VCol cols="auto">
      <VBtn
        href="https://vuetifyjs.com/components/all/"
        min-width="164"
        rel="noopener noreferrer"
        target="_blank"
        variant="text"
        size="small"  
      >
        <VIcon icon="mdi-view-dashboard" size="large" start />
        Components
      </VBtn>
    </VCol>

    <!-- Get Started Button (Pink) -->
    <VCol cols="auto">
      <VBtn
        color="pink"
        href="https://vuetifyjs.com/introduction/why-vuetify/#feature-guides"
        min-width="228"
        rel="noopener noreferrer"
        size="medium"  
        target="_blank"
        variant="flat"
      >
        <VIcon icon="mdi-speedometer" size="large" start />
        Get Started
      </VBtn>
    </VCol>

    <!-- Community Button -->
    <VCol cols="auto">
      <VBtn
        href="https://community.vuetifyjs.com/"
        min-width="164"
        rel="noopener noreferrer"
        target="_blank"
        variant="text"
        size="small"  
      >
        <VIcon icon="mdi-account-group" size="large" start />
        Community
      </VBtn>
    </VCol>
  </VRow>
</v-container>
</template>

<script setup>
/** JAVASCRIPT HERE */

// IMPORTS
import { ref,reactive,watch ,onMounted,onBeforeUnmount,computed } from "vue";  
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

const start   = ref("");
const end    = ref("");
const temperature = reactive({"min":0,"max":0,"avg":0,"range":0});
const humidity = reactive({"min":0,"max":0,"avg":0,"range":0});
const pressure = reactive({"min":0,"max":0,"avg":0,"range":0});
const altitude = reactive({"min":0,"max":0,"avg":0,"range":0});
const soil_moisture = reactive({"min":0,"max":0,"avg":0,"range":0});

const tempHiChart = ref(null);
const humidHiChart = ref(null);
const freqHiChart = ref(null);
const scattertempHiChart = ref(null);
const scatterhumidHiChart = ref(null);
const altitudeHiChart = ref(null);
const pressureHiChart = ref(null);
const alt2HiChart = ref(null);
const scatteraltHiChart = ref(null);
const soilHiChart = ref(null);
const scattersoilHiChart = ref(null);

const points = ref(10); // Specify the quantity of points to be shown on the live graph simultaneously.
const shift = ref(false);

const CreateCharts = async () => {
// TEMPERATURE CHART
tempHiChart.value = Highcharts.chart('container', {
  chart: { zoomType: 'x' },
  title: { text: 'Temperature and Heat Index Analysis', align: 'left' },
  subtitle: { text: 'The heat index, also known as the "apparent temperature," is a measure that combines'
  +' air temperature and relative humidity to assess how hot it feels to the human body. The'
  + ' relationship between heat index and air temperature is influenced by humidity levels. As humidity increases, the '
  + 'heat index also rises, making the perceived temperature higher than the actual air temperature', align: 'left' },
  yAxis: {
      title: { text: 'Air Temperature & Heat Index' , style:{color:'#000000'}},
      labels: { format: '{value} °C' }
      },

  xAxis: {
      type: 'datetime',
      title: { text: 'Time', style:{color:'#000000'} },
  },

  tooltip: { shared:true,
      xDateFormat: '%Y-%m-%d %H:%M:%S',  // formats the x value as a date/time
        headerFormat: '<b>{point.key}</b><br/>',
        pointFormat: '<span style="color:{series.color}">{series.name}</span>: <b>{point.y} °C</b><br/>'},

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
humidHiChart.value = Highcharts.chart('container0', {
  chart: { zoomType: 'x' },
  title: { text: 'Humidity Analysis', align: 'left' },
  yAxis: {
      title: { text: 'Humidity' , style:{color:'#000000'}},
      labels: { format: '{value} %' }
      },

  xAxis: {
      type: 'datetime',
      title: { text: 'Time', style:{color:'#000000'} },
  },

  tooltip: { shared:true,
      xDateFormat: '%Y-%m-%d %H:%M:%S',  // formats the x value as a date/time
        headerFormat: '<b>{point.key}</b><br/>',
        pointFormat: '<span style="color:{series.color}">{series.name}</span>: <b>{point.y} %</b><br/>'},

  series: [
  {
      name: 'Humidity',
      type: 'spline',
      data: [],
      turboThreshold: 0,
      color: '#E30B5C'
  }],
});

// FREQUENCY CHART
freqHiChart.value = Highcharts.chart('container1', {
  chart: {
      type: 'column',
      zoomType: 'x',  // Enable zooming
  },
  title: {
      text: 'Frequency Distribution Analysis', // Chart title
      align: 'left'
  },
  yAxis: {
      title: {
          text: 'Frequency', // Y-axis title
          style: { color: '#000000' }
      },
      labels: {
          format: '{value}' // Display value without units
      }
  },
  
  tooltip: {
      formatter: function () {
      let unit = "";
      
      // Determine the unit based on series name
      if (this.series.name.toLowerCase().includes("humidity")) {
          unit = "%";
      } else if (this.series.name.toLowerCase().includes("temperature") || this.series.name.toLowerCase().includes("heat_index")) {
          unit = "°C";
      }

      return `<b>Frequency:</b> ${this.y} Hz <br/>
              <span style="color:${this.series.color}">${this.series.name}</span>: 
              <b>${this.x} ${unit}</b>`;
  }
  },
  series: [
      {
          name: 'Temperature',
          data: [], // Populate data for temperature
          turboThreshold: 0,
          color: '#E30B5C', // Temperature color 
          pointStart: Date.now(), // Start from the current time
          pointInterval: 3600000, // Set interval of 1 hour between data points
          tooltip: {
              pointFormat: '{point.y} °C', // Display temperature value
          }
      },
      {
          name: 'Humidity',
          data: [], // Populate data for humidity
          turboThreshold: 0,
          color: '#E18AAA', // Humidity color 
          pointStart: Date.now(),
          pointInterval: 3600000,
          tooltip: {
              pointFormat: '{point.y}%', // Display humidity percentage
          }
      },
      {
          name: 'Heat Index',
          data: [], // Populate data for heat index
          turboThreshold: 0,
          color: '#FF69B4', // Heat Index color 
          pointStart: Date.now(),
          pointInterval: 3600000,
          tooltip: {
              pointFormat: '{point.y} °C', // Display heat index value
          }
      }
  ],
});

scattertempHiChart.value = Highcharts.chart('container2', {
  chart: {
      type: 'scatter', // Scatter plot type
      zoomType: 'x' // Enable zooming along x-axis
  },
  title: {
      text: 'Temperature & Heat Index Correlation Analysis',
      align: 'left'
  },
  subtitle: {
      text: 'Visualize the relationship between Temperature and Heat Index as well as revealing patterns or trends in the data',
      align: 'left'
  },
  xAxis: {
      title: {
          text: 'Temperature',
          style: { color: '#000000' }
      },
      labels: {
          format: '{value} °C' // Display temperature values with °C
      }
  },
  yAxis: {
      title: {
          text: 'Heat Index',
          style: { color: '#000000' }
      },
      labels: {
          format: '{value} °C' // Display heat index values with °C
      }
  },
  tooltip: {
      pointFormat: 'Temperature: {point.x} °C <br/> Heat Index: {point.y} °C'
  },
  series: [
      {
          name: 'Analysis',
          type: 'scatter',
          data: [], // Data will be dynamically populated
          color: '#E30B5C', // Use a color to differentiate the points
          marker: {
              radius: 4, // Adjust point size
              symbol: 'circle'
          }
      }
  ]
});

scatterhumidHiChart.value = Highcharts.chart('container3', {
  chart: {
      type: 'scatter', // Scatter plot type
      zoomType: 'x' // Enable zooming along x-axis
  },
  title: {
      text: 'Humidity & Heat Index Correlation Analysis',
      align: 'left'
  },
  subtitle: {
      text: 'Visualize the relationship between Humidity and Heat Index as well as revealing patterns or trends in the data',
      align: 'left'
  },
  xAxis: {
      title: {
          text: 'Humidity',
          style: { color: '#000000' }
      },
      labels: {
          format: '{value} %' // Display humidity values in percentage
      }
  },
  yAxis: {
      title: {
          text: 'Heat Index',
          style: { color: '#000000' }
      },
      labels: {
          format: '{value} °C' // Display heat index in °C
      }
  },
  tooltip: {
      pointFormat: 'Humidity: {point.x} % <br/> Heat Index: {point.y} °C'
  },
  series: [
      {
          name: 'Analysis',
          type: 'scatter',
          data: [], // Data will be dynamically populated
          color: '#E30B5C', // Use a color to differentiate the points
          marker: {
              radius: 4, // Adjust point size
              symbol: 'circle'
          }
      }
  ]
});

// ALTITUDE CHART
altitudeHiChart.value = Highcharts.chart('container4', {
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

  tooltip: { shared:true,
      xDateFormat: '%Y-%m-%d %H:%M:%S',  // formats the x value as a date/time
        headerFormat: '<b>{point.key}</b><br/>',
        pointFormat: '<span style="color:{series.color}">{series.name}</span>: <b>{point.y} %</b><br/>'},

  series: [
  {
      name: 'Altitude',
      type: 'spline',
      data: [],
      turboThreshold: 0,
      color: '#E30B5C'
  }],
});

// PRESSURE CHART
pressureHiChart.value = Highcharts.chart('container5', {
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

  tooltip: { shared:true,
      xDateFormat: '%Y-%m-%d %H:%M:%S',  // formats the x value as a date/time
        headerFormat: '<b>{point.key}</b><br/>',
        pointFormat: '<span style="color:{series.color}">{series.name}</span>: <b>{point.y} %</b><br/>'},

  series: [
  {
      name: 'Air Pressure',
      type: 'spline',
      data: [],
      turboThreshold: 0,
      color: '#E30B5C'
  }],
});

alt2HiChart.value = Highcharts.chart('container7', {
  chart: { zoomType: 'x' },
  title: { text: 'Altitude and Air Pressure Analysis', align: 'left' },
  subtitle: { 
  text: 'Altitude and air pressure have an inverse relationship governed by the barometric formula. As altitude increases, ' +
  'atmospheric pressure decreases exponentially. This relationship is critical for aviation, weather forecasting, ' +
  'and environmental studies. The graph shows how these variables interact in real-world conditions.', align: 'left' },
  yAxis: {
      title: { text: 'Air Pressure' , style:{color:'#000000'}},
      labels: { format: '{value} hPa' }
      },

  xAxis: {
    title: { text: 'Altitude' , style:{color:'#000000'}},
    labels: { format: '{value} m' }
  },

  tooltip: {
    shared: true,
    headerFormat: '<b>{point.key}</b><br/>',
    pointFormat: '<span style="color:{series.color}">{series.name}</span>: ' +
                 '<b>{point.y} {series.options.tooltipValueSuffix}</b><br/>',
    crosshairs: true
  },
  legend: {
    layout: 'horizontal',
    align: 'center',
    verticalAlign: 'bottom'
  },
  plotOptions: {
    series: {
      marker: {
        radius: 4,
        symbol: 'circle'
      }
    }
  },
  series: [
    {
      name: 'Air Pressure',
      type: 'spline',
      data: [],
      turboThreshold: 0,
      color: '#E30B5C', 
      tooltip: {
        valueSuffix: ' hPa'
      },
      yAxis: 0
    },
  ]
});

scatteraltHiChart.value = Highcharts.chart('container6', {
  chart: {
      type: 'scatter', // Scatter plot type
      zoomType: 'x' // Enable zooming along x-axis
  },
  title: {
      text: 'Altitude & Air Pressure',
      align: 'left'
  },
  subtitle: {
      text: 'Visualize the relationship between Altitude and Air Pressure as well as revealing patterns or trends in the data',
      align: 'left'
  },
  xAxis: {
      title: {
          text: 'Altitude',
          style: { color: '#000000' }
      },
      labels: {
          format: '{value} m' // Display temperature values with °C
      }
  },
  yAxis: {
      title: {
          text: 'Air Pressure',
          style: { color: '#000000' }
      },
      labels: {
          format: '{value} hPa' // Display heat index values with °C
      }
  },
  tooltip: {
      pointFormat: 'Altitude: {point.x} m <br/> Air Pressure: {point.y} hPa'
  },
  series: [
      {
          name: 'Analysis',
          type: 'scatter',
          data: [], // Data will be dynamically populated
          color: '#E30B5C', // Use a color to differentiate the points
          marker: {
              radius: 4, // Adjust point size
              symbol: 'circle'
          }
      }
  ]
});

soilHiChart.value = Highcharts.chart('container8', {
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

  tooltip: { shared:true,
      xDateFormat: '%Y-%m-%d %H:%M:%S',  // formats the x value as a date/time
        headerFormat: '<b>{point.key}</b><br/>',
        pointFormat: '<span style="color:{series.color}">{series.name}</span>: <b>{point.y} %</b><br/>'},

  series: [
  {
      name: 'Soil Moisture',
      type: 'spline',
      data: [],
      turboThreshold: 0,
      color: '#E30B5C'
  }],
});

scattersoilHiChart.value = Highcharts.chart('container9', {
  chart: {
      type: 'scatter', // Scatter plot type
      zoomType: 'x' // Enable zooming along x-axis
  },
  title: {
      text: 'Soil Moisture & Humidity Correlation Analysis',
      align: 'left'
  },
  subtitle: {
      text: 'Visualize the relationship between Soil Moisture and Humidity as well as revealing patterns or trends in the data',
      align: 'left'
  },
  xAxis: {
      title: {
          text: 'Soil Moisture',
          style: { color: '#000000' }
      },
      labels: {
          format: '{value} %' // Display temperature values with °C
      }
  },
  yAxis: {
      title: {
          text: 'Humidity',
          style: { color: '#000000' }
      },
      labels: {
          format: '{value} %' // Display heat index values with °C
      }
  },
  tooltip: {
      pointFormat: 'Soil Moisture: {point.x} % <br/> Humidityx: {point.y} %'
  },
  series: [
      {
          name: 'Analysis',
          type: 'scatter',
          data: [], // Data will be dynamically populated
          color: '#E30B5C', // Use a color to differentiate the points
          marker: {
              radius: 4, // Adjust point size
              symbol: 'circle'
          }
      }
  ]
});
};

const updateLineCharts = async () => {
if (!!start.value && !!end.value) {
  // Convert output from Textfield components to 10 digit timestamps
  let startDate = new Date(start.value).getTime() / 1000;
  let endDate = new Date(end.value).getTime() / 1000;

  // Fetch data from backend
  const data = await AppStore.getAllInRange(startDate, endDate);
  // Create arrays for each plot
  let temperature = [];
  let heatindex = [];
  let humidity = [];
  let altitude = [];
  let pressure = [];
  let soil = [];
  const altitudePressureData = [];

  // Iterate through data variable and transform object to format recognized by highcharts
  data.forEach(row => {
    temperature.push({
      "x": row.timestamp * 1000,
      "y": parseFloat(row.temperature.toFixed(2))
    });
    heatindex.push({
      "x": row.timestamp * 1000,
      "y": parseFloat(row.heat_index.toFixed(2)),
    });
    humidity.push({
      "x": row.timestamp * 1000,
      "y": parseFloat(row.humidity.toFixed(2))
    });
    altitude.push({
      "x": row.timestamp * 1000,
      "y": parseFloat(row.altitude.toFixed(2))
    });
    pressure.push({
      "x": row.timestamp * 1000,
      "y": parseFloat(row.pressure.toFixed(2))
    });
    soil.push({
      "x": row.timestamp * 1000,
      "y": parseFloat(row.soil_moisture.toFixed(2))
    });
    altitudePressureData.push({ 
        x: parseFloat(row.altitude.toFixed(2)), 
        y: parseFloat(row.pressure.toFixed(2)),
        timestamp: row.timestamp * 1000 // Optional: for tooltip
      });
  });

  // Add data to Temperature and Heat Index chart
  tempHiChart.value.series[0].setData(temperature);
  tempHiChart.value.series[1].setData(heatindex);
  humidHiChart.value.series[0].setData(humidity);
  altitudeHiChart.value.series[0].setData(altitude);
  soilHiChart.value.series[0].setData(soil);
  pressureHiChart.value.series[0].setData(pressure);
  alt2HiChart.value.update({
      xAxis: { title: { text: 'Altitude' }},
      yAxis: { title: { text: 'Air Pressure' }}
    });
    
    alt2HiChart.value.series[0].update({
      type: 'line',
      name: 'Pressure vs Altitude',
      data: altitudePressureData.sort((a, b) => a.x - b.x), 
      color: '#E30B5C',
      tooltip: {
        headerFormat: 'Altitude: <b>{point.x} m</b><br/>',
        pointFormat: 'Pressure: <b>{point.y} </b><br/>' +
                     '<small>Time: {point.timestamp:%Y-%m-%d %H:%M}</small>'
      }
    });
}
};

const updateHistogramCharts = async () => {
  // Retrieve Min, Max, Avg, Spread/Range for Column graph
  if (!!start.value && !!end.value) {
      // 1. Convert start and end dates collected fron TextFields to 10 digit timestamps
      let startDate = new Date(start.value).getTime() / 1000;
      let endDate = new Date(end.value).getTime() / 1000;
      // Subsequently, create startDate and endDate variables and then save the respective timestamps in these
      // variables
      // 2. Fetch data(temp, humid and hi) from backend by calling the getFreqDistro API functions for each
      const temp = await AppStore.getFreqDistro("temperature", startDate, endDate);
      console.log(startDate, endDate);
      const humid = await AppStore.getFreqDistro("humidity", startDate, endDate);
      const hi = await AppStore.getFreqDistro("heat_index", startDate, endDate);
      const alt = await AppStore.getFreqDistro("altitude", startDate, endDate);
      const press = await AppStore.getFreqDistro("pressure", startDate, endDate);

      // 3. create an empty array for each variable (temperature, humidity and heatindex)
      // see example below
      let temperature = [];
      let humidity = [];
      let heatIndex = [];

      // 4. Iterate through the temp variable, which contains temperature data fetched from the backend
      // transform the data to {"x": x_value,"y": y_value} format and then push it to the temperature array created
      // previously
      // see example below
      temp.forEach(row => {
          temperature.push({ "x": row["_id"], "y": row["count"] });
      });

      // 5. Iterate through the humid variable, which contains humidity data fetched from the backend
      // transform the data to {"x": x_value,"y": y_value} format and then push it to the humidity array created
      // previously
      humid.forEach(row => {
          humidity.push({ "x": row["_id"], "y": row["count"] });
      });

      // 6. Iterate through the humid variable, which contains heat index data fetched from the backend
      // transform the data to {"x": x_value,"y": y_value} format and then push it to the heatindex array created
      // previously
      hi.forEach(row => {
          heatIndex.push({ "x": row["_id"], "y": row["count"] });
      });


      // 7. update series[0] for the histogram/Column chart with temperature data
      // see example below
      freqHiChart.value.series[0].setData(temperature);

      // 8. update series[1] for the histogram/Column chart with humidity data
      freqHiChart.value.series[1].setData(humidity);
      // 9. update series[2] for the histogram/Column chart with heat index data
      freqHiChart.value.series[2].setData(heatIndex);
  }
};


const updateCards = async () => {
  console.log("Entered function");
  // Retrieve Min, Max, Avg, Spread/Range
  if (!!start.value && !!end.value) {
    console.log("enetered if");
      // 1. Convert start and end dates collected from TextFields to 10-digit timestamps
      let startDate = new Date(start.value).getTime() / 1000;
      let endDate = new Date(end.value).getTime() / 1000;

      // 2. Fetch data from backend by calling the API functions
      const temp = await AppStore.getTemperatureMMAR(startDate, endDate);
      console.log(temp);
      const humid = await AppStore.getHumidityMMAR(startDate, endDate);
      const heat = await AppStore.getHeatIndexMMAR(startDate, endDate);
      const alt = await AppStore.getAltitudeMMAR(startDate, endDate);
      const press = await AppStore.getPressureMMAR(startDate, endDate);
      const soil = await AppStore.getSoilMoistureMMAR(startDate, endDate);

      // 3. Complete for min, avg, and range
      temperature.max = temp[0].max.toFixed(1);
      temperature.avg = temp[0].avg.toFixed(1);
      temperature.min = temp[0].min.toFixed(1);
      temperature.range = temp[0].range.toFixed(1);


      // 4. Complete max, min, avg, and range for the humidity variable
      humidity.max = humid[0].max.toFixed(1);
      humidity.avg = humid[0].avg.toFixed(1);
      humidity.min = humid[0].min.toFixed(1);
      humidity.range = humid[0].range.toFixed(1);

      altitude.max = alt[0].max.toFixed(1);
      altitude.avg = alt[0].avg.toFixed(1);
      altitude.min = alt[0].min.toFixed(1);
      altitude.range = alt[0].range.toFixed(1);

      pressure.max = press[0].max.toFixed(1);
      pressure.avg = press[0].avg.toFixed(0);
      pressure.min = press[0].min.toFixed(1);
      pressure.range = press[0].range.toFixed(1);

      soil_moisture.max = soil[0].max.toFixed(1);
      soil_moisture.avg = soil[0].avg.toFixed(0);
      soil_moisture.min = soil[0].min.toFixed(1);
      soil_moisture.range = soil[0].range.toFixed(1);
  }
};

const updateScatterPlots = async ()=>{
  if(!!start.value && !!end.value){
      // Convert output from Textfield components to 10 digit timestamps
      let startDate = new Date(start.value).getTime() / 1000;
      let endDate = new Date(end.value).getTime() / 1000;
      // Fetch data from backend
      const data = await AppStore.getAllInRange(startDate,endDate);
      
      
      // Create arrays for each plot
      let temperature = [];
      let humidity = [];
      let altitude = [];
      let soil = [];

      data.forEach(row => {
          temperature.push([parseFloat(row.temperature.toFixed(2)),parseFloat(row.heat_index.toFixed(2))])
          humidity.push([parseFloat(row.humidity.toFixed(2)),parseFloat(row.heat_index.toFixed(2))])
          altitude.push([parseFloat(row.altitude.toFixed(2)),parseFloat(row.pressure.toFixed(2))])
          soil.push([parseFloat(row.soil_moisture.toFixed(2)),parseFloat(row.humidity.toFixed(2))])
      });
      
      // Add data to Temperature and Heat Index chart
      scattertempHiChart.value.series[0].setData(temperature);
      scatterhumidHiChart.value.series[0].setData(humidity);
      scatteraltHiChart.value.series[0].setData(altitude);
      scattersoilHiChart.value.series[0].setData(soil);
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
  },3000); 
});


onBeforeUnmount(()=>{
  // THIS FUNCTION IS CALLED RIGHT BEFORE THIS COMPONENT IS UNMOUNTED
  // unsubscribe from all topics 
  Mqtt.unsubcribeAll(); 
});


</script>

<style scoped>
.pink-text {
  color: #E30B5C !important;
}
.highcharts-figure {
  margin: 0;
  padding: 0;
}
Figure {
border: 2px solid black;
}

h1,h2{
    font-family: 'Great Vibes', cursive;
    font-size: 3rem;
  }
</style>
