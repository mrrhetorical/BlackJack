#ifdef _WIN32

#include "Windows.h"

class Delay {
public:
	static inline void delay(unsigned long ms) {
		Sleep(ms);
	}

#else

#include <unistd.h>

	static inline void delay( unsigned long ms )
	  {
	  usleep( ms * 1000 );
	  }

#endif
};