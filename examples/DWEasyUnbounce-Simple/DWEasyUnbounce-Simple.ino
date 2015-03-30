#include <DWEasyUnbounce.h>

//Button connected on Pin 4
DWEasyUnbounce btn;

//The setup function is called once at startup of the sketch
void setup()
{        
        //Led pin to test button
	pinMode(13,OUTPUT);
        pinMode(3,OUTPUT);
        pinMode(4,OUTPUT);

	digitalWrite(13,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);

        btn.setup(6);
	btn.setPressHandler(onPress);
        btn.setDoublePressHandler(onDoublePress);
        btn.setPressLongHandler(onLongPress);        
	btn.setReleaseHandler(onRelease);
        
        //Change this to "true" to convert the button "toggle button"
	btn.setToggleMode(false);
}

void loop()
{
	btn.loop();
}
void onDoublePress()
{

    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(4,LOW);
	
}
void onPress()
{
	digitalWrite(13,HIGH);
}
void onRelease()
{
	digitalWrite(13,LOW);
}
void onLongPress()
{
	digitalWrite(3,HIGH);
}
