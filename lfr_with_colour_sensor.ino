#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int frequency = 0;

const int h_speed = 200; // high
const int m_speed = 150; // medium
const int l_speed = 100; // low
const int z_speed = 0;   // zero
const int motor_r_red = 9;  const int motor_r_blk = 10;
const int motor_l_red = 11; const int motor_l_blk = 12;
const int color_sen = A1;
int s[4];// sensor index array

void color();
void lfr();

void setup()
{
  for (int i = 1; i < 4; i++)
    pinMode(i + 40, INPUT);
  pinMode (motor_r_red, OUTPUT); //right motors
  pinMode (motor_r_blk, OUTPUT); //right motors
  pinMode (motor_l_red, OUTPUT); //left motors
  pinMode (motor_l_blk, OUTPUT); //left motors
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);


  /* D = Digital
    vcc > 5v
    GND > GND
    SO > D3
    S1 > D4
    S2 > D5
    S3 > D6
    OUT > D2
  */

}
void loop() {
  lfr();
  color();
}

void color() {
  int RGBvalue[2];
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25, 72, 255, 0);
  RGBvalue[0] = frequency;

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30, 90, 255, 0);
  RGBvalue[1] = frequency;
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25, 70, 255, 0);
  RGBvalue[2] = frequency;

  if (RGBvalue[0] > 150 && RGBvalue[1] < 150 && RGBvalue[2] < 150) { //Red
    delay(5000);
    lfr(); lfr(); lfr(); lfr(); lfr(); lfr();
  }
  else if (RGBvalue[0] < 150 && RGBvalue[1] > 150 && RGBvalue[2] < 150) { //green
    delay(3000);
    lfr(); lfr(); lfr(); lfr(); lfr(); lfr();
  }
  else if (RGBvalue[0] < 150 && RGBvalue[1] < 150 && RGBvalue[2] > 150) { //blue
    delay(7000);
    lfr(); lfr(); lfr(); lfr(); lfr(); lfr();
  }
}
void lfr() {
  //ir sensor signal reading
  s[0] = digitalRead(1);
  s[1] = digitalRead(2);
  s[2] = digitalRead(3);

  if (s[0] == 1 && s[1] == 0 && s[2] == 1)
  { //forward
    analogWrite(motor_r_red, m_speed);
    analogWrite(motor_r_blk, z_speed);
    analogWrite(motor_l_red, m_speed);
    analogWrite(motor_l_blk, z_speed);
  }

  else if (s[0] == 0 && s[1] == 0 && s[2] == 0)
  { //Slow forward
    analogWrite(motor_r_red, l_speed);
    analogWrite(motor_r_blk, z_speed);
    analogWrite(motor_l_red, l_speed);
    analogWrite(motor_l_blk, z_speed);
  }

  else if (s[0] == 1 && s[1] == 0 && s[2] == 0)
  { //Right
    analogWrite(motor_r_red, l_speed);
    analogWrite(motor_r_blk, z_speed);
    analogWrite(motor_l_red, h_speed);
    analogWrite(motor_l_blk, z_speed);
  }

  if (s[0] == 1 && s[1] == 1 && s[2] == 0)
  { //RIGHT HARD
    analogWrite(motor_r_red, z_speed);
    analogWrite(motor_r_blk, l_speed);
    analogWrite(motor_l_red, h_speed);
    analogWrite(motor_l_blk, z_speed);
  }

  else if (s[0] == 0 && s[1] == 0 && s[2] == 1)
  { // Left
    analogWrite(motor_r_red, h_speed);
    analogWrite(motor_r_blk, z_speed);
    analogWrite(motor_l_red, l_speed);
    analogWrite(motor_l_blk, z_speed);
  }
  else if (s[0] == 0 && s[1] == 1 && s[2] == 1)
  { //LEFT HARD
    analogWrite(motor_r_red, h_speed);
    analogWrite(motor_r_blk, z_speed);
    analogWrite(motor_l_red, z_speed);
    analogWrite(motor_l_blk, l_speed);
  }
  else if (s[0] == 1 && s[1] == 1 && s[2] == 1)
  { //Reverse
    analogWrite(motor_r_red, l_speed);
    analogWrite(motor_r_blk, z_speed);
    analogWrite(motor_l_red, l_speed);
    analogWrite(motor_l_blk, z_speed);
    delay(10);
  }

}




