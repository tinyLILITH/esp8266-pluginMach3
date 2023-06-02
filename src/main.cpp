#define EB_DEB 50      // дебаунс кнопки, мс
#define EB_CLICK 500  // таймаут накликивания, мс
#define EB_HOLD 200

#define BTN1 14
#define BTN2 5
#define BTN3 4
#define BTN4 0
#define BTN5 2
#define BTN6 10

#include <EncButton.h>
//Encoder enc1(CLK, DT, SW);  // для работы c кнопкой
//Encoder enc1(CLK, DT, SW, TYPE2);  // для работы c кнопкой и сразу выбираем тип
//Encoder enc1(CLK, DT, ENC_NO_BUTTON, TYPE2);  // для работы без кнопки и сразу выбираем тип

int value = 0;


EncButton <EB_TICK, BTN1> butt1;
EncButton <EB_TICK, BTN2> butt2;
EncButton <EB_TICK, BTN3> butt3;
EncButton <EB_TICK, BTN4> butt4;
EncButton <EB_TICK, BTN5> butt5;
EncButton <EB_TICK, BTN6> butt6;

void setup() {
  Serial.begin(9600);

}

void loop() {
	// обязательная функция отработки. Должна постоянно опрашиваться
  butt1.tick();
  butt2.tick();
   butt3.tick();
     butt4.tick();
  butt5.tick();
   butt6.tick();
/*
    if (butt4.isStep(1)) {
    Serial.println("Y");
  }
 */ 



    if (butt1.click()) Serial.println("1");
    if (butt2.click()) Serial.println("2");

    if (butt3.step()) Serial.println("jF++");
    if (butt6.step()) Serial.println("jF--");
    
    if (butt3.click()) Serial.println("jF++");
    if (butt6.click()) Serial.println("jF--");

    if (butt3.release()) Serial.println("stop");
    if (butt6.release()) Serial.println("stop");

    if (butt4.isStep()) {Serial.println("stpJ");}  

    if (butt4.hasClicks(2)) Serial.println("Z"); // double selected z axis
    if (butt4.hasClicks(1)) Serial.println("X"); //single selected x axis 

  
    
  
}