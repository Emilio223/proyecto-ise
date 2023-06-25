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
#include <stdio.h> // Para el uso de la función sprintf()
#define CR 0x0D
#define CL 0x0A
#define Newline()     \
    UART_PutChar(CR); \
    UART_PutChar(CL);
char uart_in;
char cadena_uart[100];
char MODO;
char enable_led = '0';

CY_ISR(ISR_Timer1)
{ // timer de 2 segundos para apagar/prender la coneccion dependiendo del PP
    Timer1_ReadStatusRegister();
    if (enable_led == '1')
    { // SI ESTA EN MODO ALARMA, EL LED SE PRENDE(1s).

        if (LED_Read() == 1)
        { // SI ES QUE ESTA PRENDIDO SE APAGA

            LED_Write(0);
        }
        else
        {
            LED_Write(1);
        }
    }
}
CY_ISR(IRQ_UART)
{ // Validado, funciona y lee valores del 1 a 6.
    uart_in = UART_ReadRxData();
    if (!((uart_in >= '1') && (uart_in <= '4')))
    {
        MODO = 0; // se ponen las condiciones de los unicos valores de entrada que se aceptan, de otro modo seguirá teniendo el valor 0
    }
    switch (uart_in)
    {
    case '1':
    {
        MODO = '1';
        break;
    }
    case '2':
    {
        MODO = '2';
        break;
    }
    case '3':
    {
        MODO = '3';
        break;
    }
    case '4':
    {

        MODO = '4';
        break;
    }
    default:
        break;
    }
}

void menu()
{
    sprintf(cadena_uart, "Seleccione una de los MODOS");
    UART_PutString(cadena_uart);
    UART_PutChar(0xA);
    UART_PutChar(0xD);
    sprintf(cadena_uart, "1: Modo Apagado");
    UART_PutString(cadena_uart);
    UART_PutChar(0xA);
    UART_PutChar(0xD);
    sprintf(cadena_uart, "2: Modo Normal");
    UART_PutString(cadena_uart);
    UART_PutChar(0xA);
    UART_PutChar(0xD);
    sprintf(cadena_uart, "3: Modo Peligro");
    UART_PutString(cadena_uart);
    UART_PutChar(0xA);
    UART_PutChar(0xD);
    sprintf(cadena_uart, "4: Modo Alarma");
    UART_PutString(cadena_uart);
}

int main(void)
{
    CyGlobalIntEnable; // Activar interrupciones globales
\
    IRQ_UART_StartEx(IRQ_UART);

    UART_Start();
    CyGlobalIntEnable;

    menu();
    for (;;)
    {
        if (MODO == '1')
        {
            // APAGADO = NO SE HACE NADA
            continue;
        }
        else if (MODO == '2')
        {
            // MODO NORMAL
        }
        else if (MODO == '3')
        {
            // MODO PELIGRO
            // EL AIRBAG SE DESPLIEGA.
            MOTOR1_Write(1);

            // MOTOR 2 SE PARA
            MOTOR2_Write(0);
        }
        else if (MODO == '4')
        {
            // MODO ALAMAR
            BUZZER_Write(1);
            enable_led = '1'; // timer de 2 segundos para apagar/prender la coneccion dependiendo del PP
        }
    }
}
