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

  slider.size(360,24);
  slider.range(0,180);
  slider.color(TFT_RED);
  slider.align(ALIGN_BOTTOM,0,-40);

  // ปรับ style ทำการ customize หน้าตาเพิ่มเติมเอง
  slider.style[KNOB].color(TFT_BLUE, TFT_CYAN);     // สีตัว ปุ่มเลื่อน slider
  slider.style[KNOB].padding_left_right(20);        // ปรับเพิ่มระยะแนวนอน ของปุ่มเลื่อน slider
  slider.style[KNOB].padding_top_bottom(15);        // ปรับเพิ่มระยะแนวตั้ง ของปุ่มเลื่อน slider  
  slider.style[KNOB].corner_radius(20);             // รัศมีมุมโค้งของ ปุ่มเลื่อน slider
  slider.style[INDIC].padding_top_bottom(5);        // ระยะช่องไฟบนล่าง ระหว่าง พื้นหลัง slider กับ indic
  slider.style[INDIC].padding_left_right(25);       // ระยะช่องไฟซ้ายขวา ระหว่าง พื้นหลัง slider กับ indic
  slider.style[BG].opa(30);                         // ปรับความโปร่งใสของ พื้นหลัง slider

  label.font(prasanmit_40);
  label.align(slider, ALIGN_TOP,0,-20);
  
  slider.onValueChanged([](GWidget*widget){
    //ดึงค่า slider มากำหนดองศาให้ servo
    label = slider.value();
    static GTimer timer;
    timer.setOnce(20,[](){
      servo.write(slider.value());         // Wait for end of previous rotation.
    });
  });
  slider = 90;
  slider.event_send(EVENT_VALUE_CHANGED);           // สั่งให้ slider ทำงานภายใน onValueChanged(..) ที่กำหนดไป

}

void loop() {
  BlynkGO.update();
}
