#include "library.hpp"
#include <math.h>
#include <assert.h>

int main()
{
	MPI_Init(NULL, NULL);

	int rank = -1;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0){
		printf("Pass\n");
  }
  
	MPI_Finalize();
}
