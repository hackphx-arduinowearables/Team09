// IMU 
#include <I2Cdev.h>
#include <MPU6050.h>

#include <Wire.h>
#include <Adafruit_NeoPixel.h>

// DEFINES for Adafruit NEopixel
#define N_PIXELS 6
#define LED_PIN 15
//====the offset of gyro===========
//#define Gx_offset  -1.50
//#define Gy_offset  0
//#define Gz_offset  0.80
//====the offset of accelerator===========
#define Ax_offset -0.03
#define Ay_offset 0.02
#define Az_offset 0.14
//====================

int16_t ax,ay,az;//original data;
int16_t gx,gy,gz;//original data;
float Ax,Ay,Az;
float DAUG, DAUGScore;
int Time;

MPU6050 accelgyro;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.setBrightness(100);
  strip.begin();
  Wire.begin();
  Serial.begin(9600);
  Serial1.begin(38400); // Serial1 is used for the Bluetooth
  
  //Serial.println("Initializing I2C device.....");
  accelgyro.initialize();
  
  //Serial.println("Testing device connections...");
  //Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful":"MPU6050 connection failure");

  // Needed for the Xadow BLE slave
  DDRB|=0x21;        
  PORTB |= 0x21;
  
 //setting up initial variables
  Time = 100; 
  DAUGScore = 0;
}

void loop()
{
  CalculateDaugs(); 
  SetLeds();
  SendDaugsOverBT();
   
  delay(Time);//control time of sampling
}

void CalculateDaugs(){
accelgyro.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);//get the gyro and accelarator   
   //==========accelerator================================
   Ax=ax/16384.00;//to get data of unit(g)
   Ay=ay/16384.00;//to get data of unit(g)
   Az=az/16384.00;//to get data of unit(g)
 
 //Calculate Dog Activity Units Generalized (DAUG)
 //===============================================
 
 //Calculating dog activity units in units of gravity, subtracting gravity (1 = One unit of g) so that only activity beyond standing and lying is counted
 //DAUG is the scalar sum of the acceleration in x, y and z directions (minus gravity)
 //DAUG cannot be smaller than 0
 
  DAUG = max(sqrt(pow(Ax+Ax_offset,2) + pow(Ay+Ay_offset,2) + pow(Az+Az_offset,2)) - 1,0);
  DAUGScore = DAUGScore + DAUG;
}

void SetLeds()
{
  if(DAUGScore < 100) {
    for(int i =0; i< N_PIXELS; i++)
      {
        strip.setPixelColor(i,255,0, 0);
      }
    }
    else if (DAUGScore <5000){
      for(int i =0; i< N_PIXELS; i++)
      {
        strip.setPixelColor(i,0,0, 255);
      }
    }
    else {  
      for(int i =0; i< N_PIXELS; i++)
      {
        strip.setPixelColor(i,0,255, 0);
      }
    }
    strip.show();
}

void SendDaugsOverBT()
{
  char tmp[25];
  dtostrf(DAUG, 3, 2, &tmp[1]);
  if(DAUG > 0.2)//above threshold, send value
  {
    Serial1.write(tmp);
  }
  else if (DAUG <= 0.2)//below threshold, send zero
  {
    Serial1.write("Zilch");
  }
}
