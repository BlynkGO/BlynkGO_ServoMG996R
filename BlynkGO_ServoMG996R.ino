#include <BlynkGOv2.h>
#include <Servo.h>  // โหลดจาก https://github.com/RoboticsBrno/ServoESP32

#define SERVO_PIN       25
#define SERVO_CHANNEL   12

Servo servo;

GSlider slider;
GLabel  label;

void setup() {
  Serial.begin(115200); Serial.println();
  BlynkGO.begin();

  servo.attach(SERVO_PIN, SERVO_CHANNEL);

  slider.range(0,180);
  slider.color(TFT_RED);
  slider.onValueChanged([](GWidget*widget){
    //ดึงค่า slider มากำหนดองศาให้ servo
    label = slider.value();
    static GTimer timer;
    timer.setOnce(20,[](){
      servo.write(slider.value());         // Wait for end of previous rotation.
    });
  });

  label.font(prasanmit_40);
  label.align(slider, ALIGN_TOP,0,-20);
  label = 0;
}

void loop() {
  BlynkGO.update();
}
