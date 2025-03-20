  <template>
         <VToolbar flat density="compact" color="surface" height="100" >
            <VContainer fluid>
                    <VRow align="center" justify="center">
                        <VCol cols="1" align="left" >
                             
                        </VCol>

                        <VCol cols="10"  align="center"   > 

                            <RouterLink class="route" :to="{ name: 'Home' }" >
                                <VBtn class="text-subtitle-2"   density="compact"  color="primary" :variant="(route.name == 'Home')? 'tonal':'text'">Home</VBtn>
                            </RouterLink>

                            <RouterLink class="route" :to="{ name: 'Dashboard' }" >
                                <VBtn class="text-subtitle-2"   density="compact"  color="primary" :variant="(route.name == 'Dashboard')? 'tonal':'text'">Dashboard</VBtn>
                            </RouterLink>

                            <RouterLink class="route" :to="{ name: 'Analysis' }" >
                                <VBtn class="text-subtitle-2"   density="compact"  color="primary" :variant="(route.name == 'Analysis')? 'tonal':'text'">Analysis</VBtn>
                            </RouterLink>

                            <RouterLink class="route" :to="{ name: 'Forecast' }" >
                                <VBtn class="text-subtitle-2"   density="compact"  color="primary" :variant="(route.name == 'Forecast')? 'tonal':'text'">Forecast</VBtn>
                            </RouterLink>

                            <RouterLink class="route" :to="{ name: 'Privacy Policy' }" >
                                <VBtn class="text-subtitle-2"   density="compact"  color="primary" :variant="(route.name == 'Privacy')? 'tonal':'text'">Privacy Policy</VBtn>
                            </RouterLink>

                            <RouterLink class="route" :to="{ name: 'Contact Us' }" >
                                <VBtn class="text-subtitle-2"   density="compact"  color="primary" :variant="(route.name == 'Contact')? 'tonal':'text'">Contact Us</VBtn>
                            </RouterLink>


                            

                            <!-- Add Links Below -->
                                                                         

                        </VCol>
                        <VCol cols="1" align="right">
                            <VBtn size="x-small" :elevation="0"  icon @click="darkmode = !darkmode">                  
                                <VIcon v-if="darkmode" icon="mdi:mdi-weather-night"   ></VIcon>
                                <VIcon v-else  icon="mdi:mdi-white-balance-sunny"  ></VIcon>
                            </VBtn>
                        </VCol>
                    </VRow>
                </VContainer>
            </VToolbar>
  </template>

  
  <script setup>
    import { useRoute,useRouter } from "vue-router";
    import { useTheme } from 'vuetify';  
    import { ref ,watch ,onMounted ,onBeforeMount } from 'vue';


  
    // VARIABLES 
    const theme       = useTheme();
    const darkmode    = ref(false); 
    const router      = useRouter();  
    const route       = useRoute();  

    // WATCHERS
    watch(darkmode,  (mode) => {
    theme.global.name.value = mode ?  'darkMode' : 'lightMode';
    localStorage.setItem("theme",mode ? 'darkMode' : 'lightMode');  
    });


    // FUNCTIONS
    onMounted(()=>{
 

    });

    onBeforeMount(()=>{
        // SAVE THEME TO LOCALSTORAGE MAKING IT PERSIST BROWSER REFRESH

        if(localStorage.getItem("theme") != null){
            theme.global.name.value = localStorage.getItem("theme");
            darkmode.value = theme.global.current.value.dark;
        }
        else{
            localStorage.setItem("theme",theme.global.current.value.dark ? 'darkMode' : 'lightMode');
            darkmode.value = theme.global.current.value.dark;    
        }  
    });

 
  </script>

  <style>
    .route {
        text-decoration: none;
        margin-left: 8px;
        margin-right: 8px; 
    }
  </style>
  