/* This program demostrates the fork() function */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void check_fork_error(int pid, int i);
void fork_0();
void fork_1();
void fork_2();
void fork_3();
void fork_4();
void fork_5();

int error_num = 0;
int main(){
    int function_id;
    printf("Enter the integer representing the function_id you want to run\n");
    scanf("%d", &function_id);
    switch (function_id)
    {
    case 0:
        fork_0();
        break;

    case 1:
        fork_1();
        break;
    
    case 2:
        fork_2();
        break;

    case 3:
        fork_3();
        break;
    
    case 4:
        fork_4();
        break;
    
    case 5:
        fork_5();
        break;
    
    default:
        printf("The function_id %d does not exist\n", function_id);
        break;
    }
    
    printf("\nerror_num = %d\n", error_num);
    return error_num;
}

void check_fork_error(int pid, int i){
    if (pid == -1){
        printf("Error using fork()");
        error_num = i;
    }
}
/* fork() from the main process creating a child process */
void fork_0(){
    int pid_id = fork();
    if(pid_id == 0)
        printf("This is the child process with PID = %d\n", pid_id);
    else
        printf("This is the main process with PID = %d\n", pid_id);
}

/* fork() from the main process creating a child process,
*  total 2 process
*  fork() from the main process again, creating another child process
*  total 3 process
*/
void fork_1(){
    int pid_id = fork();

    if(pid_id != 0)
        fork();
    
    printf("This should be printed 3 times\n");
}

/* This function demostrates how two processes executes
*  at the same time by printing different number in a loop
*/
void fork_2(){
    int pid_id = fork();
    int x;

    if(pid_id == 0)
        x = 0;
    else
        x = 10;
    
    for(int i = x; i < x + 50; i++){
        printf("%d ", i);
        fflush(stdout); //prinf() stores things in a buffer and wont print everything right away, fflush flushes the buffer to the screen
    }
}

/* The only difference betwiin fork_3() and fork_2()
*  is the wait() statement before the for loop which
*  will tell the main process to wait untill the child
*  has finished.
*/
void fork_3(){
    int pid_id = fork();
    int x;

    if(pid_id == 0)
        x = 0;
    else
        x = 10;
    
    if (pid_id != 0)
        wait(0); //wait for the child process to finish

    for(int i = x; i < x + 50; i++){
        printf("%d ", i);
        fflush(stdout);
    }
}

/* A child process writes a user inputed int to fd
*  the parent process will then read this int and print it
*/ 
void fork_4(){
    int fd[2];
    if(pipe(fd) == -1){
        printf("Error using pipe(fd)");
        error_num = 1;
        return;
    }

    int pid_id = fork();
    check_fork_error(pid_id, 2);

    if(pid_id == 0){
        close(fd[0]);
        printf("Input a number\n");
        int child_num;
        scanf("%d", &child_num);
        if(write(fd[1], &child_num, sizeof(int)) == -1){
            printf("Error writing from child process to fd");
            error_num = 3;
        }
        close(fd[1]);
    }
    else {
        close(fd[1]);
        int parent_num;
        if(read(fd[0], &parent_num, sizeof(int)) == -1){
            printf("Error reading from parent process");
            error_num = 4;
        }
        close(fd[0]);
        printf("Reading value from the child process...\nThe value is: %d", parent_num);
    }
}

/* The largest number in an int array is found by
*  utalizing two process, a parent and its child.
*  The child searches the first half and parent the second.
*  The child will write the largest number it found through pipe(),
*  the parent will read the value and then compare with its largest
*/
void fork_5(){
    int arr[] = {1, 4, 7, 2, 14, 5, 0, -2, -100, 9};
    const int arr_size = *(&arr + 1) - arr;
    const int mid = (arr_size / 2) - 1;
    int start, end;

    int fd[2];
    if(pipe(fd) == -1) {
        printf("Error using pipe in fork_5");
        error_num = 5;
        return; 
    }

    int pid_id = fork();
    check_fork_error(pid_id, 6);

    if(pid_id == 0){
        start = 0;
        end = mid;
    }
    else {
        start = mid + 1;
        end = arr_size;
    }

    int largest = arr[0];
    int temp = largest;

    for(int i = start; i <= start + mid; i++){
        if (arr[i] > largest)
            largest = arr[i];
    }

    if(pid_id == 0){
        close(fd[0]);
        int child_num = largest;
        if(write(fd[1], &child_num, sizeof(int)) == -1){
            printf("Error writing from child process in fork_5");
            error_num = 7;
        }
        close(fd[1]);
    }
    else {
        close(fd[1]);
        int from_child;
        if (read(fd[0], &from_child, sizeof(int)) == -1){
            printf("Error reading from parent process");
            error_num = 8;
        }
        close(fd[0]);
        printf("The childs largest is: %d\nThe parents largest is %d\n", from_child, largest);
        if(largest > from_child)
            printf("The largest number in the array is therfor %d", largest);
        else
            printf("The largest number in the array is therfor %d", from_child);
    }    
}