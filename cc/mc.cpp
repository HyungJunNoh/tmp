#include <random>
#include <ctime>
#include <mpi.h>


int main()
{
	
	MPI_Init(NULL, NULL);

	int mype, totalpe;
	MPI_Comm_size(MPI_COMM_WORLD, &totalpe);
	MPI_Comm_rank(MPI_COMM_WORLD, &mype);

  //integer : -2,147,483,648 ~ 2,147,483,646. i.e. ~ 2G
  //int n=1000000000; //please make sure that the number is not over int range.
  int n=100000000/totalpe;; //please make sure that the number is not over int range.
	double area_per_particle = 4.0 / (n * totalpe);

  //====================For Seeding
  //   You may use either
  //--------------------Option 1
  //std::random_device rd;
  //std::mt19937 gen(rd());
  //--------------------Option 2
  std::mt19937 gen(mype);

  // Set distribution range
  std::uniform_real_distribution<> dis(-1.0, 1.0);

  double area_circle = 0.0;
	double area_total = 0.0; 
	double x[n], y[n], r2[n];

  for(int i=0; i<n; i++)
  {
    x[i] = dis(gen);
    y[i] = dis(gen);
	}
	for(int i = 0; i < n; i++) {
    r2[i] = x[i]*x[i] + y[i]*y[i]; //we do not need to get r. sqrt operation is expensive and waste time.
    if(r2[i] < 1.0)
    {
      area_circle += area_per_particle;
    }
  }
	MPI_Reduce(&area_circle, &area_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(!mype)
		printf("%d: pi (evaluated in parallel) = %lf\n",mype, area_total);
	MPI_Finalize();
	return 0;
}
