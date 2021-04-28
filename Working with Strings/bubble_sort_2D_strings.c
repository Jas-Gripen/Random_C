/*
* This program asks the user for a certain amount of strings,
* then the strings are sorted with bubble sort in ascending order.
* The program will exit the sorting loop as soon as all of the
* strings are sorted, that is, the loop will only iterate once
* if all of the strings are sorted to begin with. The number
* of swaps are also counted and printed out. 
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int STR_SIZE1 = 25;
const int STR_SIZE2 = 50;

/* Return 1 if str1 > str2
* return -1 if str1 < str2
* return  0 if str1 = str2
*/
int str_cmpr(char *str1, char *str2){
    if(str1 == NULL || str2 == NULL){
        return -2;
    }
    int i = 0;
    while(str1[i] != '\0'){
        if(str1[i] > str2[i])
            return 1;
        else if(str2[i] > str1[i])
            return -1;
        i++;
    }
    if(str2[i] == '\0')
        return 0;
    else 
        return -1;
}

void swich(char *str1, char *str2){
    int i;
    char tmp;
    for(i = 0; i <= STR_SIZE2; i++){
        if(str1[i] == '\0'){
            str1[i] = str2[i];
            str2[i] = '\0';
            break;
        }
        if(str2[i] == '\0'){
            str2[i] = str1[i];
            str1[i] = '\0';
            break;
        }
        tmp = str1[i];
        str1[i] = str2[i];
        str2[i] = tmp;
    }

    if(str1[i] != '\0'){   
        i++;
        while(str2[i] != '\0'){
            str1[i] = str2[i];
            i++;
        }
        str1[i] = '\0';
        return;
    }

    else if(str2[i] != '\0'){
        i++;
        while(str1[i] != '\0'){
            str2[i] = str1[i];
            i++;
        }
        str2[i] = '\0';
        return;
    }
}

void bubble_sort(char str[][STR_SIZE2], int num_str, int STR_SIZE2){
    char tmp_buff[STR_SIZE2];
    bool isSorted = true;
    int count = 0;
    
    for(int i = 0; i < num_str; i++)
        for(int j = 0; j < num_str - i; j++){
            isSorted = true;
            if(str_cmpr(&str[j][0], &str[j + 1][0]) == 1){
                swich(&str[j][0], &str[j + 1][0]);
                isSorted = false;
                count++;
            }
        }
        if(isSorted){
            printf("Total number of swaps: %d\n", count);
            return;
        }
    printf("Total number of swaps: %d\n", count);
}

void print_array(char str[][STR_SIZE2], int num_str){
    printf("Sorting the strings in ascending order:\n");
	      for(int i = 0; i <= num_str; i++)
		    printf("%s",str[i]);
}

int main(){
    char str[STR_SIZE1][STR_SIZE2];
    int num_str;
    printf("Enter number of strings");
    scanf("%d", &num_str);

    for(int i = 0; i <= num_str; i++){
        fgets(str[i], STR_SIZE2, stdin);
    }
    printf("\n");

    bubble_sort(str, num_str, STR_SIZE2);
    print_array(str, num_str);
    return 0;
}