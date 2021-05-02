# Random_C
Some random C code to learn how to better work with C code.
## File handling
### file_handling.c
This file contains functions that can create, append, read, encrypt and decrypt files.

## Working with Strings
### adding_arrays.c
The purpose of this code was to get a better understanding of how to concatenate arrays. There are already functions in C which can do this for us, for example strcat(array1, array2). This function is however not safe because there is no limit of how many characters that are added to the first array from the second array. strncat(array1, array2, size_limit) which limites how many characters that are added to array1 is a safer options.

#### Why write my own function?
Because I get more control and it is easy to modify the function to only grab certain characters or parts of an array. It is also easy to update the function so that it can take in more array arguments and add them all togater in the same function.

### rev_string.c
The functions in this file either reverses the entire string or reverses each word but keeps the order of the words.

### frequency_list.c
This program takes in a string from the user, then it finds the character that occurred the most and appends it to a single linked list. If more then one charcter occurres with the highest frequency, then those characters are added to the linked list. 

ascii[250] is an array where each index represents the corresponding ascii character The integer stored at one index represents the number of times that character was found in the string. You can think of it as each slot in the array is a key value pair where the key is the index and the value is the integer stored at that index.

### bubble_sort_2D_strings.c
This program asks the user for a certain amount of strings, then the strings are sorted with bubble sort in ascending order. The program will exit the sorting loop as soon as all of the strings are sorted, that is, the loop will only iterate once if all of the strings are sorted to begin with. This is done to reduce the time complexity if the strings are already sorted or partially sorted directly after they have been inputed by the user. The number of swaps are also counted and printed out. 

### extract_substring.c
This program can extract a part of a string and copy it to a new allocated memory. Another fnction is to scan a string to find out if a perticular substring exist. The algorithm has a worst case time complexity of O(N).
