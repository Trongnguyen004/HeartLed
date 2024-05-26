///////////////////////////////////////////////////////////////////////////////////////////////////////////
void xoaytron_doimau(){
    for(int i = 0; i < NUM_LEDS / 2; i++) {   
      fadeToBlackBy(leds, NUM_LEDS, dogiamsang);
      leds[i] = CHSV(hue++, 255,255 ); 
      for (int j = NUM_LEDS / 2; j < NUM_LEDS; j++) {
        leds[j] = leds[j - NUM_LEDS / 2];
      }
    if (buttonPressed) return;
    FastLED.show();
    delay(50);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void lenxuong_doimau(){ 
    for(int i = 0; i < NUM_LEDS/2; i++) {   
      fadeToBlackBy(leds, NUM_LEDS, dogiamsang);
      leds[i] = CHSV(hue++,255, 255);
      leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
      FastLED.delay(40);
      if (buttonPressed) return;
    }
    for(int i = NUM_LEDS/2; i >= 0; i--) {   
      fadeToBlackBy(leds, NUM_LEDS, dogiamsang );
      leds[i] = CHSV(hue++,255,255);
      leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
      FastLED.delay(40);
      if (buttonPressed) return;
    }  
}
void sangdon() { 
  int numColors = sizeof(colors) / sizeof(colors[0]);  
  for (int colorIndex = 0; colorIndex < numColors; colorIndex++) {      
    if (buttonPressed) return;
    int x = NUM_LEDS;
    CRGB currentColor = colors[colorIndex];
    
    for (int j = NUM_LEDS-1; j >=0 ; j--) {     
      for(int i = 0; i < x; i++) {               if (buttonPressed) return;
        leds[i] = currentColor; 
        FastLED.show();
        delay(25); 
        leds[i] = CRGB::Black; 
        FastLED.show();
      }
      leds[j] = currentColor;
      FastLED.show();
      delay(1);
      x--;
    }   
  }
}
