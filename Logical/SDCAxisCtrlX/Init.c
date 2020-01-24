
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	//Устанавливаем типы SDC модулей
	gAxis_X_HW.EncIf1_Typ = ncSDC_ENC16;
	gAxis_X_HW.DiDoIf_Typ = ncSDC_DIDO;
	gAxis_X_HW.DrvIf_Typ = ncSDC_DRVSERVO16;
	//Устанавливаем имена переменных
	strcpy(gAxis_X_HW.EncIf1_Name, "gAxis_X_EncIf");
	strcpy(gAxis_X_HW.DrvIf_Name, "gAxis_X_DrvIf");
	strcpy(gAxis_X_HW.DiDoIf_Name, "gAxis_X_DiDoIf");
	//Устанавливаем входы готовности и нормальной работы
	gAxis_X_EncIf.iEncOK = 1;
	gAxis_X_DrvIf.iDrvOK = 1;
	gAxis_X_DrvIf.iStatusEnable = 1;
	gAxis_X_DiDoIf.iDriveReady = 1;
	
	fb_controller.k_p=0.0001;
	fb_controller.k_i=30;
	
	fb_controller.dt=0.002;
	fb_controller.integrator.dt=0.002;
	
	fb_controller.max_abs_value=24;
	
	pwm_period = 200;
	
	enable=1;
}
