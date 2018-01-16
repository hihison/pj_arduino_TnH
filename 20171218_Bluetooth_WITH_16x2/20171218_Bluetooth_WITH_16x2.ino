//Bluetooth .h
#include <SoftwareSerial.h>
//16x2 .h
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//Senser .h
#include "DHT.h"
#define DHTPIN 2   
#define DHTTYPE DHT11  

LiquidCrystal_I2C lcd ( 0x27 , 2 , 1 , 0 , 4 , 5 , 6 , 7 , 3 , POSITIVE); //Newliquidcrystal_1.3.5
// Library cloned here: https://github.com/hihison/new-liquidcrystal-clone

//LiquidCrystal_I2C lcd(0x27, 16,2); <<another Library

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

SoftwareSerial BT(10,11); //RX(READ) , TX(Transfer)
int led[] = {13,12};
String receive;
bool state[] = {false,false} ;
String sreceive;
void setup() {
  Serial.begin(115200);
  BT.begin(115200);
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  Serial.println("HELLO World");
  lcd.begin(16,2);
  dht.begin();

}

void ptrdata(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("*C\t");
  Serial.print(f);
  Serial.print("*F\n");

  lcd.setBacklight (HIGH);
  lcd.setCursor (0,0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.setCursor (0,1);
    //lcd.scrollDisplayLeft();
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" *C");
  h = 0;
  t = h;
  f = t;
}


void loop() {/*
  if(BT.available() ) {
     lcd.setBacklight (HIGH);
     receive = BT.readString();
     lcd.setCursor(0,0);
     lcd.print("===============BT is ready!=============");
     lcd.setCursor(0,1);
     lcd.print(receive);
     delay(1000);
     lcd.setCursor(0,1);
     lcd.print("              ");
  }
  else {
    Serial.println("WAITING 4 BLUETOOTH");
    //lcd.print ( "Waiting for BT" );
    //lcd.scrollDisplayLeft();
    //delay(100);
    //lcd.setCursor (0,1);
    //lcd.print ( "Hello World" );
    delay(250);

  }*//*<<<<BLUETOOTH*/
 /* if (Serial.available()>0){
    char received = Serial.read();
    if (received == '1'){*/

  sreceive = Serial.readString();
  if (sreceive == "get"){ 
     ptrdata();
     delay(1000);
  }
  if (sreceive == "exit"){
    lcd.setBacklight (LOW);
    lcd.setCursor (0,0);
    lcd.print("===============Terminated!=============");
    lcd.setCursor (0,1);
    lcd.print("=======================================");
    exit(0);
  }
  /*
    }
  }*/

    

 // 
//delay(500);

//  delay(50);
}
void lighton(int light){
  digitalWrite(light,HIGH);
  //Serial.print("LED ON :"+light);

}

void lightoff(int light){
  digitalWrite(light,LOW); 
  //Serial.print("LED OFF :"+light);
}
