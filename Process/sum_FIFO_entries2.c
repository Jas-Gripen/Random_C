/*This file generates an array of 10 entries
* and writes them to the FIFO which should
* be red by another file.
*/
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
    int fd = open("sum_FIFO", O_RDONLY);
    if (fd == - 1){
        printf("Error opening fd\n");
        return 4;
    }
    const int numbers_size = 10;
    int numbers [numbers_size];

    if(read(fd, &numbers, sizeof(int) * numbers_size) == - 1){
        printf("Error reading from FIFO\n");
        return 3;
    }
    close(fd);

    int sum = 0;
    printf("The gathered numbers are:  ");
    for(int i = 0; i < numbers_size; i++){
        printf("%d ", numbers[i]);
        sum = sum + numbers[i];
    }
    printf("\n");

    printf("\nThe sum of the numbers is %d\n", sum);
    return 0;
}