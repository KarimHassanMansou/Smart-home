
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_registers.h"
#include "ADC_config.h"


void (*ADC_PtrToFunc)(void)=NULL;      //GLOBAL POINTER TO FUNCTION

void MADC_INIT (void)
{
	//AVCC as reference voltage
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLEAR_BIT(ADMUX, ADMUX_REFS1);
	

    #if(Reading == Left_Adjust_Result)
	SET_BIT(ADMUX, ADMUX_ADLAR);
    #elif(Reading == Right_Adjust_Result)
	CLEAR_BIT(ADMUX, ADMUX_ADLAR);
    #endif

	//set Prescaler
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_Prescaler;


	//ADC ENABLE
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u8 MADC_u8StartConversionSync (u8 copy_u8Chanel)
{
	
	ADMUX &= 0b11100000;       //CLEAR the bits which responsible for the channel

	ADMUX |= copy_u8Chanel;  //to assign the channel

	SET_BIT(ADCSRA, ADCSRA_ADSC);  //to start conversion

	while (GET_BIT(ADCSRA, ADCSRA_ADIF) == 0); // POLLING  when conversion completed the flag set to 1

	SET_BIT(ADCSRA, ADCSRA_ADIF);  // TO CLEAR FLAG

   #if (number_of_bits == 8)
	return ADCH;   // as i considered that i read just 8bit (left adjust result)
   #elif (number_of_bits == 10)
	return ADC_DIGITAL ; //as i considered that i read 10bit (right adjust result)
   #endif
}

u8 MADC_u8StartConversionAsync (u8 copy_u8Chanel,  void(*copy_ADCptrtofunc)(void) )
{
	   ADC_PtrToFunc=copy_ADCptrtofunc; //to get the address of ISR

	    ADMUX &= 0b11100000;       //CLEAR the bits which responsible for the channel

		ADMUX |= copy_u8Chanel;  //to assign the channel

		SET_BIT(ADCSRA, ADCSRA_ADSC);  //to start conversion

		SET_BIT(ADCSRA, ADCSRA_ADIE);   //to enable ADC interrupt


   #if (number_of_bits == 8)
	return ADCH;   // as i considered that i read just 8bit (left adjust result)
   #elif (number_of_bits == 10)
	return ADC_DIGITAL ; //as i considered that i read 10bit (right adjust result)
   #endif

}




void __vector_16 (void)
{
	ADC_PtrToFunc();

	CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
}
