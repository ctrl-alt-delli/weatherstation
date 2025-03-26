<template>
    <v-container>
      <v-row>
        <v-col>
          <h3 class="text-center font-weight-bold">Privacy Policy for Your Weather Station</h3>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <h4 class="text-center">Effective Date: Wednesday, March 19, 2025</h4>
        </v-col>
      </v-row>
  
      <v-row>
        <v-col>
          <p class="font-weight-bold">1. Introduction</p>
          <p>
            Welcome to Your Weather Station. Your privacy is important to us. This Privacy Policy explains how we collect, 
            use, disclose, and protect your information when you use our weather station website, hardware components, or related services.
            By accessing or using our Services, you agree to the terms of this Privacy Policy. If you do not agree, please do not use our Services.
          </p>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <p class="font-weight-bold">2. Information We Collect</p>
          <ul style="list-style: none; padding: 0; margin: 0;">
            <li><strong>Weather Data:</strong> Temperature, humidity, air pressure, soil moisture, and other environmental data collected by our weather station sensors.</li>
            <li><strong>Personal Information (if applicable):</strong> Name, email address, and other details provided when signing up for notifications or using interactive features.</li>
            <li><strong>Non-Personal Information:</strong> IP address, browser type, and usage data collected automatically when you visit our website.</li>
          </ul>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <p class="font-weight-bold">3. How We Use Your Information</p>
          <ul style="list-style: none; padding: 0; margin: 0;">
            <li>Provide real-time weather data and historical trends.</li>
            <li>Improve and personalize our weather station Services.</li>
            <li>Communicate updates, alerts, or important weather-related notifications (if subscribed).</li>
            <li>Maintain and secure our website.</li>
            <li>Comply with legal and regulatory requirements.</li>
          </ul>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <p class="font-weight-bold">4. How We Share Your Information</p>
          <ul style="list-style: none; padding: 0; margin: 0;">
            <li><strong>Service Providers:</strong> Third-party tools used for data analytics and website performance.</li>
            <li><strong>Legal Compliance:</strong> Authorities if required by law or to protect our rights.</li>
            <li><strong>Research and Public Use:</strong> Aggregated, anonymized weather data may be shared for scientific or educational purposes.</li>
          </ul>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <p class="font-weight-bold">5. Data Security</p>
          <p>We implement security measures to protect your information. However, no method of data transmission is completely secure. We encourage users to take precautions when sharing personal data online.</p>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <p class="font-weight-bold">6. Your Rights and Choices</p>
          <ul style="list-style: none; padding: 0; margin: 0;">
            <li>Accessing or updating your personal information.</li>
            <li>Opting out of email notifications (if applicable).</li>
            <li>Requesting data deletion or restriction.</li>
          </ul>
          <p>To exercise these rights, <a href="/contact" style="color: #E30B5C; text-decoration: none;">contact us</a>.</p>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <p class="font-weight-bold">7. Third-Party Links</p>
          <p>Our website may contain links to third-party services or external weather APIs. We are not responsible for their privacy practices. Please review their privacy policies separately.</p>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <p class="font-weight-bold">8. Changes to This Privacy Policy</p>
          <p>We may update this Privacy Policy from time to time. The updated version will be indicated by an "Effective Date" at the top. Continued use of our Services after changes means acceptance of the revised policy.</p>
        </v-col>
      </v-row>
      
      <v-row>
        <v-col>
          <p class="font-weight-bold">9. Contact Us</p>
          <p>If you have any questions about this Privacy Policy, please <a href="/contact" style="color: #E30B5C; text-decoration: none;">contact us</a>.</p>
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
 
 
// VARIABLES
const router        = useRouter();
const route         = useRoute();  
const Mqtt          = useMqttStore(); 
const { payload, payloadTopic } = storeToRefs(Mqtt); 
const led           = reactive({"brightness":255,"leds":1,"color":{ r: 255, g: 0, b: 255, a: 1 }}); 
let  timer, ID      = 1000; 

// WATCHERS  
watch(led,(controls)=>{ 
    clearTimeout(ID); 
    
    ID = setTimeout(()=>{   
        const message = JSON.stringify({"type":"controls","brightness":controls.brightness,"leds":controls.leds,"color": controls.color}); 
        Mqtt.publish("620157584_sub",message);  // Publish to a topic subscribed to by the hardware   
    },1000)     
}) 


// FUNCTIONS
onMounted(()=>{
    // THIS FUNCTION IS CALLED AFTER THIS COMPONENT HAS BEEN MOUNTED
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
/** CSS STYLE HERE */
@import url('https://fonts.googleapis.com/css2?family=Great+Vibes&display=swap');

h3{
    font-family: 'Great Vibes', cursive;
    font-size: 3rem;
}

</style>