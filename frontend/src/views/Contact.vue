<template>
  <v-container>
    <!-- Header Section -->
    <v-row justify="center">
      <v-col cols="12" md="12" class="text-center">
        <h3>We’d love to hear from you! Have a question, feedback, or just want to say hi? Let’s chat! 😊</h3>
        <img src="@/assets/photo.jpg" alt="Founder" width="35%" class="rounded-circle mt-3">
        <p class="text-subtitle-1 font-weight-medium mt-2">✨ Founder & CEO ✨</p>
      </v-col>
    </v-row>

    <!-- Contact Form Section -->
    <v-row justify="center">
      <v-col cols="12" md="6">
        <v-card class="pa-4">
          <v-card-title class="text-h5">Get in Touch</v-card-title>
          <v-card-text>
            <v-form @submit.prevent="submitForm">
              <v-text-field v-model="name" label="Your Name" required prepend-icon="mdi-account"></v-text-field>
              <v-text-field v-model="email" label="Your Email" type="email" required prepend-icon="mdi-email"></v-text-field>

              <!-- How Can We Help Dropdown -->
              <v-select 
                v-model="helpTopic"
                :items="['General Inquiry', 'Feedback', 'Support Request', 'Collaboration']"
                label="How Can We Help?" 
                required
                prepend-icon="mdi-help-circle"
              ></v-select>

              <v-textarea v-model="comment" label="Your Message" required prepend-icon="mdi-message"></v-textarea>

              <v-btn type="submit" color="pink" block class="mt-2" elevation="2">
                Send Message ✨
              </v-btn>
            </v-form>
          </v-card-text>
        </v-card>
      </v-col>
    </v-row>

    <!-- Social Media Links -->
    <v-row justify="center" class="mt-6">
      <v-col cols="12" md="6" class="text-center">
        <p class="text-subtitle-1 font-weight-bold">Or find us on:</p>
        <v-btn icon class="mx-2" href="https://instagram.com" target="_blank">
          <v-icon color="pink">mdi-instagram</v-icon>
        </v-btn>
        <v-btn icon class="mx-2" href="https://twitter.com" target="_blank">
          <v-icon color="blue">mdi-twitter</v-icon>
        </v-btn>
        <v-btn icon class="mx-2" href="https://facebook.com" target="_blank">
          <v-icon color="blue-darken-2">mdi-facebook</v-icon>
        </v-btn>
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
      name: '',
      email: '',
      helpTopic: '',
      comment: '',
    };
  },
  methods: {
    submitForm() {
      console.log('Form submitted:', { 
        name: this.name, 
        email: this.email, 
        helpTopic: this.helpTopic,
        comment: this.comment 
      });
      alert('Your message has been sent! 🎉');
      this.name = '';
      this.email = '';
      this.helpTopic = '';
      this.comment = '';
    },
  },
};
</script>

<style>
@import url('https://fonts.googleapis.com/css2?family=Bodoni+Moda&display=swap');
h3 {
  font-family: 'Bodoni Moda', serif;
  font-size: 1.5rem;
}

.rounded-circle {
  border-radius: 50%;
}
</style>
