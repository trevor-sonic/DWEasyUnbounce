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

    _debounceDelay      =   30;
    _doublePressDelay	=	160;
    _longPressDelay		=	3000;
    _lastDebounceTime   =   millis();
    _lastButtonState    =   false;
    _buttonState        =   false;
    _toggleState        =   false;
    _longPressed		=	false;
    _doublePressed		=	false;
}
void DWEasyUnbounce::setup(byte pinNo)
{
	_pinNo	=	pinNo;
    pinMode             (_pinNo, INPUT);
}
void DWEasyUnbounce::setPressHandler(  functionPointer theFunction)
{
    _pressHandler       =   theFunction;
}
void DWEasyUnbounce::setDoublePressHandler(  functionPointer theFunction)
{
    _doublePressHandler       =   theFunction;
}
void DWEasyUnbounce::setReleaseHandler(  functionPointer theFunction  )
{
    _releaseHandler     =   theFunction;
}
void DWEasyUnbounce::setPressLongHandler(  functionPointer theFunction)
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

    if (  millis()  > (_lastDebounceTime + _debounceDelay) &&  (currentState != _buttonState) )
    {
		_buttonState 	= 	currentState;

		if(_toggleMode)
		{
			// Toggle Controller
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
					_doublePressed	=	false;
				}

				// TODO Toggle mode: double press does not work
//				if( millis() < _lastPressTime + _doublePressDelay)
//				{
//					if( _buttonState && _doublePressHandler)   _doublePressHandler  ();
//					_doublePressed	=	true;
//				}
//				_lastPressTime	=	millis();
			}

		}
		else
		{

			if( _buttonState && _pressHandler)
			{
				_pressHandler  ();
				_doublePressed	=	false;
			}

			if(!_buttonState && _releaseHandler && !_longPressed && !_doublePressed)
			{
				_releaseHandler();
				_doublePressed	=	false;
			}

			if( millis() < _lastPressTime + _doublePressDelay)
			{
				if( _buttonState && _doublePressHandler)   _doublePressHandler  ();
				_doublePressed	=	true;
			}
			_lastPressTime	=	millis();

		}

		_longPressed	=	false;

    }

    // Long press controller
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
