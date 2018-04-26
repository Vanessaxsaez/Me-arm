
#include <Servo.h>

Servo ser1_base;
Servo ser2_der;
Servo ser3_pinza; 
Servo ser4_izq;
void setup(){
  
  ser1_base.attach(4);//base
  ser2_der.attach(8); //derecha -extencion
  ser3_pinza.attach(10); //pinza 
  ser4_izq.attach(12);//izquierda -altura

  /*ser1_base.write(0);
  ser3_pinza.write(0);
  ser2_der.write(0);
  ser4_izq.write(0);*/
}


void transrot(Servo servo, int rot_fin){
  int rot_ini = servo.read();
  if( rot_ini > rot_fin){
    for (int i = rot_ini; i > rot_fin; i--){
      servo.write(i);
      delay(15);
    }
  }else {
    for (int i = rot_ini; i < rot_fin; i++){
      servo.write(i);
      delay(15);
    }
  }
}

void pos1(){
  
}
void pos2(){
  
}
void pos3(){
  
}

void posInit(){
  transrot(ser1_base, 90); //cambiar la posición del ser1_base al ángulo 0
  transrot(ser3_pinza, 120);
  delay(500);
  transrot(ser2_der, 120); //El cero esta extendido
  transrot(ser4_izq, 60); //El cero esta atras
  delay(500);
}

void postFinal(){

  transrot(ser4_izq, 60); //El cero esta atras
  transrot(ser2_der, 90); //El cero esta extendido

}

void loop(){
  
  //Pocisión inicial
  posInit();

  //Bajar 
  transrot(ser1_base, 75); // Base
  transrot(ser2_der, 40); // Extension
  transrot(ser4_izq, 90); // Fuerza
  delay(1000);

    
  //Tomar Objeto
  delay(500);
  transrot(ser3_pinza,60);
  //transrot(ser3_pinza, 0); //Tomar a cosa
  delay(500);

  //Resetear movimiento
  postFinal();
}
