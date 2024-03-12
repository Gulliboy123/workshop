#include <stdio.h>

int main(int argc, char *argv[]){

    for(int i=0;i<=100;i++){
        printf("%d",i);
        printf("\n");

    }
    printf("Argument Count > %d",argc);
    for(int i=0;i<argc;i++){
        printf("\nArgument vector %s\n",argv[i]);

    }

    return 0; 
}

 