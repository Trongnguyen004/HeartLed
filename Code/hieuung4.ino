void rainbow() {
  static uint16_t j;
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = wheel((i + j) & 255);
    if (buttonPressed) return;
  }
  FastLED.show();
  delay(20);
  j += 1;
  if (j >= 256) j = 0;
}

void xenkecauvong() {
  for (int j = 0; j < 256; j++) {
    if (buttonPressed) return; 
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUM_LEDS; i = i + 3) {
        leds[i + q] = wheel((i + j) % 255); 
      }
      FastLED.show();
      delay(50);
      for (int i = 0; i < NUM_LEDS; i = i + 3) {
        leds[i + q] = CRGB::Black; 
      }
    }
  }
}

// Hàm chuyển đổi màu sắc
CRGB wheel(byte wheelPos) {
  wheelPos = 255 - wheelPos;
  if (wheelPos < 85) {
    return CRGB(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if (wheelPos < 170) {
    wheelPos -= 85;
    return CRGB(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return CRGB(wheelPos * 3, 255 - wheelPos * 3, 0);
}
