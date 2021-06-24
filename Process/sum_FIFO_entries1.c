/*This file reads the FIFO and calculates the total sum. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(){
    if(mkfifo("sum_FIFO", 0700) == -1){
        if(errno != EEXIST){
            printf("Error creating FIFO\n");
            return 1;
        }
    }

    const int numbers_size = 10;
    int numbers [numbers_size];
    srand(time(NULL));
    printf("The generated numbers are: ");
    for(int i = 0; i < numbers_size; i++){
        numbers[i] = rand() % 100;
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    int fd = open("sum_FIFO", O_WRONLY);
    if (fd == - 1){
        printf("Error opening fd\n");
        return 3;
    }

    if(write(fd, &numbers, sizeof(int) * numbers_size) == - 1){
        printf("Error writing to FIFO\n");
        return 2;
    }
    close(fd);

    return 0;


}