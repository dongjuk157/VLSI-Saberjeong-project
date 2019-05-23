int adc[10]={2,3,4,5,6,7,8,9,10,11};
int X1 = 0; // x direction -> 2,3
int Y1 = 1; // y direction -> 6,7
int SW1 = 12; // Push Button -> 10
int X2 = 2; // x direction -> 4,5
int Y2 = 3; // y direction -> 8,9
int SW2 = 13; // Push Button -> 11



void setup() {
  Serial.begin(9600);
  pinMode(SW1,INPUT);  pinMode(SW2,INPUT);
  for(int i=0;i<10;i++){  pinMode(adc[i],OUTPUT);  }
}

void loop() {
    int vrx[2] = {analogRead(X1),analogRead(X2)};
    int vry[2] = {analogRead(Y1),analogRead(Y2)};
    int vrs[2] = {digitalRead(SW1),digitalRead(SW2)};  
   
    Serial.print("vrx[0]: ");         Serial.print(vrx[0]);
    Serial.print("|   vry[0]: ");     Serial.print(vry[0]);
    Serial.print("|   vrs[0]: ");     Serial.print(vrs[0]);
    Serial.print("|   vrx[1]: ");     Serial.print(vrx[1]);
    Serial.print("|   vry[1]: ");     Serial.print(vry[1]);
    Serial.print("|   vrs[1]: ");     Serial.println(vrs[1]);
    
    /*for(int i=0;i<2;i++){
      output(vrx[i],vry[i],vrs[i],i);
      }
    */
  delay(100);
}

void output(int x,int y, int sw, int z){
 // if z=0, pin1
 int pin[5];
  if(z){int pin[5]={7,8,9,10,11};} 
    else{int pin[5]={2,3,4,5,6};}
  /* X1 -> pin 2,3 X2 -> pin 7,8*/
  if(x<384){digitalWrite(pin[0],LOW);digitalWrite(pin[1],HIGH);  }// 01
    else if(x>640){digitalWrite(pin[0],HIGH);digitalWrite(pin[1],LOW);  }// 10
    else{digitalWrite(pin[0],LOW);digitalWrite(pin[1],LOW);   }// 00
  /* Y1 -> pin 4,5 Y2 -> pin 9,10*/
  if(y<384){digitalWrite(pin[2],LOW);digitalWrite(pin[3],HIGH);  }// 01
    else if(y>640){digitalWrite(pin[2],HIGH);digitalWrite(pin[3],LOW);  }// 10
    else{digitalWrite(pin[2],LOW);digitalWrite(pin[3],LOW);   }// 00
  /* SW1 -> pin 6 SW2 -> pin 11*/
  if(sw){digitalWrite(pin[4],HIGH);}
    else{digitalWrite(pin[4],LOW);}
}
