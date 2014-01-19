

#include <SeeedOLED.h>

#include <I2Cdev.h>

#include <GSM.h>


#include <MPU6050.h>//add neccesary headfiles
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

// DEFINES for Adafruit NEopixel

#define N_PIXELS 6
#define LED_PIN 15


//====the offset of gyro===========
#define Gx_offset  -1.50
#define Gy_offset  0
#define Gz_offset  0.80
//====the offset of accelerator===========
#define Ax_offset -0.03
#define Ay_offset 0.02
#define Az_offset 0.14
//====================
MPU6050 accelgyro;

Adafruit_NeoPixel  strip = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

 
int test_int = 9;
int16_t ax,ay,az;//original data;
int16_t gx,gy,gz;//original data;
float Ax,Ay,Az, Aplane, Azplane;//Unit g(9.8m/s^2)
float Gx,Gy,Gz;//Unit ï¿½ï¿½/s
float Vx, Vy, Vz, Vplane;
float Dx, Dy, Dz;
int Time; float Time_s;
float DAUG, DAUGScore;

//#define LED_PIN 13 
//bool blinkState=false;
 
void setup()
{
  strip.setBrightness(100);
  strip.begin();
  Wire.begin();
  Serial.begin(9600);
   Serial1.begin(38400);
  
  Serial.println("Initializing I2C device.....");
  accelgyro.initialize();
  
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful":"MPU6050 connection failure");
  //pinMode(LED_PIN,OUTPUT);
  //accelgyro.setSleepEnabled(1);
  
  Wire.begin();
  SeeedOled.init();  //initialze SEEED OLED display
  DDRB|=0x21;        
  PORTB |= 0x21;
DAUGScore = 0;
  SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode
  SeeedOled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column  
  //SeeedOled.putString("Hello World!"); //Print the String
  
 //setting up initial variables
 Time = 100; Time_s = Time/1000; //first in milliseconds, second in seconds 
}

void loop()
{
  strip.setPixelColor(0,   100,   50, 50);
  strip.show();
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
  
  if(DAUGScore < 100) {
  for(int i ; i< N_PIXELS; i++)
    {
      strip.setPixelColor(i,255,0, 0);
    }
  }
   else if (DAUGScore <5000){
    for(int i ; i< N_PIXELS; i++)
    {
      strip.setPixelColor(i,0,0, 255);
    }
  }
  else {  for(int i ; i< N_PIXELS; i++)
    {
      strip.setPixelColor(i,0,255, 0);
    }
  }
  strip.show();
  
  char tmp[25];
  dtostrf(DAUG, 3, 2, &tmp[1]);
  SeeedOled.setTextXY(0,8);
  SeeedOled.putString(tmp);
  //Serial1.write("DAUG =");
  //Serial1.write(tmp);
  
  //Send DAUGs to bluetooth
  //==============================================
  
  if(DAUG > 0.2)//above threshold, send value
  {
    //Serial1.write("DAUG =");
    Serial1.write(tmp);
  }
  else if (DAUG <= 0.2)//below threshold, send zero
  {
    Serial1.write("Zilch");
  }
  
    delay(Time);//control time of sampling
  
   //SeeedOled.putString("%f", Az); //Print the String
   //===============gyro================================
   //Gx=gx/131.00;
   //Gy=gy/131.00;
   //Gz=gz/131.00;
  // Serial.println("Gyro data.....");
  // Serial.print(Gx+Gx_offset);
  // Serial.print("   ");
  // Serial.print(Gy+Gy_offset);
  // Serial.print("   ");
  // Serial.println(Gz+Gz_offset);
  //blinkState=!blinkState;
  //digitalWrite(LED_PIN,blinkState); 
  delay(Time);//control time of sampling
}

