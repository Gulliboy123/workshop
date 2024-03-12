#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
    int rank,size,local_value=10,global_sum=0;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    printf("Process:%d has local value:%d\n",rank,local_value);
    MPI_Reduce(&local_value,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    if(rank==0){
        printf("Rank:%d received global sum result:%d\n",rank,global_sum);
    }
    MPI_Finalize();
    return 0;
}