#include<stdio.h>
#include<wiringPi.h>

int main()
{
	wiringPiSetup();
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(0,OUTPUT);


	digitalWrite(8,HIGH);
	digitalWrite(9,HIGH);
	digitalWrite(7,HIGH);
	digitalWrite(0,HIGH);
	
	
while(1)
	
	{digitalWrite(8,LOW);
	digitalWrite(9,LOW);
	digitalWrite(7,HIGH);
	digitalWrite(0,HIGH);

	delay(5000);
	digitalWrite(8,LOW);
	digitalWrite(9,HIGH);
	digitalWrite(7,LOW);
	digitalWrite(0,HIGH);

	delay(5000);
	digitalWrite(8,LOW);
	digitalWrite(9,HIGH);
	digitalWrite(7,HIGH);
	digitalWrite(0,LOW);

	delay(5000);
}

return 0;
}
