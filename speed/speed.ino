const int echo1 = 8, Trig = 9,echo2 = 10;
long duration1=0;
long duration2=0;
long s1a=0;
long s1b=0;
long s2a=0;
long s2b=0;
int a=1;
long v1=0;
long v2=0;
long t1=0;
long t2=0;

void setup() {
// initialize serial communication:
Serial.begin(9600);
pinMode(Trig, OUTPUT);
pinMode(echo1, INPUT);
pinMode(echo2, INPUT);
}
void loop()
{
// establish variables for duration of the ping,
// and the distance result in inches and centimeters:
while(1)
{
// The PING))) is triggered by a HIGH pulse of 10 microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
digitalWrite(Trig, LOW);
delayMicroseconds(2);
digitalWrite(Trig, HIGH);
delayMicroseconds(10);
digitalWrite(Trig, LOW);
// The echo pin is used to read the signal from the PING))): a HIGH
// pulse whose duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
duration1 = pulseIn(echo1, HIGH);
duration2 = pulseIn(echo2, HIGH);
if(a==1)
{
// convert the time into a distance
s1a = microsecondsToCentimeters(duration1);
s2a = microsecondsToCentimeters(duration2);
Serial.print(s1a);
Serial.print("s1a");
Serial.println();
Serial.print(s2a);
Serial.print("s2a");
Serial.println();
delay(1000);
a--;
}
else
{s1b = microsecondsToCentimeters(duration1);
s2b = microsecondsToCentimeters(duration2);
Serial.print(s1b);
Serial.print("s1b");
Serial.println();
Serial.println(s2b);
Serial.print("s2b");
Serial.println();
a++;
delay(1000);
}
//v1 = (s1a-s1b);
//v2 = (s2a-s2b);
//t1 = (2*s1b)/v1;
//t2 = (s2b-10)/v2;
}

delay(1000);
}
long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}
