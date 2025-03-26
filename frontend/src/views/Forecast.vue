<template>
  <v-container class="bg-surface">
    <v-row class="full-page-container">
      <v-col cols="12" md="6" class="d-flex justify-center align-center">
        <div class="weather-forecast">
          <h2>7-Day Weather Forecast</h2>
          <div v-if="forecast.length > 0">
            <div v-for="(day, index) in forecast" :key="index" class="forecast-day">
              <div class="icon">
                <img :src="getWeatherIcon(day.weather)" alt="Weather Icon" />
              </div>
              <div class="temperature-bar">
                <p><strong>{{ getDayName(index) }}:</strong></p>
                <div class="temperature-range">
                  <div class="min-temp" :style="{ left: `${day.temperature_2m_min}%` }">
                    {{ day.temperature_2m_min }}°C
                  </div>
                  <div class="max-temp" :style="{ left: `${day.temperature_2m_max}%` }">
                    {{ day.temperature_2m_max }}°C
                  </div>
                </div>
              </div>
            </div>
          </div>
          <div v-else>
            <p>Loading forecast...</p>
          </div>
        </div>
      </v-col>
    </v-row>
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
  
  <script>
  export default {
    data() {
      return {
        forecast: [], 
      };
    },
    mounted() {
      this.fetchWeatherForecast();
    },
    methods: {
      fetchWeatherForecast() {
        const url = 'https://api.open-meteo.com/v1/forecast';
        const params = {
          latitude: 18.0050293,  
          longitude: -76.749635, 
          daily: ['temperature_2m_min', 'temperature_2m_max', 'weathercode'],
          timezone: 'auto',
        };
  
        const queryString = new URLSearchParams(params).toString();
        const fullUrl = `${url}?${queryString}`;
  
        fetch(fullUrl)
          .then(response => response.json())
          .then(data => {
            const daily = data.daily;
            this.forecast = daily.temperature_2m_min.map((minTemp, index) => ({
              temperature_2m_min: minTemp,
              temperature_2m_max: daily.temperature_2m_max[index],
              weather: daily.weathercode[index], 
            }));
          })
          .catch(error => {
            console.error('Error fetching weather data:', error);
            alert('Failed to fetch weather data.');
          });
      },
      
      getWeatherIcon(weatherCode) {
        switch (weatherCode) {
          case 1:
          case 2:
          case 3:
            return '/icons/cloudy.png'; 
          case 5:
          case 6:
          case 7:
            return '/icons/rain.png'; 
          default:
            return '/icons/sunny.png'; 
        }
      },
  
      getDayName(index) {
        const weekdays = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
        const today = new Date();
        const dayOfWeek = today.getDay(); 
        const forecastDayIndex = (dayOfWeek + index + 1) % 7; 
        return weekdays[forecastDayIndex];
      }
    },
  };
  </script>
  
  <style scoped>
  @import url('https://fonts.googleapis.com/css2?family=Great+Vibes&display=swap');
  
  .full-page-container {
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh; 
    background-color: rgba(0, 0, 0, 0.5); 
  }
  
  .weather-forecast {
    font-family: Arial, sans-serif;
    margin: 20px;
    text-align: center;
    background-color: rgba(255, 255, 255, 0.7);
    padding: 20px;
    box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2); 
    backdrop-filter: blur(10px); 
  }
  
  h2 {
    font-family: 'Great Vibes', cursive;
    font-size: 3rem;
  }
  
  .forecast-day {
    display: flex;
    align-items: center;
    justify-content: center; 
    margin-bottom: 15px;
  }
  
  .icon img {
    width: 80px;  
    height: 80px; 
    margin-right: 20px;
  }
  
  .temperature-bar {
    flex-grow: 0.7;
    display: flex;
    justify-content: center; 
  }
  
  .temperature-range {
  position: relative;
  width: 100%;
  height: 15px;  
  background-color: #ddd;
  border-radius: 10px;
  margin-top: 5px;
}

.min-temp, .max-temp {
  position: absolute;
  top: -25px; 
  font-weight: bold;
  font-size: 1rem;
}

.min-temp {
  left: 0;  
  transform: translateX(-50%);
}

.max-temp {
  right: 0;  
  transform: translateX(35%); 
}


  
  .temperature-range::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    height: 100%;
    width: 100%;
    background-color: rgba(0, 0, 255, 0.1);
    border-radius: 10px;
  }
  </style>
  