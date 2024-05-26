//----------------------------------------        HeardLed             -------------------------------------------------------
//--------------------------------------      Nguyễn Đức Trọng CKC      ------------------------------------------------------
//---------------------------------          //|         //////||           --------------------------------------------------
//---------------------------------         //||               ||           --------------------------------------------------
//---------------------------------        // ||         //////||           --------------------------------------------------
//---------------------------------           ||               ||           --------------------------------------------------
//---------------------------------           ||         //////||           --------------------------------------------------
//----------------          Code chuyển hiệu ứng bằng nút nhấn, mỗi hiệu ứng chạy 60s thì tắt     ----------------------------
#include <FastLED.h>
#include <LowPower.h>

#define NUM_LEDS  24
#define LED_PIN   6
#define BUT   5

#define BRIGHTNESS  20
#define dogiamsang  15
#define BUTTON_PIN 2
#define Time  30000

//CRGB leds[NUM_LEDS];
CRGBArray<NUM_LEDS> leds;
CRGB colors[] = { CRGB::Red, CRGB::Blue, CRGB::Green, CRGB::Magenta, CRGB::Cyan };

static uint8_t hue = 0;

unsigned long endTime ;
unsigned long thoigian;

volatile int currentEffect = 0;
volatile bool buttonPressed = false;

void setup(){
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUT, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), changeEffect, RISING);
  tathieuung();
}

void loop() {
   if(thoigian < endTime){
     thoigian = millis();
     effect();    
   }else {
     tathieuung();
  }
}

void changeEffect() {
  if(digitalRead(BUT)){
    delay(170);
    currentEffect++;
    thoigian = millis();
    endTime = thoigian + Time;
    buttonPressed = true; 
    while(digitalRead(BUT)){}
  }    
}
//  RedToBlue_effect();
//  duoixenke(); 
 
//  cauvong();
//  pride();
//  rainbow();
//  sangtat();
//  sangdon();
//  xoaytron_doimau();
//  lenxuong_doimau();
//  xenkecauvong();
//  xenkedoimau();
//  duoi();

void effect(){
  buttonPressed = false; 
  switch (currentEffect) {
      case 0: tathieuung();                                              
                                              break;
      case 1: cauvong();                                        
                                              break;
      case 2: rainbow();                                        
                                              break;
      case 3: sangtat();                 
                                              break;
      case 4: FastLED.setBrightness(BRIGHTNESS );sangdon();                                            
                                              break;
      case 5: xoaytron_doimau();                                      
                                              break;
      case 6: lenxuong_doimau();                                         
                                              break;
      case 7: xenkecauvong();                                                
                                              break;
      case 8: pride();                                       
                                              break;
      case 9: xenkedoimau();                                                 
                                              break;
      case 10: duoi();                                                 
                                              break;
      default: currentEffect = 0;                                         
                                              break;
    }
}


void tathieuung() {
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}
