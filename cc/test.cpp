#include <stdio.h>
#include <stdlib.h>

int main() {
	long long int a[32768];
	long long int b[32768];
	long long int c[32768];
	long long int k, l, m, n = 0;
	for(int i = 0; i < 32768; i++) {
		a[i] = 2;
		b[i] = 1;
		c[i] = 0;
	}

	for (int i = 0; i < 32768; i++) {
		c[i] = a[i] + b[i];
		k += c[i];
		k *= k;
	}

	
	for (int i = 0; i < 32768; i++) {
		c[i] = a[i] + b[i];
		l += c[i];
		l *= l;
	}

	for (int i = 0; i < 32768; i++) {
		c[i] = a[i] + b[i];
		c[i] *= c[i];
		c[i] *= 3;
		c[i] *= c[i];
		m += c[i];
		m *= m;
	}
	printf("%d, %d, %d\n",k, l, m);
	return 0;
}
