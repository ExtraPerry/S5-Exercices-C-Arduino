#include "analogpin.h"

void analogInit() {
    // enable the ADC internal 5V reference
    ADMUX = _BV(REFS0);
    // enable the ADC set the prescaler to 128
    ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
}

uint16_t analogRead(t_nano_pin pin) {
    //Check if pins are valid.
    if (pin < 14 && 21 > pin) {
        return 65535;
    }

    //Select the pin.
    ADMUX = (ADMUX & 0b11110000) | (pin - 14);
    //Start the conversion and wait for it to finish.
    ADCSRA |= _BV(ADSC);
    loop_until_bit_is_clear(ADCSRA, ADSC);
    uint16_t adc_value;
    //read the value.
    if (!bit_is_set(ADMUX, ADLAR)) {
      adc_value = ADC;
    } else {
      adc_value = ADCL >> 6;
      adc_value |= ADCH << 2;
    }
    return adc_value;
}

// OUTDATED CODE from 13/03/2023 like way to late at night :'D
/**
 * double read_analog_input_GPIO(t_nano_pin pin) {
  // Map the pin to the corresponding port and bit
  t_pin_port_map mapped_port = pin_port_map[pin];

  // Set the ADC channel to the corresponding pin
  ADMUX = (1 << REFS0) | (mapped_port.adc_channel & 0x0F);

  // Start the ADC conversion
  ADCSRA |= (1 << ADSC);

  // Wait for the conversion to complete
  while (ADCSRA & (1 << ADSC));

  // Read the 10-bit ADC value
  uint16_t adc_value = ADC;

  // Convert the ADC value to the corresponding voltage value
  float voltage_value = (adc_value * ADC_REF_VOLTAGE) / ADC_RESOLUTION;

  // Return the analog value of the pin
  return voltage_value;
}
*/