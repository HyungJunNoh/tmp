#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[32768];
	int b[32768];
	int c[32768];
//	int k = 0;
	for(int i = 0; i < 32768; i++) {
		a[i] = 0;
		b[i] = 1;
		c[i] = 0;
	}

	for (int i = 0; i < 32768; i++) {
		c[i] = a[i] + b[i];
		//k += c[i];
	}
	printf("%d\n",c[8]);
	return 0;
}
