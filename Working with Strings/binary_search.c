#include <stdio.h>
#include <stdbool.h>

bool binary_search(int *arr, int size, int target){
    int low = 0;
    int high = size;
    int mid = (high - low) / 2;

    while(low <= high){
        mid = low + (high - low) / 2;
        if(arr[mid] == target)
            return true;

        else if(arr[mid] > target){
            high = --mid;
        }
        else if(arr[mid] < target){
            low = ++mid;
        }
        //printf("high = %d, low = %d\n", high, low);
    }
    return false;
}

void print_arr(int *arr, int size){
    int i;
    for(i = 0; i < size - 1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[i]);
}

int main(){
    int arr[] = {1,2,5,8,9,12,12,16};
    int size = *(&arr + 1) - arr;
    int target = -2;

    while(target++ < 20){
        if(binary_search(arr, size, target)){
            printf("%d was found in the array: ", target);
            print_arr(arr, size);
        }
        else{
            printf("%d was not found in the array: ", target);
            print_arr(arr, size);
        }
    }
    return 0;
}