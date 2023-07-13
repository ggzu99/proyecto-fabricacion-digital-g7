
#include <Ultrasonic.h> //Librería que facilita el uso de sensores ultrasonicos, con ella no es necesario definir los trig and
//echo pin, sino que se usa la notacion Ultrasonic ultrasonic()

//LINK LIBRERIA: https://github.com/ErickSimoes/Ultrasonic/tree/master

//DEFINICION DE PINES--------------------------------------------------------------------------------------
Ultrasonic ultrasonic(13,12);

//Pines asociados a motores
const int IN1=7;
const int IN2=5;
const int IN3=4;
const int IN4=2;
const int enAPin = 6; // Pin para control PWM del motor DC IZQUIERDO
const int enBPin = 3; // Pin para control PWM del motor DC DERECHO

//Pines analógicos asociados a Sensores IR
#define IR_sensor_front A0 // Sensor IR delantero
#define IR_sensor_back A5 // Sensor IR trasero
int distance ;
//----------------------------------------------------------------------------------------------------------





void setup() 
{
Serial.begin(9600);
delay (5000); // Esperamos 5 segundos antes de partir
}




void loop()
{
 int IR_front = analogRead(IR_sensor_front); //Leemos sensor delantero
 int IR_back = analogRead(IR_sensor_back);   //Leemos sensor trasero
 distance = ultrasonic.read();  //Leemos distancia ultrasonico


 
     if(IR_front < 50) {
        BACKWARD(255);

     } else if (IR_back < 50) {
        FORWARD(255);

     } else if (distance <= 60) {
        FORWARD(255);

     } else {
       search();
            
     }

//Debugging
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  Serial.println("IR front :");
  Serial.println(IR_front); 
  Serial.println("IR back :");
  Serial.println(IR_back);  
 

} 



//FUNCIONES PARA CONTROL DE MOTORES//------
void FORWARD (int Speed){
  //FUNCION AVANZAR
  analogWrite(enAPin, Speed);  // Set motor A speed
  analogWrite(enBPin, Speed);  // Set motor B speed
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}//--------------------------------------------
void BACKWARD (int Speed){
  //FUNCION DE RETROCESO
  analogWrite(enAPin, Speed);  // Set motor A speed
  analogWrite(enBPin, Speed);  // Set motor B speed
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}//--------------------------------------------
void ROTATE (int Speed)
{
  //FUNCION DE ROTACION 
  analogWrite(enAPin, Speed);  // Set motor A speed
  analogWrite(enBPin, Speed);  // Set motor B speed
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}//--------------------------------------------
void Stop(){
  //FUNCION DE PARADA DE MOTORES
  analogWrite(enAPin, 0);  // Set motor A speed
  analogWrite(enBPin, 0);  // Set motor B speed
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
//FUNCION DE BUSQUEDA, ROTAR(100)
void search(){
  ROTATE(100);



}


