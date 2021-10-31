#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float temp; 
float vout; 
float vout1; 
int LED = 13; 
int gasSensor; 
int piezo = 7; 
void setup() 
{ 
lcd.begin(16, 2);
pinMode(A0,INPUT); 
pinMode(A1, INPUT); 
pinMode(LED,OUTPUT); 
pinMode(piezo,OUTPUT); 
Serial.begin(9600); 
} 
void loop() 
{ 
vout=analogRead(A1); 
vout1=(vout/1023)*5000; 
temp=(vout1-500)/10; 
 
if (temp>=80) 
{ 
digitalWrite(LED,HIGH); 
} 
else 
{ 
digitalWrite(LED,LOW); 
}
  
gasSensor=analogRead(A0); 
if (gasSensor>=100) 
{ 
digitalWrite(piezo,HIGH); 
} 
else 
{ 
digitalWrite(piezo,LOW); 
}
lcd.setCursor(0, 0);
if(gasSensor>=100){
    lcd.print("smoke ");
    lcd.print(gasSensor);
    
    delay(2000);
  }
 else{
  lcd.print("nosmoke ");
  lcd.print(gasSensor);
  
  delay(2000);
 }
lcd.setCursor(0,1);
lcd.print("temp:");
lcd.print(temp);
Serial.print("in DegreeC= "); 
Serial.print(" "); 
Serial.print(temp); 
Serial.print("\t"); 
Serial.print("GasSensor= "); 
Serial.print(" "); 
Serial.print(gasSensor); 
Serial.println(); 
delay(1000); 
}
