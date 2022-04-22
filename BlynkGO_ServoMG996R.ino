#include <BlynkGOv2.h>
#include <ESP32Servo.h>  // ติดตั้งไลบรารี่จาก https://github.com/ShellAddicted/ESP32Servo

#define SERVO_PIN  22
Servo  servo; //ประกาศตัวแปรแทน Servo

GSlider slider;
GLabel  label;

void setup() {
  Serial.begin(115200); Serial.println();
  BlynkGO.begin();
  servo.attach(SERVO_PIN);

  slider.range(0,180);
  slider.color(TFT_RED);
  slider.onValueChanged([](GWidget*widget){
    //ดึงค่า slider มากำหนดองศาให้ servo
    label = slider.value();
    servo.write(slider.value());
  });
  label.font(prasanmit_40);
  label.align(slider, ALIGN_TOP,0,-20);
  label = 0;
}

void loop() {
  BlynkGO.update();
}


