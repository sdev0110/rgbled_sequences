/**********************************************************************
 Include Files
 *********************************************************************/
#include <Arduino.h>

/**********************************************************************
 Public Data
 *********************************************************************/
int r1_redpin = 0;
int r1_bluepin = 1;
int r1_greenpin = 2;
int r2_redpin = 3;
int r2_bluepin = 4;
int r2_greenpin = 5;
int r3_redpin = 6;
int r3_bluepin = 7;
int r3_greenpin = 8;
int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;
int push_button = 12;
int buttonState = 0; //default
boolean ledState = false; //default
boolean prevledstate = false;
int globalcount = 0;

/**********************************************************************
 Name: debounceButton

 Description:
  detects HIGH digital signal and checkes for another HIGH digital
  signal to verify if push button is really pressed

 Input Parameters:
  buttonPin - Pin number of button

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void debounceButton(int buttonPin)
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == 1)
  {
    delay(50);
    buttonState = digitalRead(buttonPin);
    if (buttonState == 0)
    {
      globalcount = globalcount + 1;
      return;
    }
  }
  else{
    return;
  }
}


/**********************************************************************
 Name: RGB_color

 Description:
  Writes the numerical representation of colors on designated
  RGB Pins

 Input Parameters:
  red_light_value - determines whether red LED is ON (255) or OFF (0)
  blue_light_value - determines whether blue LED is ON (255) or OFF (0)
  green_light_value - determines whether green LED is ON (255) or OFF (0)

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

/**********************************************************************
 Name: mode1_redLED

 Description:
  LED mode where all RED leds are turned ON

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void mode1_redLED()
{
  digitalWrite(r1_redpin, HIGH);
  digitalWrite(r2_redpin, HIGH);
  digitalWrite(r3_redpin, HIGH);
  delay(100);
  digitalWrite(r1_redpin, LOW);
  digitalWrite(r2_redpin, LOW);
  digitalWrite(r3_redpin, LOW);
  delay(100);
  return;
}

/**********************************************************************
 Name: mode1_blueLED

 Description:
  LED mode where all BLUE leds are turned ON

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void mode2_blueLED()
{
  digitalWrite(r1_bluepin, HIGH);
  digitalWrite(r2_bluepin, HIGH);
  digitalWrite(r3_bluepin, HIGH);
  delay(100);
  digitalWrite(r1_bluepin, LOW);
  digitalWrite(r2_bluepin, LOW);
  digitalWrite(r3_bluepin, LOW);
  delay(100);
  return;
}

/**********************************************************************
 Name: mode1_greenLED

 Description:
  LED mode where all GREEN leds are turned ON

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void mode3_greenON()
{
  digitalWrite(r1_greenpin, HIGH);
  digitalWrite(r2_greenpin, HIGH);
  digitalWrite(r3_greenpin, HIGH);
  delay(100);
  digitalWrite(r1_greenpin, LOW);
  digitalWrite(r2_greenpin, LOW);
  digitalWrite(r3_greenpin, LOW);
  delay(100);
  return;
}

/**********************************************************************
 Name: mode4_forward

 Description:
  LED mode where light sequence are in forward motion

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void mode4_forward()
{
  digitalWrite(r1_redpin, HIGH);
  digitalWrite(r1_bluepin, LOW);
  digitalWrite(r1_greenpin, LOW);
  digitalWrite(r2_redpin, HIGH);
  digitalWrite(r2_bluepin, LOW);
  digitalWrite(r2_greenpin, LOW);
  digitalWrite(r3_redpin, HIGH);
  digitalWrite(r3_bluepin, LOW);
  digitalWrite(r3_greenpin, LOW);
  delay(100);
  digitalWrite(r1_redpin, LOW);
  digitalWrite(r1_bluepin, HIGH);
  digitalWrite(r1_greenpin, LOW);
  digitalWrite(r2_redpin, LOW);
  digitalWrite(r2_bluepin, HIGH);
  digitalWrite(r2_greenpin, LOW);
  digitalWrite(r3_redpin, LOW);
  digitalWrite(r3_bluepin, HIGH);
  digitalWrite(r3_greenpin, LOW);
  delay(100);
  digitalWrite(r1_redpin, LOW);
  digitalWrite(r1_bluepin, LOW);
  digitalWrite(r1_greenpin, HIGH);
  digitalWrite(r2_redpin, LOW);
  digitalWrite(r2_bluepin, LOW);
  digitalWrite(r2_greenpin, HIGH);
  digitalWrite(r3_redpin, LOW);
  digitalWrite(r3_bluepin, LOW);
  digitalWrite(r3_greenpin, HIGH);
  delay(100);
  return;
}

/**********************************************************************
 Name: mode5_allON

 Description:
  LED mode where all lights are turned ON

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void mode5_allON()
{
  digitalWrite(r1_redpin, HIGH);
  digitalWrite(r1_bluepin, HIGH);
  digitalWrite(r1_greenpin, HIGH);
  digitalWrite(r2_redpin, HIGH);
  digitalWrite(r2_bluepin, HIGH);
  digitalWrite(r2_greenpin, HIGH);
  digitalWrite(r3_redpin, HIGH);
  digitalWrite(r3_bluepin, HIGH);
  digitalWrite(r3_greenpin, HIGH);
  return;
}

/**********************************************************************
 Name: mode6_alternate

 Description:
  LED mode where color groups are turned ON alternately

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void mode6_alternate()
{
  digitalWrite(r1_redpin, HIGH);
  digitalWrite(r1_bluepin, LOW);
  digitalWrite(r1_greenpin, LOW);
  digitalWrite(r2_redpin, HIGH);
  digitalWrite(r2_bluepin, LOW);
  digitalWrite(r2_greenpin, LOW);
  digitalWrite(r3_redpin, HIGH);
  digitalWrite(r3_bluepin, LOW);
  digitalWrite(r3_greenpin, LOW);
  delay(1500);
  digitalWrite(r1_redpin, LOW);
  digitalWrite(r1_bluepin, HIGH);
  digitalWrite(r1_greenpin, LOW);
  digitalWrite(r2_redpin, LOW);
  digitalWrite(r2_bluepin, HIGH);
  digitalWrite(r2_greenpin, LOW);
  digitalWrite(r3_redpin, LOW);
  digitalWrite(r3_bluepin, HIGH);
  digitalWrite(r3_greenpin, LOW);
  delay(1500);
  digitalWrite(r1_redpin, LOW);
  digitalWrite(r1_bluepin, LOW);
  digitalWrite(r1_greenpin, HIGH);
  digitalWrite(r2_redpin, LOW);
  digitalWrite(r2_bluepin, LOW);
  digitalWrite(r2_greenpin, HIGH);
  digitalWrite(r3_redpin, LOW);
  digitalWrite(r3_bluepin, LOW);
  digitalWrite(r3_greenpin, HIGH);
  delay(1500);
}

/**********************************************************************
 Name: mode7_allOF

 Description:
  LED mode where all lights are turned OFF

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void mode7_allOFF()
{
  digitalWrite(r1_redpin, LOW);
  digitalWrite(r1_bluepin, LOW);
  digitalWrite(r1_greenpin, LOW);
  digitalWrite(r2_redpin, LOW);
  digitalWrite(r2_bluepin, LOW);
  digitalWrite(r2_greenpin, LOW);
  digitalWrite(r3_redpin, LOW);
  digitalWrite(r3_bluepin, LOW);
  digitalWrite(r3_greenpin, LOW);
  return;
}

/**********************************************************************
 Name: setup

 Description:
  Function that only executed at startup

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(r1_redpin, OUTPUT);
  pinMode(r1_bluepin, OUTPUT);
  pinMode(r1_greenpin, OUTPUT);
  pinMode(r2_redpin, OUTPUT);
  pinMode(r2_bluepin, OUTPUT);
  pinMode(r2_greenpin, OUTPUT);
  pinMode(r3_redpin, OUTPUT);
  pinMode(r3_bluepin, OUTPUT);
  pinMode(r3_greenpin, OUTPUT);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(push_button, INPUT_PULLUP);
  RGB_color(255, 255, 255); // White
}

/**********************************************************************
 Name: loop

 Description:
  Function that is being executed repeatedly

 Input Parameters:
  None

 Returned Value:
  None

 Assumptions / Limitations:
  None
**********************************************************************/
void loop() {
  // put your main code here, to run repeatedly:
  debounceButton(push_button);
  if (globalcount == 1)
  {
    mode1_redLED();
  }
  else if (globalcount == 2)
  {
    mode2_blueLED();
  }
  else if (globalcount == 3)
  {
    mode3_greenON();
  }
  else if (globalcount == 4)
  {
    mode4_forward();
  }
  else if (globalcount == 5)
  {
    mode5_allON();
  }
  else if (globalcount == 6)
  {
    mode6_alternate();
  }
  else if (globalcount == 7)
  {
    mode7_allOFF();

    if (globalcount == 7)
    {
      globalcount = 0;
    }
  }
  // RGB_color(255, 0, 0); // Red
  // delay(200);
  // RGB_color(0, 255, 0); // Green
  // delay(200);
  // RGB_color(0, 0, 255); // Blue
  // delay(200);
  // RGB_color(255, 255, 125); // Raspberry
  // delay(200);
  // RGB_color(0, 255, 255); // Cyan
  // delay(200);
  // RGB_color(255, 0, 255); // Magenta
  // delay(200);
  // RGB_color(255, 255, 0); // Yellow
  // delay(200);
  // RGB_color(0, 0, 0); // White
  // delay(200);
}

