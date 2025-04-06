/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"


int main(void)
{
  DAC_1_Start();
 DAC_2_Start();
 DAC_1_SetRange(4);
DAC_2_SetRange(4);
    CyGlobalIntEnable;

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {

    if(S2_Read()==0){
    DAC_2_SetValue(127);
    }
    if(S2_Read()==1){
    DAC_2_SetValue(190);
    }
   if(S2_Read()==2){
    DAC_2_SetValue(127);
    }
    if(S2_Read()==3){
    DAC_2_SetValue(63);
    }
    if(S2_Read()==4){
    DAC_2_SetValue(255);
    }
    if(S2_Read()==5){
    DAC_2_SetValue(255);
    }
    if(S2_Read()==6){
    DAC_2_SetValue(0);
    }
    if(S2_Read()==7){
    DAC_2_SetValue(0);
    }
        
        
                if(S1_Read()==0){
    DAC_1_SetValue(190);
    }
         if(S1_Read()==1){
    DAC_1_SetValue(127);
    }
                if(S1_Read()==2){
    DAC_1_SetValue(63);
    }
                        if(S1_Read()==3){
    DAC_1_SetValue(127);
    }
                        if(S1_Read()==4){
    DAC_1_SetValue(255);
    }
                                if(S1_Read()==5){
    DAC_1_SetValue(0);
    }
                if(S1_Read()==6){
    DAC_1_SetValue(0);
    }
                        if(S1_Read()==7){
    DAC_1_SetValue(255);
    }                   
        }

    


                                                    
  
        /*    
    
    
                if(S2_Read()==0){
    DAC_2_SetValue(127);
    }
                              if(S2_Read()==1){
    DAC_2_SetValue(190);
    }
                                          if(S2_Read()==2){
    DAC_2_SetValue(190);
    }
                                                      if(S2_Read()==3){
    DAC_2_SetValue(255);
    }
                                                                  if(S2_Read()==4){
    DAC_2_SetValue(63);
    }
                                                                              if(S2_Read()==5){
    DAC_2_SetValue(0);
    }
                                                                                          if(S2_Read()==6){
    DAC_2_SetValue(127);
    }
                                                                                                      if(S2_Read()==7){
    DAC_2_SetValue(63);
    }
    VDAC8_2_Start(); 
    VDAC8_2_RANGE_4V;
    VDAC8_2_SetValue(255); Place your application code here. */
    }


/* [] END OF FILE */
