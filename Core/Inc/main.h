/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define ColA_Pin GPIO_PIN_0
#define ColA_GPIO_Port GPIOA
#define ColB_Pin GPIO_PIN_1
#define ColB_GPIO_Port GPIOA
#define ColC_Pin GPIO_PIN_2
#define ColC_GPIO_Port GPIOA
#define ColD_Pin GPIO_PIN_3
#define ColD_GPIO_Port GPIOA
#define ColE_Pin GPIO_PIN_4
#define ColE_GPIO_Port GPIOA
#define ColF_Pin GPIO_PIN_5
#define ColF_GPIO_Port GPIOA
#define ColG_Pin GPIO_PIN_6
#define ColG_GPIO_Port GPIOA
#define ColH_Pin GPIO_PIN_7
#define ColH_GPIO_Port GPIOA
#define ColI_Pin GPIO_PIN_13
#define ColI_GPIO_Port GPIOB
#define Row8_Pin GPIO_PIN_14
#define Row8_GPIO_Port GPIOB
#define Row7_Pin GPIO_PIN_15
#define Row7_GPIO_Port GPIOA
#define Row6_Pin GPIO_PIN_3
#define Row6_GPIO_Port GPIOB
#define Row5_Pin GPIO_PIN_4
#define Row5_GPIO_Port GPIOB
#define Row4_Pin GPIO_PIN_5
#define Row4_GPIO_Port GPIOB
#define Row3_Pin GPIO_PIN_6
#define Row3_GPIO_Port GPIOB
#define Row2_Pin GPIO_PIN_7
#define Row2_GPIO_Port GPIOB
#define Row1_Pin GPIO_PIN_8
#define Row1_GPIO_Port GPIOB
#define Row0_Pin GPIO_PIN_9
#define Row0_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
