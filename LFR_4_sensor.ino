void setup() {
  // put your setup code here, to run once:
  for (int i=1;i<5;i++)
  {
    pinMode(i,INPUT);    
  }
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);
  pinMode (12,OUTPUT);
  
}
int s[4];
void loop() {
  // put your main code here, to run repeatedly:
 /*int*/ s[0]=digitalRead(1);
 /*int*/ s[1]=digitalRead(2);
 /*int*/ s[2]=digitalRead(3);
 /*int*/ s[3]=digitalRead(4);

/*switch(ch)/
 {
     case  : //back
     case 1 : // 
 }   
 */ 

 if(s[0]==1&&s[3]==1)
 {//forward
    digitalWrite(9,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
  }
 

 
 if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0)
  {//RIGHT HARD
    digitalWrite(9,LOW);
    digitalWrite(12,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
  }
 
 if(s[2]==1&&s[3]==1)
  {//RIGHT HARD
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(12,HIGH);
   }

 
 if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1)
  {//RIGHT HARD
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(12,HIGH);
  }

  if(s[1]==1&&s[2]==1&&s[3]==1)
  {//RIGHT HARD
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(12,HIGH);
  }
 if(s[3]==1)
  {//RIGHT HARD
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(12,HIGH);
    }
if(s[0]==1&&s[2]==1&&s[3]==1)
  {//LEFT HARD
    digitalWrite(12,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
 
 if(s[0]==1&&s[1]==1)
 {//LEFT HARD
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(12,LOW);
  }
 
 if(s[0]==1&&s[1]==1&&s[2]==1)
  {//LEFT HARD
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(12,LOW);
  }

 if(s[0]==1)
  {//LEFT HARD
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(12,LOW);
  }
 if(s[0]==1&&s[1]==1&&s[3]==1)
  {//LEFT HARD
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(12,LOW);
  }
 
 /*if(ctr==4||ctr==8||ctr==12||ctr==15||ctr==14)
 {
    //right
  }
 if(ctr==1||ctr==2||ctr==3)

 if (ctr==)
 */
}

