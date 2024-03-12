#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv){
    int rank,size;
    int sendbuf[4],recvbuf[4];
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    for(int i=0;i<4;i++){
        sendbuf[i]=rank+1;
    }
    MPI_Alltoall(&sendbuf,1,MPI_INT,&recvbuf,1,MPI_INT,MPI_COMM_WORLD);
    printf("Process:%d received:\n",rank);
    for(int i=0;i<4;i++){
        printf("%d",recvbuf[i]);
    }
    printf("\n");
    MPI_Finalize();
    return 0;
}