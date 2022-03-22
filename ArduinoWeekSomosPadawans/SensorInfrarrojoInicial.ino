//By: @OrlandoBatiz

const int sensorInfrarrojo = 8;                 //Constante donde guardamos el pin del sensor 8
int estadoSensor=0;                             //Variable para leer el estado del sensor

void setup() {
  Serial.begin(9600);                           //Inicia la comunicacion serial a 9600 baudios
  pinMode(sensorInfrarrojo, INPUT);             //Modo del pin Digital a entrada
}

void loop() {

  estadoSensor = digitalRead(sensorInfrarrojo); //Leemos el estado del sensor
  Serial.print("Arduino dice: ");
  if(estadoSensor == 0){                        //Logica inversa del sensor
    Serial.println("Holaaaa Panaaa");             
  }
  else{
    Serial.println(":C Aún no llegas pana");
  }
  delay(500);                                   //Cada 500 ms revisara el sensor
}
