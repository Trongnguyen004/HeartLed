void duoixenke() {
  for (int j = 0; j < 10; j++) {  
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUM_LEDS; i = i + 3) {
        leds[i + q] = CRGB:: Blue;
        if (buttonPressed) return;
      }
      FastLED.show();
      delay(40);
      for (int i = 0; i < NUM_LEDS; i = i + 3) {
        leds[i + q] = CRGB::Black;
        if (buttonPressed) return;
      }
    }
    if (buttonPressed) return;
  }
}

void xenkedoimau() {
  int numColors = sizeof(colors) / sizeof(colors[0]); 
  for (int colorIndex = 0; colorIndex < numColors; colorIndex++) {
    CRGB currentColor = colors[colorIndex];    
    for (int j = 0; j < 10; j++) {  
      for (int q = 0; q < 3; q++) {
        for (int i = 0; i < NUM_LEDS; i = i + 3) {
          leds[i + q ] = currentColor;
          if (buttonPressed) return;
        }
        FastLED.show();
        delay(40);
        for (int i = 0; i < NUM_LEDS; i = i + 3) {
          leds[i + q] = CRGB::Black;
          if (buttonPressed) return;
        }
      }
      if (buttonPressed) return;
    }
    if (buttonPressed) return;
  }
}
void duoi() {
  int numColors = sizeof(colors) / sizeof(colors[0]);
  for (int colorIndex = 0; colorIndex < numColors; colorIndex++) {    if (buttonPressed) return;  
    CRGB currentColor = colors[colorIndex]; 
    
    for(int i = 0; i <= NUM_LEDS + 8; i++) {     
      for(int j = 0; j < 8; j++) {               
        if(i - j >= 0 && i - j < NUM_LEDS) {     
          leds[i - j] = currentColor;
        }
        if(j > 0 && i - j - 1 >= 0 && i - j - 1 <= NUM_LEDS) {    if (buttonPressed) return;
          leds[i - j - 1] = CRGB::Black;
        }
      }
      FastLED.show();
      delay(50);
    }
  delay(1);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
}
