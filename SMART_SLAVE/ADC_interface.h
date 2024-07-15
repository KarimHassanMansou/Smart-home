#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

typedef struct
{
	u8* channel	;
	u16* result;
	u8 size ;
	void (*Notification_func)(void);
}chain_type;

void MADC_INIT (void);
u8 MADC_u8StartConversionSync (u8 copy_u8Chanel);
u8 MADC_u8StartConversionAsync (u8 copy_u8Chanel,  void(*copy_ADCptrtofunc)(void));
u8 MADC_u8StartchainAsync(chain_type * copy_chain);

#endif
