#include "board.h"

//Methodes (Bouton & LED).
void checkButtonForLed(t_nano_pin button_pin, t_nano_pin led_pin) {
  if (read_input_GPIO(button_pin) == LOW) {
    write_output_GPIO(led_pin, HIGH);
  } else {
    write_output_GPIO(led_pin, LOW);
  }
}

//Methodes (Potentiometre & Serial).
void checkPotentiometerForSerial(t_nano_pin potentiometer_pin) {
    if (potentiometer_pin < 14 && 21 > potentiometer_pin) {
        printf("Error : Specified pin is not an analog pin.");
        return;
    }
    int Apin = potentiometer_pin - 14;
    printf("A%d --> volt = %d\n", Apin, analogRead(potentiometer_pin));
}
