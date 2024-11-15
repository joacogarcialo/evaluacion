#include "MPU6050.h"
#include "I2C.h"
#define I2C_W 0
#define I2C_R 1
#define address_mpu 0x60
#define GYRO_CONFIG 0X27
#define ACEL-CONFIG 0X28
void MPU6050_Init(void){
    SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;  // reloj para el MPU6050
    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK; 
    PORTB->PCR[23] = PORT_PCR_MUX(2);    // SERIAL CLOCK
    PORTB->PCR[24] = PORT_PCR_MUX(2);    //SERIAL DATA
    PORTB->PCR[2] = PORT_PCR_MUX(1); //LED1
    PORTB->PCR[3] = PORT_PCR_MUX(1); //LED2
    PORTB->PCR[4] = PORT_PCR_MUX(1); //LED3
    I2C0->F = I2C_F_ICR(0x25) | I2C_F_MULT(0); // 348 kHz
    I2C0->C1 |= I2C_C1_IICEN_MASK;    
    I2C0->C1 |=ACCEL_FIFO_EN[3];

}void MPU6050_AcelX(void){
   I2C0->C1 |=XA_TEST[7];
   I2C0->C1 |=ACCEL_XOUT_L[5];
   I2C0->C1|=ACCEL_RESET[1];
}
void MPU6050_AcelY(void){
    I2C0->C1 |=YA_TEST[6];
    I2C0->C1 |=ACCEL_YOUT_L[6];
    I2C0->C1|=ACCEL_RESET[1];
}
void MPU6050_AcelZ(void){
    I2C0->C1 |=ZA_TEST[5];
    I2C0->C1 |=ACCEL_ZOUT_L[7];
    I2C0->C1|=ACCEL_RESET[1];
}
 void MPU6050_GiroX(void){
I2C0->C1 |=XG_ST[7];
I2C0->C1 |=GYRO_XOUT_L[5];
I2C0->C1 |=GYRO_RESET[2];
I2C0->C1|=ZG_FIFO_EN[6];
 }
void MPU6050_GiroY(void){
I2C0->C1 |=YG_ST[6];
I2C0->C1 |=GYRO_YOUT_L[6];
I2C0->C1 |=GYRO_RESET[2];
I2C0->C1|=ZG_FIFO_EN[5];
}
void MPU6050_GiroZ(void){
I2C0->C1 |=ZG_ST[5];
I2C0->C1 |=GYRO_ZOUT_L[7];
I2C0->C1 |=GYRO_RESET[2];
I2C0->C1|=ZG_FIFO_EN[4];
}
void MPU6050_Temp(void){
I2C0->C1 |=TEMP_ZOUT_L[4];
I2C0->C1|=TEMP_RESET[0];
I2C0->C1|=TEMP_FIFO_EN[7];
}



