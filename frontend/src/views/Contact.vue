<template>
  <v-container>
    <v-row justify="center">
      <v-col cols="12" md="6">
        <v-card class="pa-4">
          <v-card-title class="text-h5">Contact Us</v-card-title>
          <v-card-text>
            <v-form @submit.prevent="submitForm">
              <v-text-field v-model="name" label="Name" required></v-text-field>
              <v-text-field v-model="email" label="Email" type="email" required></v-text-field>
              <v-textarea v-model="comment" label="Comment" required></v-textarea>
              <v-btn type="submit" color="primary" block>Submit</v-btn>
            </v-form>
          </v-card-text>
        </v-card>
      </v-col>
    </v-row>
  </v-container>
</template>

<script>
export default {
  data() {
    return {
      name: '',
      email: '',
      comment: '',
    };
  },
  methods: {
    submitForm() {
      console.log('Form submitted:', { name: this.name, email: this.email, comment: this.comment });
      alert('Your message has been sent!');
      this.name = '';
      this.email = '';
      this.comment = '';
    },
  },
};
</script>
