/* IEEE RAS 1ST WORKSHOP 7/9/18
 * FUNCTIONS COVERED - 
 * pinMode(pinNumber, MODE);
 * digitalWrite(pinNumber, value);
 * analogWrite(pinNumber, value);
 * delay(time);
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
 
  // blink for 500 milliseconds
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);

  // fade
  for (i=0 ; i<=255 ; i++){
    analogWrite(13, i);
    delay(10);
  }
  for (i=0 ; i<=255 ; i++){
    analogWrite(13, 255-i);
    delay(10);
  }
}
