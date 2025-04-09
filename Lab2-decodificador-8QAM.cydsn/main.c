#include "project.h"
#include <stdio.h>

#define NUM_POSICIONES 8

uint16 ADCI, ADCQ; // Lectura de ADC

// Valores de salida DAC para los símbolos 8QAM
static const uint8_t dac1_vals[NUM_POSICIONES] = {190, 127,  63, 127, 255,   0,   0, 255};
static const uint8_t dac2_vals[NUM_POSICIONES] = {127, 190, 127,  63, 255, 255,   0,   0};

// Inicializa los DACs
static void Init_DACs(void) {
    DAC_1_Start();
    DAC_2_Start();
    DAC_1_SetRange(4);
    DAC_2_SetRange(4);
}

// Inicializa los ADCs
static void Init_ADCs(void) {
    Opamp_1_Start();
    ADC_1_Start();
    ADC_1_StartConvert();
    ADC_1_IsEndConversion(ADC_1_WAIT_FOR_RESULT);

    Opamp_2_Start();
    ADC_2_Start();
    ADC_2_StartConvert();
    ADC_2_IsEndConversion(ADC_2_WAIT_FOR_RESULT);
}

// Cuantiza el voltaje leído a niveles r1, r2
int8_t cuantizar(float voltaje) {
    if (voltaje <= 0.8) return -4;         // -r2
    else if (voltaje <= 1.6) return -2;    // -r1
  
    else return 4;                        // +r2
}


// Determina el símbolo de acuerdo a I y Q
uint8_t determinar_simbolo(int8_t I, int8_t Q) {
    if (I == 2 && Q == 0) return 0;
    if (I == 0 && Q == 2) return 1;
    if (I == -2 && Q == 0) return 2;
    if (I == 0 && Q == -2) return 3;
    if (I == 4 && Q == 4) return 4;
    if (I == -4 && Q == 4) return 5;
    if (I == -4 && Q == -4) return 6;
    if (I == 4 && Q == -4) return 7;
    return 255;
}

// Envía bits serialmente por un pin: primero d2, luego d1, luego d0
void enviar_serial(uint8_t simbolo) {
    uint8_t d0 = simbolo & 0x01;
    uint8_t d1 = (simbolo >> 1) & 0x01;
    uint8_t d2 = (simbolo >> 2) & 0x01;

    // Enviar bit más significativo primero
    Pin_Serial_Write(d2);
    CyDelay(10);
    Pin_Serial_Write(d1);
    CyDelay(10);
    Pin_Serial_Write(d0);
    CyDelay(10);
    
    
}

int main(void)
{
    CyGlobalIntEnable;

    Init_DACs();
    Init_ADCs();

    for (;;)
    {
        uint8_t pos1 = S1_Read();  // Posición del switch S1
        uint8_t pos2 = S2_Read();  // Posición del switch S2

        if (pos1 < NUM_POSICIONES) {
            DAC_1_SetValue(dac1_vals[pos1]);
        }
        if (pos2 < NUM_POSICIONES) {
            DAC_2_SetValue(dac2_vals[pos2]);
        }

        // Leer valores analógicos
        ADCI = ADC_1_CountsTo_Volts(ADC_1_GetResult16());
        ADCQ = ADC_2_CountsTo_Volts(ADC_2_GetResult16());

        float voltI = ADCI ;
        float voltQ = ADCQ;

        int8_t I = cuantizar(voltI);
        int8_t Q = cuantizar(voltQ);

        // Mapear r2=4V, r1=2V
        if (I == 4 || I == -4) ;  // Mantener
        else if (I == 0) I = 0;
        else I = (I > 0) ? 2 : -2;

        if (Q == 4 || Q == -4) ;
        else if (Q == 0) Q = 0;
        else Q = (Q > 0) ? 2 : -2;

        // Determinar símbolo y enviar serial
        uint8_t simbolo = determinar_simbolo(I, Q);

        if (simbolo != 255) {
            enviar_serial(simbolo);
        }
    }
}

/* [] END OF FILE */
