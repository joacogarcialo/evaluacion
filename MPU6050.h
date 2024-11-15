#ifndef MPU6050_H
#define MPU6050_H
#include "MKL25Z4.h"
void MPU6050_Init(void);
void MPU6050_AcelX(void);
void MPU6050_AcelY(void);
void MPU6050_AcelZ(void);
void MPU6050_GiroX(void);
void MPU6050_GiroY(void);
void MPU6050_GiroZ(void);
void MPU6050_Temp(void);
#endif