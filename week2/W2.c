#include<stdio.h>
#include <mpi.h>
#include <string.h>


int main(int argc,char **argv){
    int rank,size;
    char send_message[100],recv_message[100];
    MPI_Request send_request,recv_request;
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(size !=2){
        if(rank==0){
            printf("This program needs exactly 2 process to run \n");
        }
        MPI_Finalize();
        return 1;
    }
    if(rank ==0){
        strcpy(send_message,"Hello from process 0!");
        MPI_Isend(send_message,100,MPI_CHAR,1,0,MPI_COMM_WORLD,&send_request);
        MPI_Irecv(recv_message,100,MPI_CHAR,1,0,MPI_COMM_WORLD,&recv_request);
    }else{
        strcpy(send_message,"Hello from process 1!");
        MPI_Isend(send_message,100,MPI_CHAR,0,0,MPI_COMM_WORLD,&send_request);
        MPI_Irecv(recv_message,100,MPI_CHAR,0,0,MPI_COMM_WORLD,&recv_request);
    }
    MPI_Wait(&send_request,&status);
    MPI_Wait(&recv_request,&status);
    printf("Process : %d received:%s\n",rank,recv_message);
    MPI_Finalize();
    return 0;
}