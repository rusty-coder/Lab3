
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	gAxis_Z_EncIf.iLifeCnt++; 
	gAxis_Z_DiDoIf.iLifeCntDriveEnable++;
	gAxis_Z_DiDoIf.iLifeCntDriveReady++; 
	gAxis_Z_DiDoIf.iLifeCntNegHwEnd++; 
	gAxis_Z_DiDoIf.iLifeCntPosHwEnd++; 
	gAxis_Z_DiDoIf.iLifeCntReference++; 
	gAxis_Z_DrvIf.iLifeCnt++; 
	
	gAxis_Z_EncIf.iActTime = (INT)AsIOTimeCyclicStart();
	gAxis_Z_EncIf.iActPos = axis_Z.counter;
	
	gAxis_Z_DiDoIf.iPosHwEnd = axis_Z.endswitch_a_reached;
	gAxis_Z_DiDoIf.iNegHwEnd = axis_Z.endswitch_b_reached;
	
	//coil_pwm_value = coil_powered?32767:0;
	if(coil_powered)
		coil_pwm_value = 32767;
	else
		coil_pwm_value = 0;
	
	//fb_controller.e = 100 * 6500.0 / 32767 - axis_X.speed; //6500.0 максимльня скорость в метках в секунду
	fb_controller.e = gAxis_Z_DrvIf.oSetPos * 6500 / 32767 - axis_Z.speed; //6500.0 максимльня скорость в метках в секунду
	FB_Regulator(&fb_controller); // передать значение в регулятор
	axis_Z.u = fb_controller.u;
	
	//axis_X.u = 18;
	
	FB_Axis(&axis_Z);
}
