/*
Copyright (c) 2012-2015 Ben Croston

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "common.h"

#if FOR_H6_ONLY
#define SUNXI_GPIO_BASE   (0x0300B000)
#define SUNXI_GPIO_BASE_2 (0x07022000)
#define SUNXI_PWM_BASE    (0x0300A000)
#define SUNXI_PWM_BASE_2  (0x07020C00)
#else
#define SUNXI_GPIO_BASE   (0x01C20800)
#define SUNXI_GPIO_BASE_2 (0x01F02C00)
#define SUNXI_PWM_BASE    (0x01C21400)
#define SUNXI_PWM_BASE_2  (0x01F03800)
#endif

#define SUNXI_GPIO_EXTRA  352

#define BLOCK_SIZE        0x400
#define MAP_MASK          (BLOCK_SIZE - 1)

#define SETUP_OK          0
#define SETUP_DEVMEM_FAIL 1
#define SETUP_MALLOC_FAIL 2
#define SETUP_MMAP_FAIL   3

#define INPUT             0
#define OUTPUT            1

#define HIGH              1
#define LOW               0

#define PUD_OFF           0
#define PUD_DOWN          2
#define PUD_UP            1

#define OPiGPIODebug      0

int setup(void);
int gpio_function(int gpio);
void setup_gpio(int gpio, int direction, int pud);
void output_gpio(int gpio, int value);
int input_gpio(int gpio);
void clear_event_detect(int gpio);
int eventdetected(int gpio);
void set_rising_event(int gpio, int enable);
void set_falling_event(int gpio, int enable);
void set_high_event(int gpio, int enable);
void set_low_event(int gpio, int enable);
void cleanup(void);
