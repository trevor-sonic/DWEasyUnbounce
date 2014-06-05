//
// EasyButton.cpp 
// Class library C++ code
// ----------------------------------
// Project 		EasyButton for Arduino
//
// Created by 	Trevor D. BEYDAG, 05/06/14 15:03
// 				dejaWorks
//
// Copyright 	© Trevor D. BEYDAG, 2014
// License     Freware for personal use and education.
//
// See 			EasyButton.h and ReadMe.txt for references
//


// Library header
#include "EasyButton.h"

// Code
EasyButton::EasyButton(uint8_t pinNo)
{
    _pinNo  =   pinNo;
}
void EasyButton::setup()
{
    pinMode             (_pinNo, INPUT);
    digitalWrite        (_pinNo, HIGH);
    _debounceDelay      =   50;
    _lastDebounceTime   =   millis();
    _lastButtonState    =   HIGH;
    _buttonState        =   LOW;
    _toggleState        =   LOW;
}
void EasyButton::setPressHandler(  void (*ptr)(void)  )
{
    _pressHandler       =   ptr;
}
void EasyButton::setReleaseHandler(  void (*ptr)(void)  )
{
    _releaseHandler     =   ptr;
}
void EasyButton::setToggleOffHandler(  void (*ptr)(void)  )
{
    _toggleOnHandler    =   ptr;
}
void EasyButton::setToggleOnHandler(  void (*ptr)(void)  )
{
    _toggleOffHandler   =   ptr;
}
void EasyButton::check()
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
            
            if(!currentState && _pressHandler)   _pressHandler  ();
            if(currentState  && _releaseHandler) _releaseHandler();
            
            _buttonState = currentState;

            if (_buttonState == HIGH)
            {
                _toggleState = !_toggleState;
                
            }
        }
    }
    
    if (_toggleState == HIGH)
    {
        if (_toggleOnHandler) _toggleOnHandler();
        
    }
    else
    {
        if (_toggleOffHandler) _toggleOffHandler();
    }

    _lastButtonState = currentState;
}