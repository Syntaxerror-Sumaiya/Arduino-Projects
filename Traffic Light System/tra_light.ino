unsigned char count[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
unsigned char i,j,k;
void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFF;
  DDRB |= 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9, HIGH);
   digitalWrite(10, LOW);
   digitalWrite(11, LOW);
  for(  i = 9; i>0; i--)
  {
  PORTD = count[i];
  delay(1000);
  }
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  for(  j = 5; j>0; j--)
  {
  PORTD = count[j];
  delay(1000);
  }
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  for( k = 9; k>0; k--)
  {
  PORTD = count[k];
  delay(1000);
  }
}
