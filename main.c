#include <stdio.h>
#include "list.h" 

list* readNumbers(){
    int value;
    list* pointer = NULL;
    puts("Type numbers:\n");
    while(scanf("%d", &value) != EOF){
        if(pointer == NULL) pointer = list_create(value);
        else pointer = list_add_front(value, pointer);
    }
    return pointer;
}

void printList(list* pointer){
    size_t index = 0;
    while(pointer->next != NULL){
        printf("Value %zu:%d\n", index, pointer->val);
        index++;
        pointer = pointer->next;
    }
}

void printValue(list* pointer){
    size_t index;
    puts("Write index of element");
    int console = scanf("%zu", &index);
    while(1){
        while(console != EOF && console != 0){
            printf("Value for your index %zu: %d\n", index, list_get(index, pointer));
            puts("Write index of element");
            console = scanf("%zu", &index);
        }
        if(console == EOF) break;
    }
}

int main(){
    list* pointer = readNumbers();
    printList(pointer);
    printf("Sum of elements:%li\n",list_sum(pointer));
    printValue(pointer);
    list_free(pointer);
}