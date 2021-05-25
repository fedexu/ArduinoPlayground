#ifndef Pins_Espressif_h
#define Pins_Espressif_h

#include <stdint.h>

#define EXTERNAL_NUM_INTERRUPTS 16
#define NUM_DIGITAL_PINS        40
#define NUM_ANALOG_INPUTS       16

#define analogInputToDigitalPin(p)  (((p)<20)?(esp32_adc2gpio[(p)]):-1)
#define digitalPinToInterrupt(p)    (((p)<40)?(p):-1)
#define digitalPinHasPWM(p)         (p < 34)

static const uint8_t LED_BUILTIN = 2;
#define BUILTIN_LED  LED_BUILTIN // backward compatibility
#define LED_BUILTIN LED_BUILTIN

static const uint8_t E_A0 = 36;
static const uint8_t E_A1 = 36;
static const uint8_t E_A2 = 36;
static const uint8_t E_A3 = 36;


// unchecked


#endif /* Pins_Espressif_h */