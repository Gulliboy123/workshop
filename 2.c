#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv){
    int size,rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(size!=3){
        printf("This program needs exactly 3 processes to run");
        MPI_Finalize();
        return 1;
    }
    if(rank==0){
        char message1[100] = "I am Anmol";
        char message2[100] = "I am Anmol Shrestha";
        MPI_Send(message1,100,MPI_CHAR,1,0,MPI_COMM_WORLD);
        MPI_Send(message2,100,MPI_CHAR,2,0,MPI_COMM_WORLD);

 
    }else{
        char receivedmessage[100];
        MPI_Recv(receivedmessage,100,MPI_CHAR,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("\nprocess : %d received %s",rank,receivedmessage);
    }
    MPI_Finalize();
    return 0;
}