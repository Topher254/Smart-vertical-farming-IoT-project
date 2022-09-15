//https://www.tinkercad.com/things/1skZljAbK7g-glorious-gogo-rottis/editel
//vertical farming model
//By Topher Telecoms
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0); 
#define temperaturepin A0
#define our_voltage 5.0
#define moisture_pin A1
#define LED 13
const int LDR = A2;
int ldr_val = 0;
int moisture = 0;
int moisture_percentage = 0;
void setup()
{
 Serial.begin(9600);
  pinMode(A1, INPUT);
 // pinMode(A2, INPUT);
lcd_1.begin(16, 2);
lcd_1.print("VERTICAL FARMING");
 
}

void loop()
{
  
  //temperature sensor
  int temp_reading = analogRead(temperaturepin);
  float voltage = temp_reading * (our_voltage / 1024.0);
// Converting the voltage into the temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" degrees");
  delay(1000);
  //turn fan on if temperature is greater than 30 degrees
   if (temperatureC > 30) {
    digitalWrite(12, HIGH);
    
  }
  else{
     digitalWrite(12, LOW);
  }
 // soil moisture sensor
  moisture = analogRead(A0);  
  moisture_percentage  = map(moisture, 0, 1023, 0, 100); 
  Serial.print("Moisture = ");
  Serial.print(moisture_percentage); 
  Serial.println(" %");
  delay(1000);
  if (moisture_percentage < 20) {
    digitalWrite(11, HIGH);
  }
  else{
     digitalWrite(11, LOW);
  }
  //ldr sensor
  ldr_val = analogRead(LDR);
  Serial.print("LDR Value is: ");
  Serial.println(ldr_val);
  lcd_1.setCursor(0,1);
  lcd_1.print("L:");
  lcd_1.setCursor(2,1);
  lcd_1.print(ldr_val);
  lcd_1.setCursor(5,1);
  lcd_1.print("M:");
  lcd_1.setCursor(7,1);
  lcd_1.print(moisture_percentage);
  lcd_1.setCursor(10,1);
  lcd_1.print("T:");
  lcd_1.setCursor(12,1);
  lcd_1.print(temperatureC);
  delay(1000);
  if (ldr_val < 500) {
    digitalWrite(LED, HIGH);
  }
  else{
     digitalWrite(LED, LOW);
  }
 
  //LCD
  lcd_1.setCursor(2, 0);
  lcd_1.setBacklight(1);

}
