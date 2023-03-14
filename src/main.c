#include <nanolib.h>
#include <extraperrylib.h>

#include <avr/io.h>
#include <util/delay.h>

int main()
{
  analogInit();
  init_block_USART0();

  init_input_GPIO(D3, PULLUP);
  init_output_GPIO(D7);

  int count = 0;

  while(1) {

    if (count >= 100) {
      printf("------------------------\n");
      checkPotentiometerForSerial(A0);
      checkPotentiometerForSerial(A1);
      count = 0;
    }
    
    checkButtonForLed(D3, D7);

    _delay_ms(10);
    count++;
  }
}