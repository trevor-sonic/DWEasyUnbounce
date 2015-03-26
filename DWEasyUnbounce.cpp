//
// File			DWEasyUnbounce.cpp
// Class library header
//
// Details		Press, Relase, Toggle On/Off actions/handlers
//
// Project	 	DWEasyUnbounce for Arduino
//
// Author		Trevor D.BEYDAG
// 				dejaWorks
//
// Date			05/06/14 15:03
// Version		1.1
//
// Copyright	Trevor D. BEYDAG, 2014
// License	    Freware for personal use and education.
//
// See			ReadMe.txt for references
//


// Library header
#include "DWEasyUnbounce.h"

// Code
DWEasyUnbounce::DWEasyUnbounce()
{
    _toggleMode	=	false;

    _debounceDelay      =   50;
    _longPressDelay		=	3000;
    _lastDebounceTime   =   millis();
    _lastButtonState    =   false;
    _buttonState        =   false;
    _toggleState        =   false;
    _longPressed		=	false;
}
void DWEasyUnbounce::setup(byte pinNo)
{
	_pinNo	=	pinNo;
    pinMode             (_pinNo, INPUT);
}
void DWEasyUnbounce::setPressHandler(  callbackFunction theFunction)
{
    _pressHandler       =   theFunction;
}
void DWEasyUnbounce::setReleaseHandler(  callbackFunction theFunction  )
{
    _releaseHandler     =   theFunction;
}
void DWEasyUnbounce::setPressLongHandler(  callbackFunction theFunction)
{
    _pressLongHandler       =   theFunction;
}
void DWEasyUnbounce::loop()
{
    uint8_t currentState = digitalRead(_pinNo);
    
    if (currentState != _lastButtonState)
    {
        _lastDebounceTime = millis();
    }

    if ((millis() - _lastDebounceTime) > _debounceDelay)
    {
        if (currentState != _buttonState)
        {
        	_buttonState 	= 	currentState;

            if(_toggleMode)
            {
            	if( !_buttonState && !_longPressed)
				{
            		if(_toggleState)
					{
            			if(_releaseHandler) _releaseHandler();
            			_toggleState	=	false;
					}
            		else
            		{
            			if(_pressHandler) _pressHandler  ();
            			_toggleState	=	true;
            		}
				}

            }
            else
            {
            	if( _buttonState && _pressHandler)   _pressHandler  ();
				if(!_buttonState && _releaseHandler && !_longPressed) _releaseHandler();

            }

            _longPressed	=	false;
        }
    }
    if ((millis() - _lastDebounceTime) > _longPressDelay && currentState==true && !_longPressed)
    {

    	if(_pressLongHandler)
    	{
    		_pressLongHandler	();
			_longPressed	=	true;
    	}
    }
    
    _lastButtonState = currentState;
}
void DWEasyUnbounce::setToggleMode(bool mode)
{
    _toggleMode		=   mode;
}
