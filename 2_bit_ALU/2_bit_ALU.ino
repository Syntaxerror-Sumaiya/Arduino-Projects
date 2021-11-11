int a0, a1, b0, b1, c_out, s0, s1, s2, f0, f1;
void setup(){
//put your setup code here,to run once:

pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);

pinMode(10,INPUT);
pinMode(9,INPUT);
pinMode(8,INPUT);
pinMode(7,INPUT);
pinMode(6,INPUT);
pinMode(5,INPUT);
pinMode(4,INPUT);
  
}
void loop(){
a0 = digitalRead(10);
a1 = digitalRead(9);
b0 = digitalRead(8);
b1 = digitalRead(7);
s0 = digitalRead(6);
s1 = digitalRead(5);
s2 = digitalRead(4);

if ((s2 == 0 && s1 == 0 && s0 == 0)|| (s2 == 1 && s1 == 1 && s0 == 1)){
c_out = 0;

digitalWrite(13, a0);
digitalWrite(12, a1);
digitalWrite(11, c_out);
}
else if (s2 == 0 && s1 == 0 && s0 == 1){

f0 = a0 ^ 1;
int cin = a0 & 1;
f1 = cin ^ a1;
c_out = cin & a1;

digitalWrite(13, f0);
digitalWrite(12, f1);
digitalWrite(11, c_out);
 
}

else if (s2 == 0 && s1 == 1 && s0 == 0){

f0 = a0 ^ b0;
int cin = a0 & b0;
f1 = cin ^ a1 ^ b1;
c_out = (cin & a1) | (b1 & a1) | (cin & b1) ;

digitalWrite(13, f0);
digitalWrite(12, f1);
digitalWrite(11, c_out);
}

else if (s2 == 0 && s1 == 1 && s0 == 1){
int p = 1;
f0 = a0 ^ b0 ^ p;
int cin = (a0 & b0) | (p ^ b0) | (a0 ^ p);
f1 = cin ^ a1 ^ b1;
c_out = (cin & a1) | (b1 & a1) | (cin & b1) ;

digitalWrite(13, f0);
digitalWrite(12, f1);
digitalWrite(11, c_out);
}

else if (s2 == 1 && s1 == 0 && s0 == 0){
b0 = !b0;
b1 = !b1;
f0 = a0 ^ b0;
int cin = a0 & b0;
f1 = cin ^ a1 ^ b1;
c_out = (cin & a1) | (b1 & a1) | (cin & b1) ;

digitalWrite(13, f0);
digitalWrite(12, f1);
digitalWrite(11, c_out);
}

else if (s2 == 1 && s1 == 0 && s0 == 1){
b0 = !b0;
b1 = !b1;
int p = 1;
f0 = a0 ^ b0 ^ p;
int cin = (a0 & b0) | (p ^ b0) | (a0 ^ p );
f1 = cin ^ a1 ^ b1;
c_out = (cin & a1) | (b1 & a1) | (cin & b1) ;

digitalWrite(13, f0);
digitalWrite(12, f1);
digitalWrite(11, c_out);
}
else if (s2 == 1 && s1 == 1 && s0 == 0){
int p = 1;
int d0 = !a0;
f0 = a0 ^ p;
int borrow = d0 & p ;
f1 = a1 ^ borrow;
c_out =  (!a1) & borrow;
digitalWrite(13, f0);
digitalWrite(12, f1);
digitalWrite(11, c_out);
}

}
