#include <reg51.h>

#define size 8
#define delay 100000

const vals[size] = {1, 2, 4, 8, 16, 32, 64, 128};

void main() {

	unsigned char y;
	unsigned int i;
	
	while (1) {
		// 0, 1, 2, 3, 4, 5, 6, 7
		for (y = 0; y < size; y++) {
			port0 = vals[y]; // Replace the port here.
			for(i = 0; i < delay; i++);
		}
		// y = 8 rn.
		y--; // Making y = 7.
	
		while (y >= 0) {
			port0 = vals[--y];
			for(i = 0; i < delay; i++); 
		}
	}
}