#include <random>
#include <ctime>
#include <omp.h>

int main()
{

  //integer : -2,147,483,648 ~ 2,147,483,646. i.e. ~ 2G
  //int n=1000000000; //please make sure that the number is not over int range.
  int n=10000000; //please make sure that the number is not over int range.
  double area_per_particle = 4.0 / n;

	double area_total = 0.0;
	#pragma omp parallel shared(area_total)
	{

  //====================For Seeding
  //   You may use either
  //--------------------Option 1
  //std::random_device rd;
  //std::mt19937 gen(rd());
  //--------------------Option 2
  std::mt19937 gen((unsigned int)time(NULL) + omp_get_thread_num());

  // Set distribution range
  std::uniform_real_distribution<> dis(-1.0, 1.0);

  double area_circle = 0.0;
	#pragma omp for
  for(int i=0; i<n; i++)
  {
    double x = dis(gen);
    double y = dis(gen);

    double r2 = x*x + y*y; //we do not need to get r. sqrt operation is expensive and waste time.
    if(r2 < 1.0)
    {
      area_circle += area_per_particle;
    }
  }

	#pragma omp atomic
	area_total += area_circle;

	}
	//area_circle *= area_per_particle;
  printf("pi (evaluated) = %lf\n",area_total);

	return 0;
}
