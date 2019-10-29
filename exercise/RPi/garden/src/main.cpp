#include <Arduino.h>
#include <ArduinoJson.h>

const int relay = 3;
const int pump = 8;
bool lightSwitch = 0;
int pumptimer = 0;

void setup() {
  Serial.begin(9600);//this begin the Serial connection
  pinMode(relay, OUTPUT);
  pinMode(pump, OUTPUT);
  while (!Serial) continue; //wait for serial port to be ready
}

void SendData(int temperature, int light, int moisture){
  StaticJsonBuffer<200> jsonBuffer; //this might need to grow bigger if there is more sensors this is the byte size of the JsonArray

  JsonObject& root = jsonBuffer.createObject();
  JsonArray& data = root.createNestedArray("data");

  JsonObject& tempSensor = jsonBuffer.createObject();
  tempSensor["sensor"] = "temperature";
  tempSensor["reading"] = temperature;
  data.add(tempSensor);

  JsonObject& moistSensor = jsonBuffer.createObject();
  moistSensor["sensor"] = "moisture";
  moistSensor["reading"] = moisture;
  data.add(moistSensor);

  JsonObject& LightSensor = jsonBuffer.createObject();
  LightSensor["sensor"] = "light";
  LightSensor["reading"] = light;
  data.add(LightSensor);
  root.printTo(Serial);// This prints the json data to the serial port*/
}
void ReceiveData(){
  //this assume this data format {"light":1,"pump":2}
  StaticJsonBuffer<200> reception;
  JsonObject& received = reception.parseObject(Serial);
  lightSwitch = received["light"]; //1 == lights on
  pumptimer = received["pump"]; //assumes the controller return a value representing the seconds pumps should run*/
}

void loop() {
  SendData(15, 100, 30);
  while(Serial.available() == 0){}//wait for serial data
  ReceiveData();
  /*
  digitalWrite(relay, HIGH);//complete the circuit, turn the light on
  digitalWrite(relay, LOW);//close the light
  digitalWrite(pump, HIGH);//complete the circuit, start the pump
  digitalWrite(pump, LOW);//stop the pump
  */
  digitalWrite(relay, lightSwitch);
  if(pumptimer>0){
    digitalWrite(13, HIGH);
    delay(pumptimer*1000);//convert to milliseconds
    digitalWrite(13, LOW);
  }

}
