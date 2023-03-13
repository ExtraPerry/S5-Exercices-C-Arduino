#include <nanolib.h>
#include <extraperrylib.h>

#include <util/delay.h>

int main()
{
  init_block_USART0();

  init_input_GPIO(D3, PULLUP);
  init_output_GPIO(D7);

  init_input_GPIO(A0, NO_PULLUP);
  init_input_GPIO(A1, PULLUP);
  
  while(1) {
    double pot1volt = read_analog_input_GPIO(A0);
    t_pin_state pot1state = read_state_input_GPIO(A0);
    double pot2volt = read_analog_input_GPIO(A1);
    t_pin_state pot2state = read_state_input_GPIO(A1);

    printf("volt1 --> volt = %f | state = %s\n", pot1volt, pot1state == HIGH ? "HIGH" : "LOW");
    printf("volt2 --> volt = %f | state = %s\n", pot2volt, pot2state == HIGH ? "HIGH" : "LOW");

    _delay_ms(1000);
  }
}