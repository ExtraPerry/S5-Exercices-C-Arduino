#include <nanolib.h>
#include <extraperrylib.h>

#include <avr/io.h>
#include <util/delay.h>

int main()
{
  analogInit();
  init_block_USART0();
  
  while(1) {

    printf("------------------------\n");
    checkPotentiometerForSerial(A0);
    checkPotentiometerForSerial(A1);

    _delay_ms(1000);
  }
}