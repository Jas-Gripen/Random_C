#include <stdio.h>

const int str_size = 100;
void revCase(char *str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (char)((int)(str[i]) + 32);
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = (char)((int)(str[i]) - 32);
        
        i++;
    } 

}

int main(){
    char str[str_size];

    printf("Enter a string plz\n");
    fgets(str, str_size, stdin);
    revCase(str);
    printf("%s", str);
    return 0;
}