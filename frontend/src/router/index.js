// Composables
import { createRouter, createWebHistory } from 'vue-router'

const routes = [
  { path: '/', name: 'Home', component: () => import('@/views/Home.vue'), meta:{ transition: 'fade'} },
  { path: '/dashboard', name: 'Dashboard', component: () => import('@/views/Dashboard.vue'), meta:{ transition: 'fade'} },
  { path: '/analysis', name: 'Analysis', component: () => import('@/views/Analysis.vue'), meta:{ transition: 'fade'} },
  { path: '/forecast', name: 'Forecast', component: () => import('@/views/Forecast.vue'), meta:{ transition: 'fade'} },
  { path: '/privacy', name: 'Privacy Policy', component: () => import('@/views/Privacy.vue'), meta:{ transition: 'fade'} },
  { path: '/contact', name: 'Contact Us', component: () => import('@/views/Contact.vue'), meta:{ transition: 'fade'} }
  // ADD NEW ROUTES HERE
  
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes,
})

export default router
