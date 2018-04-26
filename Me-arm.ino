
#include <Servo.h>

Servo ser1;
Servo ser2;
Servo ser3; 
Servo ser4;
void setup(){
ser1.attach(4);//base
ser2.attach(8); //derecha -extencion
ser3.attach(10); //pinza 
ser4.attach(12);//izquierda -altura

  /*ser1.write(0);
  ser3.write(0);
  ser2.write(0);
  ser4.write(0);*/
}
void loop(){
  /*
//si señal del sensor de movimiento es igual a 1 ..ejecutar siguientes instrucciones
ser1.write(0); //cambiar la posición del ser1 al ángulo 0
delay(2000); //espera de 3 seg
ser1.write(70);
delay(2000);
ser1.write(40);
delay(2000);
ser3.write(50);
delay(2000);
ser3.write(90);
delay(2000);
ser3.write(10);
delay(2000);
ser2.write(60);
delay(2000);
ser2.write(90);
delay(2000);
ser2.write(60);
delay(2000);*/

//Pocisión inicial

ser1.write(90); //cambiar la posición del ser1 al ángulo 0
ser3.write(20);

delay(500);
ser3.write(40);
delay(500);
ser3.write(100); //Es una buena apertura de pinza
delay(500);
ser2.write(90); //El cero esta extendido
ser4.write(60); //El cero esta atras
delay(2000);

//Bajar 
ser2.write(30); //El cero esta extendido
ser4.write(90);//Baja
delay(500);
ser4.write(120); //Bajar
delay(500);

//Tomar Objeto
ser3.write(180);
delay(500);
ser3.write(70);
delay(500);
ser3.write(0); //Tomar a cosa
delay(500);


ser2.write(90); //El cero esta extendido
ser4.write(60); //El cero esta atras

delay(500);

//Mover base y Dejar Objeto.

ser1.write(30);
delay(500);

ser4.write(90); //Baja
ser4.write(120); //Bajar
delay(500);

ser3.write(100); //Suelta la cosa
delay(500);

ser2.write(90); //El cero esta extendido
ser4.write(60); //El cero esta atras
delay(1000);





/*
ser1.write(180);
delay(1000);
ser1.write(0); //cambiar la posición del ser1 al ángulo 0
delay(1000); //espera de 3 seg
ser1.write(180);
delay(1000);
ser1.write(0); //cambiar la posición del ser1 al ángulo 0
delay(1000); //espera de 3 seg
ser1.write(180);
delay(1000);*/

}
