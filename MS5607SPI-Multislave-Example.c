#include <stdio.h>
#include "MS5607SPI.h"
#include "stm32l0xx_hal.h"

#define SPI1_CS_MS5607_1_GPIO_Port GPIOC
#define SPI1_CS_MS5607_2_GPIO_Port GPIOB
#define SPI1_CS_MS5607_1_Pin GPIO_PIN_15
#define SPI1_CS_MS5607_2_Pin GPIO_PIN_5

void sensors_MS5607SPI_Example(SPI_HandleTypeDef *hspi) {
	MS5607SPI_t MS5607SPI_1;
	MS5607SPI_t MS5607SPI_2;

	printf("SENSORS: MS5607 1 init\n");
	if(MS5607_Init(&MS5607SPI_1, hspi, SPI1_CS_MS5607_1_GPIO_Port, SPI1_CS_MS5607_1_Pin) == MS5607_STATE_FAILED) {
		printf("SENSORS: MS5607 1 init FAILED\n");
	} else {
		printf("SENSORS: Reading MS5607 1\n");
		MS5607Update(&MS5607SPI_1);
		printf("SENSORS: temp=%ld.%ld°C, pres=%ld Pa\n",MS5607GetTemperaturemC(&MS5607SPI_1)/10,
														MS5607GetTemperaturemC(&MS5607SPI_1)%10,
														MS5607GetPressurePa(&MS5607SPI_1));
	}
	printf("SENSORS: MS5607 2 init\n");
	if(MS5607_Init(&MS5607SPI_2, hspi, SPI1_CS_MS5607_2_GPIO_Port, SPI1_CS_MS5607_2_Pin) == MS5607_STATE_FAILED) {
		printf("SENSORS: MS5607 2 init FAILED\n");
	} else {
		printf("SENSORS: Reading MS5607 2\n");
		MS5607Update(&MS5607SPI_2);
		printf("SENSORS: temp=%ld.%ld°C, pres=%ld Pa\n",MS5607GetTemperaturemC(&MS5607SPI_2)/10,
														MS5607GetTemperaturemC(&MS5607SPI_2)%10,
														MS5607GetPressurePa(&MS5607SPI_2));
	}
}