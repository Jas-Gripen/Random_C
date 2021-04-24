#include <stdio.h>
#include <stdlib.h>

char* addArray(char *str1, int size1, char *str2, int size2)
{   
    char *buff = malloc(sizeof(*buff) * (size1 + size2));
    int i;
    for(i = 0; i < size1 - 1; i++) // size1 - 1 to remove first \0
        buff[i] = str1[i];

    for(int j = 0; j < size2; j++){
        buff[i] = str2[j]; 
        i++;
    }
    
    return buff;
}
int main ()
{
    char str1[] = "Obi-Wan Kenobi: Hello there\n";
    char str2[] = "General Grievous: General Kenobi";
    int size1 = *(&str1 + 1) - str1;
    int size2 = *(&str2 + 1) - str2;
    char *buff = addArray(str1, size1, str2, size2);
    printf("%s", buff);
    free(buff);
    return 0;
}