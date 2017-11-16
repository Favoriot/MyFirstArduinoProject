#define sensorPin A0
#define pushButton 2
int sensorValue = 0;
int celcius = 0;

void setup() 
{   Serial.begin(9600);  
    pinMode(pushButton, INPUT);
    pinMode(sensorPin, INPUT);
    Serial.println("Press to get temperature");
}

void loop()
{
if(digitalRead(pushButton) == LOW)  // Execute when push button is pressed
{   
        // Read data from temperature sensor and convert ADC value to celcius
        celcius = analogRead(sensorPin) * 0.488;   
        // Display current temperature
        Serial.println("Temperature : " + String(celcius) + " Celcius");
        delay(1000);
  }
}

