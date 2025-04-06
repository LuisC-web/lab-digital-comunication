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
#include <stdio.h>

#define NUM_POSICIONES 8
uint16 ADCI, ADCQ; //Lectura del ADC
// Mapas de valores para cada posición de los switches
static const uint8_t dac1_vals[NUM_POSICIONES] = {190, 127,  63, 127, 255,   0,   0, 255};
static const uint8_t dac2_vals[NUM_POSICIONES] = {127, 190, 127,  63, 255, 255,   0,   0};

static void Init_DACs(void)
{
    DAC_1_Start();
    DAC_2_Start();
    DAC_1_SetRange(4);
    DAC_2_SetRange(4);
}

static void Init_ADCs(void)
{
    // ADC 1
    Opamp_1_Start();
    ADC_1_Start();
    ADC_1_StartConvert();
    ADC_1_IsEndConversion(ADC_1_WAIT_FOR_RESULT);
    // ADC 2
    Opamp_2_Start();
    ADC_2_Start();
    ADC_2_StartConvert();
    ADC_2_IsEndConversion(ADC_2_WAIT_FOR_RESULT);
}

int main(void)
{
    CyGlobalIntEnable;

    Init_DACs();
    Init_ADCs();

    for (;;)
    {
        uint8_t pos1 = S1_Read();  // Lee posición del switch S1 (0–7)
        uint8_t pos2 = S2_Read();  // Lee posición del switch S2 (0–7)

        // Actualiza DAC1 según S1
        if (pos1 < NUM_POSICIONES) {
            DAC_1_SetValue(dac1_vals[pos1]);
        }

        // Actualiza DAC2 según S2
        if (pos2 < NUM_POSICIONES) {
            DAC_2_SetValue(dac2_vals[pos2]);
        }
        ADCI=ADC_1_CountsTo_mVolts(ADC_1_GetResult16());
        ADCQ=ADC_2_CountsTo_mVolts(ADC_2_GetResult16());
        

        
    }
}

/* [] END OF FILE */
