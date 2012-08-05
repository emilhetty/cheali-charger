#ifndef TIMER_H_
#define TIMER_H_

#include <inttypes.h>

#define INTERRUPT_PERIOD_MICROSECONDS 512

class Timer {
	volatile uint32_t _interrupts;
public:
	Timer();
	void init();
	void doInterrupt();
	uint32_t getInterrupts() const { return _interrupts; }
	uint32_t getMiliseconds() const;
	void delay(uint32_t ms) const;
};

#endif /* TIMER_H_ */