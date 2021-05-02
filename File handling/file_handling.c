/*  file_handling.c contains functions that can create, append, read,
    encrypt and decrypt files.
*/

#include <stdio.h>
#include <stdlib.h>
    const int SIZE = 1000;
    const int NAME_SIZE = 20;

void check_file_ptr(FILE *fptr, int i){
    if(fptr == NULL){
        printf("Error opening the file.");
        exit(i);
    }
}

void create_file(){
    char str[SIZE];
    FILE *fptr;
    char fname[NAME_SIZE];
    printf("Enter the name of the file that you want to create\n");
    scanf("%s", fname);
    int c = getc(stdin);
    fptr = fopen(fname, "w");
    check_file_ptr(fptr, 1);

    printf("Input a string to store in the file\n");
    fgets(str, SIZE, stdin);
    fprintf(fptr, "%s", str);
    fclose(fptr);

    printf("The file %s was succesfully created\n", fname);
}

void append_string(){
    char str[SIZE];
    FILE *fptr;
    char fname[] = "test.txt";

    fptr = fopen(fname, "a");
    check_file_ptr(fptr, 1);

    printf("Input a string to append to the file\n");
    fgets(str, SIZE, stdin);
    fprintf(fptr, "%s", str);
    fclose(fptr);
}
void print_file(FILE *fptr){
    char c;
    while((c = fgetc(fptr)) != EOF)
        printf("%c", c);
    printf("\n");
}
void read_file(){
    FILE *fptr;
    char fname[NAME_SIZE];

    printf("Enter the name of the file you want to read from\n");
    scanf("%s", fname);
    fptr = fopen(fname, "r");
    check_file_ptr(fptr, 1);
    print_file(fptr);
    fclose(fptr);
}

void delete_file(char *fname) {
    int file_status = remove(fname);
    if(file_status == 0)
        printf("The file '%s' was successfully deleted\n", fname);
    else
        printf("The file '%s' was not successfully deleted\n", fname);
}

void copy_file(FILE *fptr, FILE *ftmp, int encrypt){
    char c;
    while((c = fgetc(fptr)) != EOF)
        fputc(c + encrypt, ftmp);
    
    fclose(fptr);
    fclose(ftmp);
}
void encrypt_file(int encrypt){
    FILE *fptr, *ftmp;
    char fname[NAME_SIZE];
    char ftmp_name[NAME_SIZE];
    printf("Enter the name of the file you want to encrypt\n");
    scanf("%s", fname);
    printf("Enter a name that can be used as a temporary file\n");
    scanf("%s", ftmp_name);

    fptr = fopen(fname, "r");
    check_file_ptr(fptr, 1);
    ftmp = fopen(ftmp_name, "w");
    check_file_ptr(ftmp, 2);
    copy_file(fptr, ftmp, encrypt);
   

    fptr = fopen(fname, "w");
    check_file_ptr(fptr, 4);
    ftmp = fopen(ftmp_name, "r");
    check_file_ptr(ftmp, 5);
    copy_file(ftmp, fptr, 0);
    delete_file(ftmp_name);
    
}

void decrypt_file(int decrypt){
    FILE *fptr, *ftmp;
    char fname[NAME_SIZE];
    char ftmp_name[NAME_SIZE];
    printf("Enter the name of the file you want to decrypt\n");
    scanf("%s", fname);
    printf("Enter a name that can be used as a temporary file\n");
    scanf("%s", ftmp_name);

    fptr = fopen(fname, "r");
    check_file_ptr(fptr, 1);
    ftmp = fopen(ftmp_name, "w");
    check_file_ptr(ftmp, 2);
    copy_file(fptr, ftmp, decrypt);
   

    fptr = fopen(fname, "w");
    check_file_ptr(fptr, 4);
    ftmp = fopen(ftmp_name, "r");
    check_file_ptr(ftmp, 5);
    copy_file(ftmp, fptr, 0);
    delete_file(ftmp_name);
}

void test_create_file(){
    create_file();
}
void test_read_file(){
    read_file();
}
void test_append_string(){
    append_string();
    read_file();
}
void test_delete_file(){
    char fname[NAME_SIZE];
    printf("Enter the name of the file you want to delete\n");
    scanf("%s", fname);
    delete_file(fname);
}
void test_encrypt_file(){
    create_file();
    encrypt_file(100);
    read_file();
}

void test_decrypt_file(){
    decrypt_file(-100);
    read_file();
}
int main(){
    //test_create_file();
    //test_read_file();
    //test_append_string();
    //test_delete_file();
    test_encrypt_file();
    test_decrypt_file();
    
    return 0;
}