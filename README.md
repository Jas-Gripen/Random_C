# Random_C
Some random C code to learn how to better work with C code.

## Working with Strings
### adding_arrays.c
The purpose of this code was to get a better understanding of how to concatenate arrays. There are already functions in C which can do this for us, for example strcat(array1, array2). This function is however not safe because there is no limit of how many characters that are added to the first array from the second array. strncat(array1, array2, size_limit) which limites how many characters that are added to array1 is a safer options.

#### Why write my own function?
Because I get more control and it is easy to modify the function to only grab certain characters or parts of an array. It is also easy to update the function so that it can take in more array arguments and add them all togater in the same function.
