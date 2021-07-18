#include <stdio.h>
#include <stdlib.h> // for random number
#include <time.h>
#include <math.h>

int main() {

	clock_t start = clock();
	srand(time(NULL));
	
	double area = 0;
	long int n = 100000000000000;
	double pi;
	double error = 3;

	for (long int i = 0; i < n; i++) {
		double random_x = (double)rand() / (double)RAND_MAX;
		double random_y = (double)rand() / (double)RAND_MAX;

		if (random_x * random_x +
			  random_y * random_y <= 1)
			area++;

		pi = 4 * area / i;
		error = 3.14159265358979323846264338327950288419716 - pi;	
		//printf("%dth, pi : %.20f \n", i, pi);

		if (fabs(error) < 1e-12) {
			printf("Error : %.15f \n", error);
			printf("%dth, pi : %.15f \n", i, pi);
			break;
		}
	}
	clock_t end = clock();
	printf("Time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
return 0;
}




//Ø©Öã?ª®ªÏªâª¦ðûªïªêi
