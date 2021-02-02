#include <reg51.h>

#define size 8
#define half 4
#define delay 100000

const vals[size] = {1, 2, 4, 8, 16, 32, 64, 128};

void main() {

	unsigned char y;
	unsigned int i;
	
	while (1) {
		// (3, 4), (2, 5), (1, 6), (0, 7).
		for (y = 0; y < half; y++) {
			port0 = vals[half - y - 1] + vals[half + y]; // Replace the port here.
			for(i = 0; i < delay; i++);
		}

		// (1, 6), (2, 5), (3, 4)
		for (y = 2;y > 0; y--) {					
			port0 = vals[half - y - 1] + vals[half + y]; // Replace the port here.
			for(i = 0; i < delay; i++);

		}
	}
}
