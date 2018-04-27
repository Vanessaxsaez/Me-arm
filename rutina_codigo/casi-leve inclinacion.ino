
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

void posInit(){
  transrot(ser1_base, 90); //cambiar la posición del ser1_base al ángulo 0
  transrot(ser3_pinza, 120);
  delay(500);
  transrot(ser4_izq, 60); //El cero esta atras
  transrot(ser2_der, 100); //El cero esta extendido
  delay(500);
}

void tomarObjeto(){
  //Tomar Objeto
  delay(500);
  transrot(ser3_pinza,55);
  //transrot(ser3_pinza, 0); //Tomar a cosa
  delay(500);
}

void pos1(){
  
  //Bajar 
  transrot(ser1_base, 75); // Base
  transrot(ser2_der, 40); // Extension
  transrot(ser4_izq, 100); // Fuerza
  delay(1000);
}
void pos2(){
  
  //Bajar 
  transrot(ser1_base, 40); // Base
  transrot(ser2_der, 50); // Extension
  delay(1000);
}
void pos3(){

  //Bajar 
  transrot(ser1_base, 10); // Base
  transrot(ser2_der, 40); // Extension
  //transrot(ser4_izq, 90); // Fuerza
  delay(1000);
}

void transicion(){
  
  transrot(ser4_izq, 45); //El cero esta atras
  delay(1000);
  transrot(ser2_der, 120);
}

void loop(){
  
  //Pocisión inicial
  posInit();


  ////// Primera cajita //////
  pos1();
  tomarObjeto();
  transrot(ser2_der, 120);
  transrot(ser4_izq, 55); 
  ////////////
  transrot(ser4_izq, 90); // 
  
  transicion();

  pos3();
  transrot(ser4_izq, 90); // Bajar hasta el segundo nivel
  transrot(ser3_pinza, 100); // Soltar objeto

  
  ///// Segunda cajita //////
  transicion();
  pos2();
  transrot(ser4_izq, 90); // Fuerza
  tomarObjeto();
  transicion();
  
  pos3();
  transrot(ser4_izq, 80);// Bajar hasta el segundo nivel
 delay(500);
  transrot(ser3_pinza, 100); // Soltar objeto



  /// Tercera cajita ////
  transicion();
  transrot(ser1_base, 40); // Base
  transrot(ser2_der, 30); // Extension
  transrot(ser4_izq, 110); // Fuerza
  tomarObjeto();
  transicion();


  transrot(ser1_base, 10); // Base
  delay(500);
  transrot(ser2_der, 30); // Extension <- aqui falta afinar
  delay(500);
  transrot(ser4_izq, 70); // Fuerza <- aqui falta afinar
  transrot(ser3_pinza, 100); // Soltar objeto  
  transicion();
  //postFinal();
} 
