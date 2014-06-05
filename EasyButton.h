//
// File			EasyButton.h
// Class library header
//
// Details		Press, Relase, Toggle On/Off actions/handlers
//
// Project	 	EasyButton for Arduino
//
// Author		Trevor D.BEYDAG
// 				dejaWorks
//
// Date			05/06/14 15:03
// Version		1.0
//
// Copyright	© Trevor D. BEYDAG, 2014
// License	    Freware for personal use and education.
//
// See			ReadMe.txt for references
//

#include "Arduino.h"

#ifndef EasyButton_h

#define EasyButton_h


class EasyButton
{
    
public:
    EasyButton(uint8_t pinNo);
    void setup();
    void check();
    void setPressHandler        ( void(*ptr)(void) );
    void setReleaseHandler      ( void(*ptr)(void) );
    void setToggleOnHandler     ( void(*ptr)(void) );
    void setToggleOffHandler    ( void(*ptr)(void) );

    
    
private:
    uint8_t     _pinNo;
    void        (*_pressHandler)    (void);
    void        (*_releaseHandler)  (void);
    void        (*_toggleOnHandler) (void);
    void        (*_toggleOffHandler)(void);
    
    bool        _buttonState;
    bool        _lastButtonState;

    long        _lastDebounceTime;
    long        _debounceDelay;
    
    bool        _toggleState;
};

#endif
