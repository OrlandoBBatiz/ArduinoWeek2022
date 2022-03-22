//Translate by: @OrlandoBatiz
//Link de Libreria en Github: https://github.com/gamegine/HCSR04-ultrasonic-sensor-lib
#include <HCSR04.h>         //Libreria desarrollada por Gamegine (Buscar como "hcsr04 ultrasonic sensor")
HCSR04 hc(5, 6);            //Inicializamos el objeto del sensor HCSR04 (pin de Trigger , pin de Echo)

void setup(){
    Serial.begin(9600);     //Inicializa la comunicación a 9600 baudios
}

void loop(){
    Serial.print(hc.dist());   // Regresa la distancia a la que se encuentra el objeto en cm :O
    Serial.println(" cm");     //Para imprimir la medida u otro mensaje 
    delay(60);                 // Es el delay para aparecer nueva medición, se recomienda arriba de 60ms
}
