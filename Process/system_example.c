/* This program takes input from the user through STDIN
*  and executes it as a system command using system().
*  The output is then printed to the consol.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    printf("Enter a cmd command\n");

    const int STR_SIZE = 1024;
    char str[STR_SIZE];

    fgets(str, STR_SIZE, stdin);

    printf("Executing %s\n", str);
    int x = system(str);

    if(x == 1)
        printf("Error executing the command: %s", str);

    return 0;
}