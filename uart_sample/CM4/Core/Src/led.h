#ifndef _LED_H_
#define _LED_H_

#include <stdbool.h>
#include <stdint.h>

#define LED2_PORT 1

void LED_Init();

void LED_Blink(uint32_t port, bool bBlink);

#endif /* _LED_H_ */

