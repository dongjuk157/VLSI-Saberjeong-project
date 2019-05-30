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
  for(int i=0;i<10;i++){  pinMode(adc[i],OUTPUT); }
  
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

    ////////////////// output  //////////////
      //adc[0]~adc[4]={2,3,4,5,6};
      /* X1 -> pin 2,3*/
      if(vrx[0]<384){       digitalWrite(adc[0],LOW); digitalWrite(adc[1],HIGH);  } // 01 LEFT
        else if(vrx[0]>640){digitalWrite(adc[0],HIGH);digitalWrite(adc[1],LOW);  }  // 10 RIGHT
        else{               digitalWrite(adc[0],LOW); digitalWrite(adc[1],LOW);   } // 00 
      /* Y1 -> pin 4,5*/
      if(vry[0]<384){       digitalWrite(adc[2],LOW); digitalWrite(adc[3],HIGH);  } // 01 UP
        else if(vry[0]>640){digitalWrite(adc[2],HIGH);digitalWrite(adc[3],LOW);  }  // 10 DOWN
        else{               digitalWrite(adc[2],LOW); digitalWrite(adc[3],LOW);   } // 00
      /* SW1 -> pin 6 */
      if(vrs[0]){ digitalWrite(adc[4],HIGH);}
        else{     digitalWrite(adc[4],LOW);}
        
      //adc[5]~adc[6]={7,8,9,10,11};
      /* X2 -> pin 7,8*/
      if(vrx[1]<384){       digitalWrite(adc[5],LOW); digitalWrite(adc[6],HIGH);  } // 01 LEFT
        else if(vrx[1]>640){digitalWrite(adc[5],HIGH);digitalWrite(adc[6],LOW);  }  // 10 RIGHT
        else{               digitalWrite(adc[5],LOW); digitalWrite(adc[6],LOW);   } // 00
      /* Y2 -> pin 9,10*/
      if(vry[1]<384){       digitalWrite(adc[7],LOW); digitalWrite(adc[8],HIGH);  } // 01 UP
        else if(vry[1]>640){digitalWrite(adc[7],HIGH);digitalWrite(adc[8],LOW);  }  // 10 DOWN
        else{               digitalWrite(adc[7],LOW); digitalWrite(adc[8],LOW);   } // 00
      /* SW2 -> pin 11*/
      if(vrs[1]){ digitalWrite(adc[9],HIGH);}
        else{     digitalWrite(adc[9],LOW);}
         
  delay(100);
}
