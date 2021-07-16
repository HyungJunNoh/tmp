
int peel = x & 0x0f; 
if (peel != 0) {
  peel = 16 - peel; 
	  /* runtime peeling loop */
		  for (i = 0; i < peel; i++) { x[i] = 1; } 
			} 

			/* aligned access */ 
			for (i = peel; i < 1024; i++) { x[i] = 1; }

int main()
{
	int a[32768];
	int b[32768];
	int c[32768];

	for(int i=0; i<32768; i++) {
		a[i] = i * 2;
		b[i] = i;
	}
	for(int i=0; i<32768; i++) {
		c[i] = a[i] * b[i];
	}
return 0;
}
