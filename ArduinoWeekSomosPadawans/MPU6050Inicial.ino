//Translate by: @OrlandoBatiz
//Link de la libreria en Github: https://github.com/rfetick/MPU6050_light
/* Obtiene todos los datos posibles del MPU6050
 * Los valores dados por el acelerometros se multiplicacion por: [1g = 9.81 m/s²]
 * Valores del Gyroscopio son dados en deg/s
 * El ángulo de inclinación es dado en grados
 * Notar que "X" y "Y" no son "Pitch/Roll"
 * License: MIT
 */

#include "Wire.h"
#include <MPU6050_light.h>              //Libreria desarrollada por rfetick. (buscar como "MPU6050_light")
MPU6050 mpu(Wire);                      //Inicializa el objeto del sensor MPU6050, en los pines A4=SDA, A5=SCL
long timer = 0;

void setup() {
  Serial.begin(9600);                   //Inicializar comunicación serial a 9600 Baudios
  Wire.begin();                         //Inicializa la comunicación I2C 
  
  byte status = mpu.begin();            
  Serial.print(F("MPU6050 estado: "));
  if(status == 0){
    Serial.println("Correcto");  
  }
  else{
    Serial.println("Desconectado");
  }
  while(status!=0){ }                   // No continua si no esta conectado el sensor MPU6050
  
  Serial.println(F("Calculando los offsets, no mover el MPU6050"));
  delay(1000);
  mpu.calcOffsets(true,true);           // Giroscopio y acelerometro
  Serial.println("Listooo Pana!\n");
  
}

void loop() {
  mpu.update();

  if(millis() - timer > 1000){         // Imprime cada segundo
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
    Serial.println(F("=====================================================\n"));
    timer = millis();
  }
}
