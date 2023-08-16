/*
 *******************************************************************************
 * MIT License
 *
 * Copyright (c) 2023 Jerryl James
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *******************************************************************************
 */

#include "tca9548.h"

extern I2C_HandleTypeDef hi2c1;


/**
  * @brief  Set
  * @retval None
  */
void SetCh(uint8_t *ch)
{
	HAL_I2C_Master_Transmit(&hi2c1, TCAADDR, ch, 1, HAL_MAX_DELAY);
}

/**
  * @brief  Set TCA channel. Range 0 - 8
  * @retval None
  */
void SetTCAChannel(uint8_t channel)
{
	uint8_t ch = (1 << channel);
	if(ch > MAXCHANNEL)
	{
		ch = 0;				//No channel selected
	}
	SetCh(&ch);
}


