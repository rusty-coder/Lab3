
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
void FB_Motor(struct FB_Motor* inst)
{
	inst->integrator.in = (inst->u / inst->ke - inst->w) * inst->dt / inst->Tm; //integr's in (incoming signal u multipled by 1/ke subtracting w then multipled by dt/Tm)
	
	//inst->integrator.out = inst->w;
	
	FB_Integrator(&(inst->integrator));			//calling integr
	inst->w = inst->integrator.out;				//from 1 integr
	
	inst->integrator.in = inst->w * inst->dt;	//integr's in (incoming signal w multipled by dt)
	
	//inst->integrator.out = inst->phi;
	
	FB_Integrator(&(inst->integrator));			//calling integr
	
	inst->phi = inst->integrator.out; 			//outcoming signal phi
}
