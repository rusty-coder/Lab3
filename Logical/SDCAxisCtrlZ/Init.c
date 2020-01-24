
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	//Устанавливаем типы SDC модулей
	gAxis_Z_HW.EncIf1_Typ = ncSDC_ENC16;
	gAxis_Z_HW.DiDoIf_Typ = ncSDC_DIDO;
	gAxis_Z_HW.DrvIf_Typ = ncSDC_DRVSERVO16;
	//Устанавливаем имена переменных
	strcpy(gAxis_Z_HW.EncIf1_Name, "gAxis_Z_EncIf");
	strcpy(gAxis_Z_HW.DrvIf_Name, "gAxis_Z_DrvIf");
	strcpy(gAxis_Z_HW.DiDoIf_Name, "gAxis_Z_DiDoIf");
	//Устанавливаем входы готовности и нормальной работы
	gAxis_Z_EncIf.iEncOK = 1;
	gAxis_Z_DrvIf.iDrvOK = 1;
	gAxis_Z_DrvIf.iStatusEnable = 1;
	gAxis_Z_DiDoIf.iDriveReady = 1;
	
	fb_controller.k_p=0.002;
	fb_controller.k_i=0.16;
	
	fb_controller.dt=0.002;
	fb_controller.integrator.dt=0.002;
	
	fb_controller.max_abs_value=24;
	
	pwm_period = 200;
	
	enable=1;
}
