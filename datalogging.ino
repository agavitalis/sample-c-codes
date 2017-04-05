#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include<stdlib.h>

//remember that this code logs  minutes, and easily be made to log in seconds by editing some part the code
//connct pin2 and 9 then connect and also your pin3 of your lcd.

//liguidCrystal(Rs,en,d4,d5,d6,d7)
LiquidCrystal lcd(8, 10, 6, 5, 4, 3);


//decleration for the datalogger
File datafile;


/////////ohmeter variables////////
float digValue;
float anaValue;
float vout100;
float vout2;


int id = 1;
const byte interruptPin = 2; // digital pin 2 is now interrupt pin

volatile int masterClock = 0; // counts rising edge clock signals
volatile int seconds = 0; // variable to hold seconds

int minutes = 0; // variable to hold minutes
int dispMinutes = 0; // variable for creating real time clock.

int hours = 0; // variable to hold hours
int dispHours = 0;

int days;
int dispdays = 0;

int secondsCounter = 0;
int minutesCounter = 0;


const int chipSelect = 7; // pin7 decleared as chip select(change if you used a different pin)
String CLEAR_SCREEN = "                ";

//edit these varible below to the current date and time, you started the logging
int p_minutes = 50; // variable for setting time. Equate it to the actual time at the point of starting
int p_hours = 11; // variable for setting time. Equate it to the actual time at the point of starting    
int p_days = 14; // variable for setting date
int Month = 2; //change to reflect the month at thepoint of logging or using keypad when implemented 
int Year = 2017; //change to reflect the year at thepoint of logging
int logging_interval = 3; // now in minutes



      void setup()
      {
          
          ////////declearig pin A0 as input pin for the ohmeter and clock pulse for counting time
          pinMode(A0,INPUT);
          pinMode(9, OUTPUT);// pin 9 pwm shall be used for interrupt trigger
          pinMode(chipSelect, OUTPUT);//chipSelect is pin7 remember as already decleared
          analogWrite(9, 127); // this starts our PWM 'clock' with a 50% duty cycle
          
         //intializing the lcd
         lcd.begin(16, 2);//this is the type of lcd we are using.
         lcd.setCursor(0, 0);


          //initializing the serial monitor
          Serial.begin(9600);
          attachInterrupt(digitalPinToInterrupt(interruptPin), clockCounter , RISING);
          // interruptPin is our interrupt, clockCounter function is called when
          // invoked on a RISING clock edge
          analogReference(DEFAULT);
         
         
        
           //printing a welcome massage
          lcd.print("Initializing SD card...");
          Serial.print("Initializing SD card...");
          delay (1000);
        

          
          // see if the card is present and can be initialized:
          if (!SD.begin(chipSelect)) 
          {
          lcd.setCursor(0, 0);
          lcd.print(CLEAR_SCREEN);
          lcd.setCursor(0, 0);
          lcd.println("Card failed, or not present");
          Serial.print("Card failed or not prsent");
          // if the system needs to stop uncomment return0 don't do anything more:
          // return(0);
          } 
          else 
          {
            
          lcd.setCursor(0, 0);
          lcd.print(CLEAR_SCREEN);
          lcd.setCursor(0, 0);
          lcd.println("SD card initialized");
          Serial.print("SD card initialized");
          delay (1000);//uncomment
 
          }
          //Access file to write the logged data to,""myData" is the name I gave the file to be written to
          datafile = SD.open("myData.csv", FILE_WRITE);
          if (datafile)
          {
            //set the header to choice now
              datafile.print(", ,\n");
              datafile.println("ECE461 TEST ON DATALOGGING BY");
              datafile.println("OGBONNA VITALIS");
              datafile.print(", ,\n");
                        datafile.print("id");
                        datafile.print (",");
                        
                       datafile.print("feb");
                       datafile.print(' ');
                       datafile.print("14");
                       datafile.print(' ');
                       datafile.print ("2017");
                        
                        datafile.print (",");
                        datafile.print("H");
                        datafile.print(':');
                        datafile.print("M");
                        datafile.print (':');
                        datafile.print("S");
                        
                        datafile.print (",");
                        datafile.print("Vout");
                        datafile.print (",");
                        datafile.print("Vout*100");
                        datafile.print (",");
                        datafile.print("100V-2");
                        datafile.print (",");
                        datafile.print("Vitalis");
                        datafile.close();
                        delay (1000);
                                  lcd.setCursor(0, 0);
                                  lcd.print(CLEAR_SCREEN);
                                  lcd.setCursor(0, 0);
                                  lcd.println("SD card accessed");
                                  Serial.println("SD card accessed");
                                  
      
          }
      }
                 void clockCounter() // called by interrupt
                     {
                        masterClock ++; // with each clock rise add 1 to masterclock count
                        if (masterClock == 489) // 490Hz reached. Note pwm roughly operate at a frequency of 490Hz
                        {
                          
                        seconds ++; // after one 490Hz cycle add 1 second ;)
                        secondsCounter++;
                        masterClock = 0; // Reset after 1 second is reached
                        }

                        
                        if (seconds==60)
                        {
                          minutes++;
                          minutesCounter++;
                          seconds=0;
                        }


                        
                        if (dispMinutes == 60)
                        {
                        dispHours ++; // increment hour by 1
                        dispMinutes = 0; // reset the minutes variable
                        minutes=0;
                        hours ++;
                        }


                        
                        if (dispHours == 24)
                        {
                        days ++; // increment day by 1
                        dispHours = 0; // reset the hour variable
                        }

              
              //to log in seconds, change the minutesCounter in the IF condition to secondsCounter          
                        if ( minutesCounter == logging_interval)
                        {
                        datafile = SD.open("myData.csv", FILE_WRITE);
                        if (datafile)
                        {

                          
                        
                        datafile.print(", ,\n");

                        datafile.print(id);
                        datafile.print (",");
                        
                        datafile.print("feb");
                        datafile.print(' ');
                        datafile.print("14");
                        datafile.print(' ');
                        datafile.print ("2017");
                        datafile.print (",");
                        
                        datafile.print(dispHours);
                        datafile.print(':');
                        datafile.print(dispMinutes);
                        datafile.print (':');
                        datafile.print(seconds);
                        datafile.print (",");
                        datafile.print(digValue);
                        datafile.print (",");
                        datafile.print(vout100);
                        datafile.print (",");
                        datafile.print(vout2);
                        datafile.print (",");
                        datafile.print("vitalis");
                        
                        Serial.println("data printed on memory card\n");
                        lcd.println("data printed");
                        datafile.close();



                
                       // to log in seconds, uncomment the second counter and comment the minutes conuter      
                       //secondsCounter = 0;
                       
                        minutesCounter=0;
                        id++;
                        }
                        }
                        return;
                       }
                                            void loop()
                                            {
                                                dispMinutes = p_minutes + minutes;
                                                dispHours = p_hours + hours;
                                                dispdays = p_days + days;
                                                
                                                ///luxmeter code
                                                digValue=analogRead(A0);
                                                digValue=digValue*0.0048;
                                                vout100=digValue*100;
                                                vout2=vout100-2;
                                                
                                                clearScreen();
                                                lcd.setCursor(0, 0);
                                                lcd.print(dispHours);
                                                lcd.print( ":");
                                                lcd.print(dispMinutes);
                                                lcd.print( ":");
                                                lcd.print( seconds);
                                                lcd.print( " ");
                                                lcd.print( dispdays);
                                                lcd.print( "/");
                                                lcd.print(Month);
                                                lcd.print( "/");
                                                lcd.print( Year);
                                                lcd.setCursor(1,1);
                                                lcd.print(digValue);
                                                lcd.print("  volts");
                                                delay(1000);



                                              Serial.print(dispHours);
                                              Serial.print( ":");
                                              Serial.print(dispMinutes);
                                              Serial.print( ":");
                                              Serial.print( seconds);
                                              Serial.print( " ");
                                              Serial.print( dispdays);
                                              Serial.print( "/");
                                              Serial.print(Month);
                                              Serial.print( "/");
                                              Serial.print( Year);
                                              Serial.print( "         /");
                                              Serial.print(digValue);
                                              Serial.println("volts");
                                            }
   //A function created to clear screen    
    void clearScreen(){
    lcd.setCursor(0, 0);
    lcd.print(CLEAR_SCREEN);
    lcd.setCursor(1, 0);
    lcd.print(CLEAR_SCREEN);
    }
 

