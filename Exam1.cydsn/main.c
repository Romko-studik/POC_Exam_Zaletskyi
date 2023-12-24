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
int readPorts1(){
int a = Out1_1_Read();
int b = Out1_2_Read();
int c = Out1_3_Read();
if(a == 0)return 0;
if(b == 0)return 1;
if(c == 0)return 2;
else return 3;
}
int readPorts2(){
int a = Out2_1_Read();
int b = Out2_2_Read();
int c = Out2_3_Read();
if(a == 0)return 0;
if(b == 0)return 1;
if(c == 0)return 2;
else return 3;
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    
    
    Result_Write(0);
    for(;;)
    {
        CyDelay(500);
        int counter = 0;
        for(int i = 0;i <= 1;i++){
            for(int j = 0; j <=1; j++){
                In1_Write(i);
                In2_Write(j);
                CyDelay(100);
                if(readPorts1() == i*2+j*1)counter++;;
            }
        }
        for(int i = 0;i <= 1;i++){
            for(int j = 0; j <=1; j++){
                In2_2_Write(i);
                In1_2_Write(j);
                CyDelay(500);
                if(readPorts2() == i*2+j*1)counter++;
            }
        }
        if(counter==8)Result_Write(1);
    }
}

/* [] END OF FILE */
