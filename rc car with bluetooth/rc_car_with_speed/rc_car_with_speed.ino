
   int motorA1  = 5;
   int motorA2  = 6;
   int motorB1  = 9;
   int motorB2  = 10;
   int buzzer  = 8;   
   int light1  = 12;
   int light2  = 13;
   int light3  = 11;
   int state;
   int vSpeed;
   char ch;

void setup() {

    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(light1, OUTPUT); 
    pinMode(light2, OUTPUT);
    pinMode(light3, OUTPUT);   
    pinMode(buzzer, OUTPUT);  
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {

  //Save income data to variable 'state'
    if(Serial.available() > 0){     
      state = Serial.read();
      ch = state;
     // Serial.print("state:");Serial.print(state);
     // Serial.print(" ch:");Serial.println(ch);
    }


    if(state == '0')
     vSpeed = 0;
    if(state == '1')
     vSpeed = 120;
    if(state == '2')
     vSpeed = 140;
    if(state == '3')
     vSpeed = 160;
    if(state == '4')
     vSpeed = 180;
    if(state == '5')
     vSpeed = 200;
    if(state == '6')
     vSpeed = 210;
    if(state == '7')
     vSpeed = 220;
    if(state == '8')
     vSpeed = 230;
    if(state == '9')
     vSpeed = 240;
    if(state == 'q')
     vSpeed = 255;
     

  /***********************Forward****************************/
  //If state is equal with number 'F', car will go forward!
    if (state == 'F') {
      analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed);
      analogWrite(motorB1, 0);      analogWrite(motorB2, vSpeed);

    }  
  
  /***********************Backward****************************/
  //If state is equal with number 'B', car will go backward
    else if (state == 'B') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0); 
      analogWrite(motorB1, vSpeed); analogWrite(motorB2, 0);

    }

   /***************************Right*****************************/
  //If state is equal with number 'R', wheels will turn right
    else if (state == 'R') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0); 
      analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 

    }
    /***************************Left*****************************/
  //If state is equal with number 'L', wheels will turn left
    else if (state == 'L') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
      analogWrite(motorB1, vSpeed); analogWrite(motorB2,0); 

    }
  /***************************Stop*****************************/
  //If state is equal with number 'S', stop the car
    else if (state == 'S') {
      analogWrite(motorA1, 0); analogWrite(motorA2, 0);  
      analogWrite(motorB1, 0); analogWrite(motorB2, 0);
    }
    
  /***************************light1*****************************/
  //If state is equal with letter 'W', light1 turn on
    if (state == 'w') {
      digitalWrite(light1, HIGH); 
    }
    if (state == 'W') {
      digitalWrite(light1, LOW); 
    }
    
  /***************************light2*****************************/
  //If state is equal with letter 'U', light2 turn on
    if (state == 'u') {
      digitalWrite(light2, HIGH); 
    }
    if (state == 'U') {
      digitalWrite(light2, LOW); 
    }

  /***************************light3*****************************/
  //If state is equal with letter 'X', light3 turn on
    if (state == 'x') {
      digitalWrite(light3, HIGH); 
    }
    if (state == 'X') {
      digitalWrite(light3, LOW); 
    }
    
  /***************************buzzer*****************************/
  //If state is equal with letter 'N', buzzer turn on
   if (state == 'v') {
      digitalWrite(buzzer, HIGH); 
    }
    if (state == 'V') {
      digitalWrite(buzzer, LOW); 
    }

}
