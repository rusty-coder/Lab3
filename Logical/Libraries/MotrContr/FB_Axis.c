
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotrContr.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Axis(struct FB_Axis* inst)
{
	
	/*
	switch(inst->state)
	{
		case unknown:
			if (inst->endswitch_a_reached || inst->button_a)
				inst->state = A;
			
			if (inst->endswitch_b_reached || inst->button_b)
				inst->state = B;
			
			if (inst->direction)								//
				inst->state = A_dir;
			
			if (!inst->direction)								//
				inst->state = B_dir;
			
			break;
		
		case B:
			inst->pwm_value = 0;
			inst->reset_error = 1;
			
			if (!inst->button_b && !inst->endswitch_b_reached)
				inst->state = B_dir;
			
			if (inst->direction)								//
				inst->state = A_dir;
			break;
		
		case A:
			inst->pwm_value = 0;
			inst->reset_error = 1;
			
			if (!inst->button_a && !inst->endswitch_a_reached)
				inst->state = A_dir;
			
			if (!inst->direction)								//
				inst->state = B_dir;
			break;
		
		case A_dir:
			inst->pwm_value = inst->u / 24.0 * 32767;			//шим соответственно напряжению с регулятора
			inst->reset_error = 0;
			inst->speed = inst->u / 24.0 * 6500.0;
			
			if (inst->endswitch_a_reached || inst->button_a)
				inst->state = A;
			
			if (!inst->direction)								//
				inst->state = B_dir;
			
			break;
		
		case B_dir:
			inst->pwm_value = -inst->u / 24.0 * 32767;			//шим соответственно напряжению с регулятора
			inst->reset_error = 0;
			inst->speed = -inst->u / 24.0 * 6500.0;
			
			if (inst->endswitch_b_reached || inst->button_b)
				inst->state = B;
			
			if (inst->direction)								//
				inst->state = A_dir;
			
			break;
	}
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*if (inst->endswitch_a_reached || inst->endswitch_b_reached)
	{
		inst->reset_error=1;
	}
	else
	{*/
		inst->pwm_value= inst->u / 24.0 * 32767;//шим соответственно напряжению с регулятора
		//inst->reset_error=0;
	///}
	inst->speed = inst->u / 24.0 * 6500.0;
}
