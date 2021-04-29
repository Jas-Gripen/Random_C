/*
This program can extract a part of a string and copy it to
a new allocated memory. Another fnction is to scan a string
to find out if a perticular substring exist. The algorithm
has a worst case timecomplexity of O(N).
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
const int SIZE = 100;

char* extract_string(char *str, int start_pos, int length){
    if(str == NULL || start_pos < 0 || length < 0 || start_pos + length >= SIZE){
        printf("The input is not allowed\n");
        exit(1);
    }

    char *ex_str = malloc(sizeof(*ex_str) * length);
    int i;  
    for(i = 0; i < length; i++){
        if(str[start_pos] == '\0')
            break;
        ex_str[i] = str[start_pos];
        start_pos++;
    }
    ex_str[i] = '\0';
    return ex_str;
}

bool find_substring(char *str1, char *str2){
    if(str1 == NULL || str2 == NULL){
        printf("ERROR: NULL pointer");
        exit(1);
    }
    
    int str1_pos = 0;
    int str2_pos = 0;
    
    /*str1_pos is never subtracted or restored and the inner loop
    continues from the same position as the outer loop. As soon as
    either '\0' is found in either of the arrays or str1_pos reaches
    size, the function returns either true or false.
    --> Worst case O(N) time complexity.*/
    while(str1_pos < SIZE){
        if(str1[str1_pos] == str2[str2_pos]){
            while(str1_pos < SIZE){
                /////////////////////////////////////////////////////////////////////////
                /*a new line character is added at the end of the string before
                the null character. Therefor, we have to iterate to the next position*/
                if(str1[str1_pos] == '\n'){
                    str1_pos++;
                    continue;
                }
                else if(str2[str2_pos] == '\n'){
                    str2_pos++;
                    continue;
                }
                /////////////////////////////////////////////////////////////////////////
                else if((str1[str1_pos] != str2[str2_pos]) && str2[str2_pos] != '\0'){
                    str2_pos = 0;
                    break;
                }
                else if(str2[str2_pos] == '\0'){
                    return true;
                }
                else if(str1[str1_pos] == '\0')
                    return false;
                str1_pos++;
                str2_pos++;
            }
        }
        str1_pos++;
    }

    return false;
}

void test_extract_string(){
    char str[SIZE];
    char sub_str[SIZE];
    int start_pos;
    int length;

    printf("Enter a string\n");
    fgets(str, SIZE, stdin);
    printf("Enter start position for the extracted string\n");
    scanf("%d", &start_pos);
    printf("Enter the length for the extracted string\n");
    scanf("%d", &length);
    char *pStr = extract_string(str, start_pos, length);
    printf("The extracted string is:\n%s\n", pStr);
    printf("End of test_extract_string\n");
}

void test_findsubstring(){
    char str[SIZE];
    char sub_str[SIZE];
    int start_pos;
    int length;

    printf("Enter a string\n");
    fgets(str, SIZE, stdin);
    printf("Enter a substring\n");
    fgets(sub_str, SIZE, stdin);

    bool is_sub_string = find_substring(str, sub_str);
    if(is_sub_string)
        printf("The substring exist\n");
    else
        printf("The subtring does not exist\n");
    
    printf("End of test_find_substring\n\n");
}

int main(){
    test_findsubstring();
    test_extract_string();
    return 0;
}