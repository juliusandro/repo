int sensorPin = 5;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:

float suhu(){
   int reading = analogRead(sensorPin); 
   float voltage = reading * 5.0;
   voltage /= 1024.0;
   float temperatureC = ((voltage - 0.5) * 10) + 7 ;
   return temperatureC;
  }
  
void loop() {
  // read the input on analog pin 0:
  delay(5000);
  Serial.println(suhu());
  

  
  // delay in between reads for stability
}
