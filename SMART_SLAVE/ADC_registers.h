#ifndef ADC_REGISTERS_H
#define ADC_REGISTERS_H


#define ADMUX                *((volatile u8*)0x27)  //ADC multiplexer selection register
#define ADMUX_REFS1          7                      //Reference selection bit1
#define ADMUX_REFS0          6                      //Reference selection bit0
#define ADMUX_ADLAR          5                      //ADC left adjust result


#define ADCSRA               *((volatile u8*)0x26)  //ADC control and status registers
#define ADCSRA_ADEN          7                      //ADC enable 
#define ADCSRA_ADSC          6                      //Start conversion 
#define ADCSRA_ADATE         5                      //Auto trigger enable
#define ADCSRA_ADIF          4                      //Interrupt Flag
#define ADCSRA_ADIE          3                      //Interrupt Enable
#define ADCSRA_ADPS2         2                      //Prescaler bit2 
#define ADCSRA_ADPS1         1                      //Prescaler bit1 
#define ADCSRA_ADPS0         0                      //Prescaler bit0 

#define ADCH                 *((volatile u8*)0x25)  //ADC high register
#define ADCL                 *((volatile u8*)0x24)  //ADC low register

#define ADC_DIGITAL          *((volatile u16*)0x24)

#endif
