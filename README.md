# Weather Station - Internet of Things (IoT) Template

## Description

### **Hardware Component**
The hardware component of this weather station is built using an **ESP32**, responsible for collecting real-time weather data from various sensors. The system does **not** use a potentiometer. The **TFT display** is used for visualizing data and has:
1. A **Live Sensor Page** that continuously updates with real-time data.
2. Separate pages dedicated to displaying **each pair of sensor readings**:
   - Temperature & Humidity
   - Soil Moisture
   - Altitude & Air Pressure

### **Backend Component**
The backend is designed to:
1. **Store weather data** sent via **HTTP POST requests** from the ESP32 into a database, adhering to a structured schema.
2. **Facilitate data access** for both hardware and frontend components by implementing API routes on the frontend and allowing the ESP32 to fetch historical data via **HTTP GET requests**.

### **Frontend Component**
The frontend, built with **Vue.js** and styled with **Vuetify**, provides an interactive user interface for monitoring and analyzing weather data. The website includes the following pages:
1. **Home** – A dynamic and engaging introduction.
2. **Live** – Displays real-time weather data.
3. **Analysis** – Shows trends, graphs, and insights.
4. **Forecast** – Provides weather predictions.
5. **Privacy Policy** – Outlines how data is handled.
6. **Contact** – Allows users to reach out.

### **Key Features**
- **Real-time monitoring** with live sensor updates.
- **Historical data analysis** to track trends over time.
- **Weather predictions** based on collected data.
- **User-friendly UI** for easy interaction and visualization.

This weather station serves as a **fully integrated IoT system**, leveraging cloud storage, interactive dashboards, and **real-time sensor monitoring** for enhanced weather tracking and analysis.

# Hardware Setup
Download and install [Arduino](https://www.arduino.cc/en/software) IDE. Subsequently, install the following Arduino IDE libraries following the tutorial [here](https://support.arduino.cc/hc/en-us/articles/5145457742236-Add-libraries-to-Arduino-IDE):
1. Adafruit GFX Library by Adafruit
2. Adafruit BMP280 Library by Adafruit
3. Adafruit Unified Sensor by Adafruit
4. Adafruit ILI9341 by Adafruit
5. ArduinoJson by Benoît Blanchon
6. PubSubClient by Nick O’Leary
7. DHT sensor library by DHT.h
8. esp32 by Espressif Systems, from the Board Manager tab in the Arduino IDE



# Backend Setup
Always ensure to establish a virtual environment and install the necessary packages from your requirements file if you haven't already done so. Following that, activate your virtual environment and proceed to run your Flask API.

**The commands below must be executed from a command line terminal in the homeautomation/backend/ folder**
### Create a virtual environment

Windows 
```sh
python -m venv env  
```
Linux
```sh
python3 -m venv env  
```
### Activate virtual environment
Windows
```sh
.\env\Scripts\activate 
```
Linux
```sh
source env/bin/activate
```
### Install API requirements in the virtual environment
```sh
pip install -r requirements.txt 
```
### Create **.env** file
Create a **.env** file in the backend/ folder to store the application's environment variables. 
Refer to the lab manual for the specific information that must be added to this file. Subsequently, modify the **FLASK_RUN_HOST** variable found in this file from localhost to the IP address of the computer your backend is running on.

### Start Flask API
Windows
```sh
py run.py 
```
Linux
```sh
python3 run.py
```
# Frontend Setup ( [Vue js](https://vuejs.org/), [Vuetify](https://vuetifyjs.com/en/components/all/), [Vite](https://vitejs.dev/))
### Recommended IDE Setup
[VSCode](https://code.visualstudio.com/) + [Volar](https://marketplace.visualstudio.com/items?itemName=johnsoncodehk.volar) (and disable Vetur) + [TypeScript Vue Plugin (Volar)](https://marketplace.visualstudio.com/items?itemName=johnsoncodehk.vscode-typescript-vue-plugin).

Customize configuration
See [Vite Configuration Reference](https://vitejs.dev/config/).


### In a command line terminal, execute the first commands in the homeautomation/frontend/ folder to initiate the dev server for the initial setup. 
### For all subsequent instances, only run the second command to start the dev server.
### Once development is complete, run the final command to generate production files. Please be aware that the generation of production files is not part of this course.

Project Setup
```sh
npm install
```

Run dev server (Compile and Hot-Reload for Development)
```sh
npm run dev
```

Create a production bundle (Compile and Minify for Production)
```sh
npm run build
```
### Modify **vite.config.js** file
Modify the target in the proxy object found in the **frontend/vite.config.js** file shown in the code block below. Change localhost in the string to the IP address of the computer your backend is running on.
```js
proxy: {
      '^/api*': { 
        target: 'http://localhost:8080/' ,
       changeOrigin: false,
    },   
  }

```
