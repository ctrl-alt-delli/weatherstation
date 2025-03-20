<template>
  <v-container fluid>
    <v-row no-gutters gap="4">
      <!-- Left Panel (30%) -->
      <v-col cols="3" class="left-panel">
        <img 
          src="https://cdn2.iconfinder.com/data/icons/weather-flat-14/64/weather02-512.png" 
          class="image"
          alt="Weather Icon"
        />
        <div class="date-time">
          {{ formattedDate }}
        </div>
        <h4>Kingston, Jamaica</h4>
      </v-col>

      <v-col cols="1">
      </v-col>

      <!-- Right Panel (70%) -->
      <v-col cols="8" class="hero-section">
  <v-row>
    <!-- Temperature Card -->
  <v-col cols="12" md="4" class="mb-4">
    <v-card>
      <v-card-title class="d-flex justify-center align-center">
        Temperature
      </v-card-title>
      <v-card-text class="d-flex justify-center align-center">
        <h3>{{ temperature }}</h3>
      </v-card-text>
      <v-card-actions class="d-flex justify-center">
        <v-btn color="primary" @click="toggleTemperatureUnit">
          Change Unit
        </v-btn>
      </v-card-actions>
    </v-card>
  </v-col>


    <!-- Card 2: Live Data Button -->
    <v-col cols="12" md="4" class="mb-4">
  <v-card>
    <v-card-title class="d-flex justify-center align-center">Humidity</v-card-title>
    <v-card-text class="d-flex justify-center align-center">
      <h3>{{ humidity }}</h3>
    </v-card-text>
    <v-card-actions class="d-flex justify-center">
        <v-btn color="primary" @click="toggleHumidityUnit">
          Change Unit
        </v-btn>
      </v-card-actions>
  </v-card>
</v-col>

<!-- Card 3: Live Data Button -->
<v-col cols="12" md="4" class="mb-4">
  <v-card>
    <v-card-title class="d-flex justify-center align-center">Heat Index</v-card-title>
    <v-card-text class="d-flex justify-center align-center">
      <h3>{{ heat_index }}</h3>
    </v-card-text>
    <v-card-actions class="d-flex justify-center">
        <v-btn color="primary" @click="toggleTemperatureUnit">
          Change Unit
        </v-btn>
      </v-card-actions>
  </v-card>
</v-col>
  </v-row>

  <v-row>
    <!-- Card 4: Live Data Button -->
    <v-col cols="12" md="4" class="mb-4">
  <v-card>
    <v-card-title class="d-flex justify-center align-center">Altitude</v-card-title>
    <v-card-text class="d-flex justify-center align-center">
      <h3>{{ altitude }}</h3>
    </v-card-text>
    <v-card-actions class="d-flex justify-center">
        <v-btn color="primary" @click="toggleAltitudeUnit">
          Change Unit
        </v-btn>
      </v-card-actions>
  </v-card>
</v-col>
  
    <!-- Card 5: Live Data Button -->
    <v-col cols="12" md="4" class="mb-4">
  <v-card>
    <v-card-title class="d-flex justify-center align-center">Air Pressure</v-card-title>
    <v-card-text class="d-flex justify-center align-center">
      <h3>{{ pressure }}</h3>
    </v-card-text>
    <v-card-actions class="d-flex justify-center">
        <v-btn color="primary" @click="togglePressureUnit">
          Change Unit
        </v-btn>
      </v-card-actions>
  </v-card>
</v-col>

    <!-- Card 6: Weather Prediction Button -->
    <v-col cols="12" md="4" class="mb-4">
  <v-card>
    <v-card-title class="d-flex justify-center align-center">Soil Moisture</v-card-title>
    <v-card-text class="d-flex justify-center align-center">
      <h3>{{ soil_moisture }}</h3>
    </v-card-text>
  </v-card>
</v-col>
  </v-row>
</v-col>

    </v-row>
  </v-container>
  
  <v-container>
    <v-row>
      <v-col cols="12" md="8" class="mx-auto">
        <h2 class="text-center">About the Weather Station</h2>
        <p class="text-center">
          Track the weather in your area with real-time data on temperature, humidity, air pressure, and more.
          Our station offers accurate, up-to-date information to help you plan your day.
        </p>
      </v-col>
    </v-row>
  </v-container>

  <v-container>
    <v-row>
      <v-col cols="12" md="4">
        <v-card>
          <v-card-title>Live Data</v-card-title>
          <v-card-subtitle>View real-time weather data.</v-card-subtitle>
          <v-card-actions>
            <v-btn color="primary" href="/dashboard">See Live Data</v-btn>
          </v-card-actions>
        </v-card>
      </v-col>
      <v-col cols="12" md="4">
        <v-card>
          <v-card-title>Weather Analysis</v-card-title>
          <v-card-subtitle>View a detailed analysis of weather data over a specified range of time.</v-card-subtitle>
          <v-card-actions>
            <v-btn color="primary" href="/analysis">See Analysis</v-btn>
          </v-card-actions>
        </v-card>
      </v-col>
        <v-col cols="12" md="4">
        <v-card>
          <v-card-title>Weather Predictions</v-card-title>
          <v-card-subtitle>Get accurate forecasts for the coming days.</v-card-subtitle>
          <v-card-actions>
            <v-btn color="primary" href="/forecast">See Forecasts</v-btn>
          </v-card-actions>
        </v-card>
        </v-col>
    </v-row>
  </v-container>

  <v-container>
    <v-row>
      <v-col cols="12">
        <h2 class="text-center">Interactive Weather Map</h2>
        <div id="weather-map" style="height: 400px;"></div>
      </v-col>
    </v-row>
  </v-container>

  <v-footer>
    <v-row class="d-flex justify-center">
      <v-col class="text-center">
        <v-btn href="/privacy">Privacy Policy</v-btn>
        <v-btn href="/contact">Contact</v-btn>
      </v-col>
    </v-row>
    <v-row class="d-flex justify-center">
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
    </v-row>
    <v-row class="d-flex justify-center">
      <v-col class="text-center">
        <p>© 2025 Your Weather Station</p>
      </v-col>
    </v-row>
  </v-footer>
</template>

<script setup>
import { ref,reactive,watch ,onMounted, onBeforeUnmount,computed } from "vue";  
import { useRoute ,useRouter } from "vue-router";
import { useMqttStore } from '@/store/mqttStore'; // Import Mqtt Store 
import { storeToRefs } from "pinia"; 
import { useAppStore } from "@/store/appStore";
import L from 'leaflet';
import 'leaflet/dist/leaflet.css';

// VARIABLES
const router      = useRouter();
const route       = useRoute();  
const Mqtt          = useMqttStore(); 
const AppStore = useAppStore();
const { payload, payloadTopic } = storeToRefs(Mqtt); 

// Reactive state
const latitude = ref(18.0050293); // Replace with your weather station latitude
const longitude = ref(-76.7496350); // Replace with your weather station longitude
const formattedDate = ref('');
const isCelsius = ref(true);
const isHpa = ref(true);
const isHumid = ref(true);
const isPercent = ref(true);
const isMeter = ref(true);

// Computed properties
const temperature = computed(() => {
  if (payload.value) {
    return isCelsius.value
    ?`${payload.value.temperature.toFixed(2)} °C`
    : `${((payload.value.temperature * 9) / 5 + 32).toFixed(2)} °F`;
  }
  return 'Loading...';
});

const humidity = computed(() => {
  if (payload.value) {
    return isHumid.value
    ?`${payload.value.humidity.toFixed(2)} %`
    : `${((6.112 * Math.exp((17.67 * payload.value.temperature)/(payload.value.temperature+243.5)) * payload.value.humidity * 18.02)/((273.15 + payload.value.temperature) * 100 * 0.08314)).toFixed(2)} g/m³`;
    console.log(((6.112 * Math.exp((17.67 * payload.value.temperature)/(payload.value.temperature+243.5)) * payload.value.humidity * 18.02)/((273.15 + payload.value.temperature) * 100 * 0.08314)).toFixed(2));
  }
  return 'Loading...';
});

const heat_index = computed(() => {
  if (payload.value) {
    return isCelsius.value
    ?`${payload.value.heat_index.toFixed(2)} °C`
    : `${((payload.value.heat_index * 9) / 5 + 32).toFixed(2)} °F`;
  }
  return 'Loading...';
});

const soil_moisture = computed(() => {
  if (payload.value) {
    return `${payload.value.soil_moisture.toFixed(2)} %`;
  }
  return 'Loading...';
});

const altitude = computed(() => {
  if (payload.value) {
    return isMeter.value
    ?`${payload.value.altitude.toFixed(2)} m`
    : `${((payload.value.altitude * 3.28084)).toFixed(2)} ft`;
  }
  return 'Loading...';
});

const pressure = computed(() => {
  if (payload.value) {
    return isHpa.value
    ?`${payload.value.pressure.toFixed(1)} hPa`
    : `${((payload.value.pressure * 0.0145038)).toFixed(2)} psi`;
  }
  return 'Loading...';
});

const toggleTemperatureUnit = () => {
  isCelsius.value = !isCelsius.value;
};

const toggleHumidityUnit = () => {
  isHumid.value = !isHumid.value;
};

const toggleAltitudeUnit = () => {
  isMeter.value = !isMeter.value;
};

const togglePressureUnit = () => {
  isHpa.value = !isHpa.value;
};



// Initialize the map
const initializeMap = () => {
  const map = L.map('weather-map').setView([latitude.value, longitude.value], 10);
  L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png').addTo(map);
  L.marker([latitude.value, longitude.value])
    .addTo(map)
    .bindPopup(temperature.value)
    .openPopup();
};

// Update the date
const updateDate = () => {
  const now = new Date();
  formattedDate.value = new Intl.DateTimeFormat('en-US', {
    weekday: 'long',
    month: 'long',
    day: 'numeric',
    year: 'numeric',
  }).format(now);
};

// Lifecycle hooks
onMounted(() => {

  // Connect to MQTT broker
  Mqtt.connect();
  setTimeout(() => {
    Mqtt.subscribe('620157584');
    console.log('Subscribed to topic 620157584');
  }, 3000);

  initializeMap();
  updateDate();
  setInterval(updateDate, 60000); // Update date every minute
});

  onBeforeUnmount(()=>{
  // THIS FUNCTION IS CALLED RIGHT BEFORE THIS COMPONENT IS UNMOUNTED
  // unsubscribe from all topics 
  Mqtt.unsubcribeAll(); 
  });
</script>

<style scoped>
@import url('https://fonts.googleapis.com/css2?family=Great+Vibes&display=swap');
@import url('https://fonts.googleapis.com/css2?family=Bodoni+Moda&display=swap');

.hero-section {
  background-color: #f0f0f0;
  height: 50vh;
}

#weather-map {
  width: 100%;
}

.v-footer {
  background-color: #f0f0f0;
  padding: 20px;
}

.left-panel {
  background-color: #f0f0f0;
  height: 50vh;
  display: flex;
  flex-direction: column;
  align-items: center;
  padding-top: 20px; /* Moves image to the top */
}

.image {
  max-width: 100%;
  max-height: 250px; /* Ensure image is displayed properly */
}

.date-time {
  margin-top: 10px;
  font-size: 1.2em;
  font-weight: bold;
  color: #333;
  text-align: center;
}

  h1,h2{
    font-family: 'Great Vibes', cursive;
    font-size: 3rem;
  }

  h3{
    font-family: 'Bodoni Moda', serif;
    font-size: 3rem;
  }

  h4{
    font-family: 'Bodoni Moda', serif;
    font-size: 2rem;
  }
</style>
