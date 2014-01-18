
#include <I2Cdev.h>//add neccesary headfiles
#include <MPU6050.h>//add neccesary headfiles
#include <Wire.h>
//====the offset of gyro===========
#define Gx_offset  -1.50
#define Gy_offset  0
#define Gz_offset  0.80
//====the offset of accelerator===========
#define Ax_offset -0.07
#define Ay_offset 0.02
#define Az_offset 0.14
//====================
MPU6050 accelgyro;
 
int16_t ax,ay,az;//original data;
int16_t gx,gy,gz;//original data;
float Ax,Ay,Az;//Unit g(9.8m/s^2)
float Gx,Gy,Gz;//Unit ��/s
//#define LED_PIN 13 
//bool blinkState=false;
 
void setup()
{
  Wire.begin();
  Serial.begin(9600);
 
  Serial.println("Initializing I2C device.....");
  accelgyro.initialize();
  
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful":"MPU6050 connection failure");
  //pinMode(LED_PIN,OUTPUT);
  //accelgyro.setSleepEnabled(1);
}
 
void loop()
{
  
  accelgyro.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);//get the gyro and accelarator   
   //==========accelerator================================
   Ax=ax/16384.00;//to get data of unit(g)
   Ay=ay/16384.00;//to get data of unit(g)
   Az=az/16384.00;//to get data of unit(g)
   Serial.println("Acce data.....");
   Serial.print(Ax+Ax_offset);
   Serial.print("   ");
   Serial.print(Ay+Ay_offset);
   Serial.print("   ");
   Serial.println(Az+Az_offset);
   //===============gyro================================
   Gx=gx/131.00;
   Gy=gy/131.00;
   Gz=gz/131.00;
   Serial.println("Gyro data.....");
   Serial.print(Gx+Gx_offset);
   Serial.print("   ");
   Serial.print(Gy+Gy_offset);
   Serial.print("   ");
   Serial.println(Gz+Gz_offset);
  //blinkState=!blinkState;
  //digitalWrite(LED_PIN,blinkState); 
  delay(1000);//control time of sampling
}
