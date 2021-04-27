#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Keep the order of the words but reverse each word
char* revStringWords(char *str, int str_size)
{
    char *rev_str = malloc(sizeof(*rev_str) * str_size);
    int index = 0;
    int rev_str_index = 0;
    int size = 0;
    char *token = strtok(str, " ");
    
    while(token != NULL)
    {   
        while(token[index] != '\0'){
            size++;
            index++;
        }
        index = 0;
        for(int i = size - 1; i >= 0; i--){
            rev_str[rev_str_index++] = token[i];
        }
        rev_str[rev_str_index++] = ' ';
        size = 0;
        token = strtok(NULL, " ");
    }
    rev_str[str_size] = '\0';
    return rev_str;
}

//Reverse the enire string
char* revString(char *str, int size)
{
    char *rev_str = malloc(sizeof(*rev_str) * size);
    int index = 0;
    
    for(int i = size - 1; i >= 0; i--){
        rev_str[index] = str[i];
        index++;
    }
    rev_str[index] = '\0';
    return rev_str;

}

int main()
{
    char str[] = "Hello Obi-Wan Kenobi how are you dooing?";
    int size = *(&str + 1) - str;

    char *rev_str = revString(str, size);
    for(int i = 0; i < size; i++)
        printf("%c", rev_str[i]);
    printf("\n\n");

    char *rev_str2 = revStringWords(str, size);
    for(int i = 0; i < size; i++)
        printf("%c", rev_str2[i]);

    return 0;
}