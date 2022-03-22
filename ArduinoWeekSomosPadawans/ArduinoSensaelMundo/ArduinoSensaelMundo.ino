//By: @OrlandoBatiz
#include <HCSR04.h>                             //Libreria desarrollada por Gamegine (Buscar como "hcsr04 ultrasonic sensor")
#include "Wire.h"
#include <MPU6050_light.h>                      //Libreria desarrollada por rfetick. (buscar como "MPU6050_light")

//Sensor Ultrasonico HCSR04
HCSR04 hc(5, 6);                                //Inicializamos el objeto del sensor HCSR04 (pin de Trigger , pin de Echo)

//Sensor de Presencia Infrarrojo
const int sensorInfrarrojo = 8;                 //Constante donde guardamos el pin del sensor 8
int estadoSensor=0;                             //Variable para leer el estado del sensor

//Sensor MPU6050
MPU6050 mpu(Wire);                              //Inicializa el objeto del sensor MPU6050, en los pines A4=SDA, A5=SCL
long timer = 0;

void setup() {
  Serial.begin(9600);                           //Inicia la comunicacion serial a 9600 baudios
  pinMode(sensorInfrarrojo, INPUT);             //Modo del pin Digital a entrada
  Wire.begin();                                 //Inicializa la comunicación I2C 
  
  byte status = mpu.begin();            
  Serial.print(F("MPU6050 estado: "));
  if(status == 0){
    Serial.println("Correcto");  
  }
  else{
    Serial.println("Desconectado");
  }
  while(status!=0){ }                           // No continua si no esta conectado el sensor MPU6050
  
  Serial.println(F("Calculando los offsets, no mover el MPU6050"));
  delay(1000);
  mpu.calcOffsets(true,true);                   // Giroscopio y acelerometro
  Serial.println("Listooo Pana!\n");
    
}

void loop() {

  estadoSensor = digitalRead(sensorInfrarrojo); //Leemos el estado del sensor
  Serial.print("Arduino dice: ");
  if(estadoSensor == 0){                        //Logica inversa del sensor
    //Sensor de Presencia Infrarrojo
    Serial.println("Holaaaa Panaaa");
    
    //Sensor Ultrasonico para distancia
    Serial.print("Arduino te ve a: ");
    Serial.print(hc.dist());                    // Regresa la distancia a la que se encuentra el objeto en cm :O
    Serial.println(" cm");                      //Para imprimir la medida u otro mensaje  
    delay(200);            

    //Sesor MPU6050, que tiene varios sensores dentro como tu smartphone
    Serial.println("\n\nARDUINO TE PASA SU REPORTE DE ESTADO");
    Serial.println(F("=====================================================\n"));
    Serial.print(F("TEMPERATURA: "));Serial.println(mpu.getTemp());
    Serial.print(F("ACCELERO  X: "));Serial.print(mpu.getAccX());
    Serial.print("\tY: ");Serial.print(mpu.getAccY());
    Serial.print("\tZ: ");Serial.println(mpu.getAccZ());
   
    Serial.print(F("GYRO      X: "));Serial.print(mpu.getGyroX());
    Serial.print("\tY: ");Serial.print(mpu.getGyroY());
    Serial.print("\tZ: ");Serial.println(mpu.getGyroZ());
  
    Serial.print(F("ACC ANGLE X: "));Serial.print(mpu.getAccAngleX());
    Serial.print("\tY: ");Serial.println(mpu.getAccAngleY());
    
    Serial.print(F("ANGLE     X: "));Serial.print(mpu.getAngleX());
    Serial.print("\tY: ");Serial.print(mpu.getAngleY());
    Serial.print("\tZ: ");Serial.println(mpu.getAngleZ());
    Serial.println("\n");
  }
  else{
    Serial.println(":C Aún no llegas pana");
  }

  
  delay(1000);                                   //Cada 1000 ms revisara el sensor
}
