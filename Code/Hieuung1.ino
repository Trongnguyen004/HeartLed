///////////////////////////////////////////////////////////////////////////////////////////////////////////
void RedToBlue_effect(){
      for (int x = 0; x < NUM_LEDS ;x++){
        if (buttonPressed) return;
        leds[x] = CRGB::Blue;
        fadeToBlackBy(leds, NUM_LEDS, 10);
        FastLED.show();
        delay(50);
      }
      for (int x = NUM_LEDS ;x>=0 ;x--){
        if (buttonPressed) return;
        leds[x] = CRGB::Red;
        fadeToBlackBy(leds, NUM_LEDS, 10);
        FastLED.show();
        delay(50);  
      }    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////

void sangtat(){
  int numColors = sizeof(colors) / sizeof(colors[0]);  
  for (int colorIndex = 0; colorIndex < numColors; colorIndex++) {
    
    CRGB currentColor = colors[colorIndex];  
    for (int brightness = 0; brightness <= BRIGHTNESS; brightness++) {
      fill_solid(leds, NUM_LEDS, currentColor);
      FastLED.setBrightness(brightness);
      FastLED.show();
      FastLED.delay(70);
      if (buttonPressed) return;
    }  
    for (int brightness = BRIGHTNESS; brightness >= 0; brightness--) {
      fill_solid(leds, NUM_LEDS, currentColor);
      FastLED.setBrightness(brightness);
      FastLED.show();
      FastLED.delay(70);
      if (buttonPressed) return;
    }
    if (buttonPressed) return;
  }
  FastLED.setBrightness(BRIGHTNESS);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void cauvong() {
  for(int i = 0; i < NUM_LEDS; i++) {      
    if (buttonPressed) return;
    leds[i] = CHSV((hue - (i * 256 / NUM_LEDS)) % 256, 255, 255);
  }
  hue++;
  FastLED.show();
  delay(5); 
}
