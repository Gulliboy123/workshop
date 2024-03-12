// // Qno1

// /*
//   MPI_Init must be used to initialise MPI. 
//   MPI_Comm_size finds out how many processes is running, i.e. the number following the -n switch.
//   MPI_COMM_WORLD is the default communicator group.
//   MPI_Comm_rank gets the process rank. The process with rank 0 is thought of as the starting process
//   MPI_Finalize closes down MPI. All processes must call this to close down MPI. 
// */

// #include <stdio.h>
// #include <mpi.h>

// int main(int argc, char** argv) {
//   int size, rank;

//   MPI_Init(NULL, NULL);
//   MPI_Comm_size(MPI_COMM_WORLD, &size);
//   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//   printf("I am %d of %d\n", rank, size);
//   MPI_Finalize();

//   return 0;
// }



// // Qno2
// /*
//   - Process 0 sends x to process 1 and y to processes 2. "1, MPI_INT" 
//     indicates that the message consists of one integer.
//   - Processes other than rank 0 wait to receive a message using MPI_Recv. 
//     The "0, 0" indicates that the message is expected from process 0 and 
//     should have the tag 0. The result is stored in the number variable. 
// */

// #include <stdio.h>
// #include <mpi.h>

// int main(int argc, char** argv) {
//   int size, rank;

//   MPI_Init(NULL, NULL);
//   MPI_Comm_size(MPI_COMM_WORLD, &size);
//   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//   if(size != 3) {
//     if(rank == 0) {
//       printf("This program needs to run on exactly 3 processes\n");
//     }
//   } else {
//     if(rank ==0){
//       int x = 9;
//       int y = 17;
//       MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
//       MPI_Send(&y, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
//     } else {
//       int number;
//       MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//       printf("Process %d received %d\n", rank, number); 
//     }
//   }
//   MPI_Finalize(); 

//   return 0;
// }



// // Qno3 and 4
// /*
//   - Process 0 sends x to process 1 and y to processes 2. "1, MPI_INT" 
//     indicates that the message consists of one integer.
//   - Processes other than rank 0 wait to receive a message using MPI_Recv. 
//     The "0, 0" indicates that the message is expected from process 0 and 
//     should have the tag 0. The result is stored in the number variable. 
// */

// #include <stdio.h>
// #include <mpi.h>

// int main(int argc, char** argv) {
//   int size, rank;

//   MPI_Init(NULL, NULL);
//   MPI_Comm_size(MPI_COMM_WORLD, &size);
//   MPI_Comm_rank(MPI_COMM_WORLD, &rank);

//     if(rank ==0){
//       int x = 9;
//       int y = 17;
//       MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
//       MPI_Send(&y, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
//     } else {
//       int number;
//       MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//       printf("Process %d received %d\n", rank, number); 
    
//   }
//   MPI_Finalize(); 

//   return 0;
// }


// // /Qno 5

// /*
//   This program demonstrates how to send a message from the process with rank
//   0 to other processes. The other processes execute a blocking receive 
//   instruction. This causes them to wait for a message before proceeding to 
//   print out the data that was received. Process 0 wants to receieve from 
//   process 1 before process 2. When process 1 goes to sleep blocking causes
//   the send from process 2 to process 0 to be delayed by 5 seconds. 
// */

// #include <stdio.h>
// #include <mpi.h>
// #include <unistd.h>

// int main(int argc, char** argv) {
//   int size, rank;

//   MPI_Init(NULL, NULL);
//   MPI_Comm_size(MPI_COMM_WORLD, &size);
//   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//   // Check if the program is running on exactly 3 processes
//   if(size != 3) {
//     if(rank == 0) {
//       printf("This program needs to run on exactly 3 processes\n");
//     }
//   } else {
//     if(rank ==0){
//       int x, y;
//       // Receive message from process 1
//       MPI_Recv(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//       printf("Received %d from process %d\n", x, 1); 
//       // Initiate non-blocking receive from process 2
//       MPI_Request request;
//       MPI_Status status;
//       MPI_Irecv(&y, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &request);
//       // Sleep for 5 seconds if the current process is rank 1
//       if(rank == 1){
//         usleep(5000000);
//       }
//       // Wait for the non-blocking receive to complete
//       MPI_Wait(&request, &status);
//       printf("Received %d from process %d\n", y, 2);
//     } else { 
//       // Process ranks 1 and 2 send a message to process 0
//       int number = rank + 10;
//       MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
//     }
//   }
//   MPI_Finalize(); 

//   return 0;
// }



// Qno 6
#include<stdio.h>
#include<mpi.h>
int main(int argc, char **argv){
    int size,rank;
    int i,c;
    int nstart=1, nfinish=10000;
    printf("%s : Prime numbers between %d and %d are :\n", argv[0], nstart, nfinish);
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    for(i=nstart; i<=nfinish; i++)
  { 
    for(c=2; c<=i-1; c++)
    {
      if ( i%c==0 )
        break;
    }
    if ( c==i ) 
      printf("Rank:%d Number:%d\n",rank,i);//Change garya ho(printf("%s : %d\n",argv[0], i); yesto thiyo)
  }
  MPI_Finalize();
  return 0;

}