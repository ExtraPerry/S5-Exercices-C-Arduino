#ifndef board_h
#define board_h

#include <nanolib.h>

//Methodes (Bouton & LED).
void checkButtonForLed(t_nano_pin button, t_nano_pin led);

//Methodes (Potentiometre & Serial).
void checkPotentiometerForSerial(t_nano_pin potentiometer);

#endif