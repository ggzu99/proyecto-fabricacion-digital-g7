
#include <Ultrasonic.h> //Librería que facilita el uso de sensores ultrasonicos, con ella no es necesario definir los trig and
//echo pin, sino que se usa la notacion Ultrasonic ultrasonic()

//LINK LIBRERIA: https://github.com/ErickSimoes/Ultrasonic/tree/master


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
 ROTATE(200); // Rotacion si (distance < 20){
    Stop();
    while (distance < 20 ) {
    FORWARD(255); 
    distance = ultrasonic.read();
    IR_front = analogRead(IR_sensor_front);
    IR_back = analogRead(IR_sensor_back);
    if ( IR_front > 650 || IR_back > 650 ) { break;}
    delay(10); }
  
  
 if (IR_front < 650 )  // < 650 means white line // aun en testeo estos valores
   {
   Stop();
   delay (50);
   BACKWARD(255);
   delay (500);
   } 
   
 if (IR_back < 650 )  //
   {
   Stop();
   delay (50);
   FORWARD(255);
   delay (500);
   }
   
//Debugging
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  Serial.println("IR front :");
  Serial.println(IR_front); 
  Serial.println("IR back :");
  Serial.println(IR_back);  
 

} //FUNCIONES PARA CONTROL DE MOTORES//------
void FORWARD (int Speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(enAPin, Speed);  // Set motor A speed
  analogWrite(enBPin, Speed);  // Set motor B speed
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}//--------------------------------------------
void BACKWARD (int Speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(enAPin, Speed);  // Set motor A speed
  analogWrite(enBPin, Speed);  // Set motor B speed
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}//--------------------------------------------
void ROTATE (int Speed)
{
  //When we want to let Motor To Rotate ,
  // just void this part on the loop section .
  analogWrite(enAPin, Speed);  // Set motor A speed
  analogWrite(enBPin, Speed);  // Set motor B speed
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}//--------------------------------------------
void Stop(){
  //When we want to  Motor To stop ,
  // just void this part on the loop section .
  analogWrite(enAPin, 0);  // Set motor A speed
  analogWrite(enBPin, 0);  // Set motor B speed
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}