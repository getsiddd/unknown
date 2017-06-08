
#include "HX711.h"
#include "U8glib.h"

U8GLIB_KS0108_128 u8g(A0, A1, A2, A3, A4, A5, A6, A7, 20, 23, 22, 18, 19); //8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, cs1=14, cs2=15,di=17,rw=16

float weight = 0.0;
char buffer1[11];
uint8_t keys;

void draw(char *string, int po_X, int po_Y) {
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(po_X, po_Y); 
  u8g.print(string);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Welcome to WeightX-Program");
  u8g.setRot180();
  u8g.firstPage();  
  do {
     draw("Weight-X", 0, 30);
  } while( u8g.nextPage() );
  
  HX711_init(128);
  for(int i=0;i<10;i++){
    HX711_read_average(10);  
  }
  HX711_tare(10);
  HX711_set_scale(3434.0f);
}

void loop() {
  // put your main code here, to run repeatedly:
  weight = HX711_get_units(10);
  if(weight <= 0.00049 && weight>= - 0.00049){
    HX711_set_offset(weight*HX711_get_scale() + HX711_get_offset());
    weight = 0;
  }
  dtostrf(weight, 5, 5, buffer1);
  u8g.firstPage();  
  do {
      draw("Weight:", 0, 15);
      draw(buffer1, 0, 30);
  } while( u8g.nextPage() );
 delay(500);
}


