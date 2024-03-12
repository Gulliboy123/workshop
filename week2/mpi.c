#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
int main(int argc, char **argv){
    int rank,size;
    int senddata,*recvdata;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    senddata=(rank+1)*10;
    if(rank==0){
        recvdata=(int*)malloc(sizeof(int)*size);
    }
    MPI_Gather(&senddata,1,MPI_INT,recvdata,1,MPI_INT,0,MPI_COMM_WORLD);
    if(rank==0){
        printf("Received data from process:");
        for(int i=0;i<size;i++){
            printf("Rank:%d Received data:%d\n",rank,recvdata[i]);
        }
        printf("\n");
        free(recvdata);
    }
    MPI_Finalize();
    return 0;
}