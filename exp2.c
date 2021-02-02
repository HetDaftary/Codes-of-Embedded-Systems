#include <reg51.h>

#define size 8
#define half 4
#define delay 100000

const vals[size] = {1, 2, 4, 8, 16, 32, 64, 128};

void main() {

	unsigned char y;
	unsigned int i;
	
	while (1) {
		// (0, 4), (1, 5), (2, 6), (3, 7)
		for (y = 0; y < half; y++) {
			port0 = vals[y] + vals[y + 4]; // Replace the port here.
			for(i = 0; i < delay; i++);
		}
		
		port0 = 0;
		
		// (2, 6), (1, 5), (0, 4)
		for (y = half - 2; y >= 0; y--) {
			port0 = vals[y] + vals[y + 4]; // Replace the port here.
			for(i = 0; i < delay; i++);
		}
	}
}