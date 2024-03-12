#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv){
    int rank,size,data;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0){
        data=123;
    }
    MPI_Bcast(&data,1,MPI_INT,0,MPI_COMM_WORLD);
    printf("Process:%d Received data:%d\n",rank,data);
    MPI_Finalize();
    return 0;
}

