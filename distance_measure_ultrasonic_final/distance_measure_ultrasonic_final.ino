
/* HC-SR04
A Simple Modified version of the Ping Sensor Program t
*/
// this constant won't change. It's the pin number
// of the sensor's output / trigger
const int echo = 8, Trig = 9;
void setup() {
// initialize serial communication:
Serial.begin(9600);
pinMode(Trig, OUTPUT);
pinMode(echo, INPUT);
}
void loop()
{
// establish variables for duration of the ping,
// and the distance result in inches and centimeters:
while(1)
{
long duration, inches, cm,a,cm1,s;
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
duration = pulseIn(echo, HIGH);
if(a==1)
{
// convert the time into a distance
//inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
//Serial.print(inches);
//Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(1000);
a--;
}
else
{cm1 = microsecondsToCentimeters(duration);
//Serial.print(inches);
//Serial.print("in, ");
Serial.print(cm1);
Serial.print("cm1");
Serial.println();
a++;
delay(1000);}
}
delay(1000);
}
s=(cm1-cm);
Serial.println(s);
long microsecondsToInches(long microseconds)
{
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}
