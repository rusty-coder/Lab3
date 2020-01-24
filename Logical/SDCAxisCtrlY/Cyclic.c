
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	gAxis_Y_EncIf.iLifeCnt++; 
	gAxis_Y_DiDoIf.iLifeCntDriveEnable++;
	gAxis_Y_DiDoIf.iLifeCntDriveReady++; 
	gAxis_Y_DiDoIf.iLifeCntNegHwEnd++; 
	gAxis_Y_DiDoIf.iLifeCntPosHwEnd++; 
	gAxis_Y_DiDoIf.iLifeCntReference++; 
	gAxis_Y_DrvIf.iLifeCnt++; 
	
	gAxis_Y_EncIf.iActTime = (INT)AsIOTimeCyclicStart();
	gAxis_Y_EncIf.iActPos = axis_Y.counter;
	
	gAxis_Y_DiDoIf.iPosHwEnd = axis_Y.endswitch_a_reached;
	gAxis_Y_DiDoIf.iNegHwEnd = axis_Y.endswitch_b_reached;
	
	//coil_pwm_value = coil_powered?32767:0;
	if(coil_powered)
		coil_pwm_value = 32767;
	else
		coil_pwm_value = 0;
	
	//fb_controller.e = 100 * 6500.0 / 32767 - axis_X.speed; //6500.0 максимльня скорость в метках в секунду
	fb_controller.e = gAxis_Y_DrvIf.oSetPos * 6500 / 32767 - axis_Y.speed; //6500.0 максимльня скорость в метках в секунду
	FB_Regulator(&fb_controller); // передать значение в регулятор
	axis_Y.u = fb_controller.u;
	
	//axis_X.u = 18;
	
	FB_Axis(&axis_Y);
}
