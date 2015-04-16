//
// File			DWEasyUnbounce.h
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

#include "Arduino.h"
#ifndef DWEasyUnbounce_h
#define DWEasyUnbounce_h

#define GND_ON_PRESS      1
#define VCC_ON_PRESS      0

//-----------------------------------------------
typedef void (*functionPointer)(void);
//-----------------------------------------------

class DWEasyUnbounce
{
    
public:
	DWEasyUnbounce();
    void setup					( byte pinNo );
    void loop					();
    void setDoublePressHandler        ( functionPointer theFunction);
    void setPressHandler        ( functionPointer theFunction);
    void setReleaseHandler      ( functionPointer theFunction);
    void setPressLongHandler    ( functionPointer theFunction);
    void setToggleMode			( bool mode );
    void setButtonConnection    ( bool conn );
    
    
private:
    uint8_t     _pinNo;
    bool        _buttonDefaultConnection;
    void        (*_doublePressHandler)	(void);
    void        (*_pressHandler)    	(void);
    void        (*_releaseHandler)  	(void);
    void        (*_pressLongHandler)	(void);

    void        (*_toggleOnHandler) 	(void);
    void        (*_toggleOffHandler)	(void);
    
    bool		_toggleMode;
    bool        _buttonState;
    bool        _lastButtonState;

    unsigned long	_lastDebounceTime;
    unsigned long	_lastPressTime;
    byte			_debounceDelay;
    byte			_doublePressDelay;
    unsigned int	_longPressDelay;
    bool			_longPressed;
    bool 			_doublePressed;
    bool        	_toggleState;
};

#endif
