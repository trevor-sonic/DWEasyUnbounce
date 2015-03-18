#include <DWEasyUnbounce.h>

//Button connected on Pin 4
DWEasyUnbounce btn(4);

//The setup function is called once at startup of the sketch
void setup()
{
	pinMode(4, INPUT);
        
        //Led pin to test button
	pinMode(13,OUTPUT);
	digitalWrite(13,LOW);

	btn.setPressHandler(onPress);
	btn.setReleaseHandler(onRelease);
        
        //Change this to "true" to convert the button "toggle button"
	btn.setToggleMode(false);
}

void loop()
{
	btn.loop();
}
void onPress()
{
	digitalWrite(13,HIGH);
}
void onRelease()
{
	digitalWrite(13,LOW);
}
