#include <BlynkGOv2.h>
#include <ESP32Servo.h>

#define SERVO_PIN  22
Servo  servo; //ประกาศตัวแปรแทน Servo

GSlider slider;

void setup() {
  Serial.begin(115200); Serial.println();
  BlynkGO.begin();
  servo.attach(SERVO_PIN);

  slider.range(0,180);
  slider.color(TFT_RED);
  slider.onValueChanged([](GWidget*widget){
    //ดึงค่า slider มากำหนดองศาให้ servo
    servo.write(slider.value());  
  });
  
}

void loop() {
  BlynkGO.update();
}
