#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
    int rank,size,sum=0;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    printf("Process:%d is doing something...\n",rank);
    for(int i=0;i<rank*100000000;i++){
        sum+=i;
    }
    MPI_Barrier(MPI_COMM_WORLD);
    printf("Process:%d has reached the barrier\n",rank);
    MPI_Finalize();
    return 0;
}