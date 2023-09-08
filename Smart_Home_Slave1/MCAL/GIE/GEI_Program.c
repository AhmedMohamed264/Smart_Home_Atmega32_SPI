#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_Interface.h"


void MGIE_voidEnable()
{
	SET_BIT(SREG, 7);
}

void MGIE_voidDisable()
{
	CLR_BIT(SREG, 7);
}
