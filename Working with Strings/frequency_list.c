/* This program takes in a string from the user,
 * then it finds the character that occurred
 * the most and appends it to a single linked list.
 * If more then one charcter occurres with the highest
 * frequency, then those characters are added to the linked list. 
 * 
 * ascii[250] is an array where each index represents the corresponding ascii character
 * The integer stored at one index represents the number of times that character was found
 * in the string. You can think of it as each slot in the array is a key value pair where
 * the key is the index and the value is the integer stored at that index.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
}Node;

Node* create_node(char data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node *head = NULL;
Node *tail = NULL;
int num_nodes = 0;
void add_last(char data){
    if(num_nodes == 0){
        head = create_node(data);
        tail = head;
    }
    else{
        Node *new_node = create_node(data);
        tail->next = new_node;
        tail = new_node;
    }
    num_nodes++;
}

void print_list(int frequency){
    Node *temp = head;
    if(num_nodes <= 0){
        printf("List is empty");
       return;
    }
    else if(num_nodes == 1){
        printf("The character that appeared the most was: %c\n", temp->data);
        printf("It appeared %d number of times", frequency);
    }
    else{
        printf("These characters appeared the most: ");
        for(int i = 0; i < num_nodes - 1; i++){
            printf("%c, ", temp->data);
            temp = temp->next;
        }
        printf("%c\nThey appeared %d number of times each", temp->data, frequency);
    }
}
void find_duplicats(int *ascii, int max){
    int index = 0;
    for(int i = 1; i < 255; i++){
        if(ascii[i] == max){
            add_last((char)(i));
        }
    }
}

void init_zero(int *ascii){
    int i = 0;
    for(int i = 0; i < 255; i++){
        ascii[i] = 0;
    }
}

void set_key_value(int *ascii, char *str1){
    int i = 0;
    int index;
    while(str1[i] != '\0'){
        if(str1[i] == ' ' || str1[i] == '\n' || str1[i] == '\t'){
            i++;
            continue;
        }
        index = (int)(str1[i]);
        ascii[index]++;
        i++;
    }
}

int get_highest_frequency(int *ascii){
    int max = ascii[0];
    int index = 0;
    for(int i = 1; i < 255; i++){
        if(ascii[i] > max){
            max = ascii[i];
            index = i;
        }
    }
    return max;
}

/* ascii[250] is an array where each index represents the corresponding ascii character
 * The integer stored at one index represents the number of times that character was found
 * in the string. You can think of it as each slot in the array is a key value pair where
 * the key is the index and the value is the integer stored at that index.
*/
void char_frequency(char *str1){
    if(str1[0] =='\n'){
        printf("You did not enter anyting :/");
        return;
    }

    int ascii [255];
    init_zero(ascii);
    set_key_value(ascii, str1);

    int max = get_highest_frequency(ascii);
    find_duplicats(ascii, max);
    print_list(max);
}

int main()
{
    int str_size = 100;
    char str1 [str_size];
    printf("Enter a string plz\n");
    fgets(str1, str_size, stdin);
    char_frequency(str1);
    
    return 0;
}