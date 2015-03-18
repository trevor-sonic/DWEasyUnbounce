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

//-----------------------------------------------
typedef void (*callbackFunction)(void);
//-----------------------------------------------

class DWEasyUnbounce
{
    
public:
	DWEasyUnbounce(uint8_t pinNo);
    void setup();
    void check();
    void setPressHandler        ( callbackFunction theFunction);
    void setReleaseHandler      ( callbackFunction theFunction);
    void setToggleMode			(bool mode);
    
    
private:
    uint8_t     _pinNo;
    void        (*_pressHandler)    (void);
    void        (*_releaseHandler)  (void);
    void        (*_toggleOnHandler) (void);
    void        (*_toggleOffHandler)(void);
    
    bool		_toggleMode;
    bool        _buttonState;
    bool        _lastButtonState;

    unsigned long _lastDebounceTime;
    unsigned long _debounceDelay;
    
    bool        _toggleState;
};

#endif
