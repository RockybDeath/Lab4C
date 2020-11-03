#include <malloc.h>
#include "list.h"

list* list_create(int x){
    return list_add_front(x, NULL);
}

list* list_add_front(int x, list* pointer){
    list* node = (list*) malloc(sizeof(list));
    node->next = pointer;
    node->val = x;
    return node;
}

void list_add_back(int x, list* pointer){
    while(pointer->next != NULL) pointer = pointer->next;
    pointer->next = list_add_front(x, NULL);
}

void list_free(list* pointer){
    while(pointer != NULL){
        list* next = pointer->next;
        free(pointer);
        pointer = next;
    }
    puts("Memory was free");
}

size_t list_length(list* pointer){
    size_t count = 0;
    while(pointer != NULL){
        count++;
        pointer = pointer->next;
    }
    return count;
}

long list_sum(list* pointer){
    long sum = 0;
    while (pointer != NULL){
        sum+= pointer->val;
        pointer = pointer->next;
    }
}

list* list_node_at(size_t index, list super_list){
    size_t i;
    list* pointer = super_list.next;
    for(i=0; i < index; i++){
        if(pointer->next == NULL) return NULL;
        pointer = pointer->next;
    }
    return pointer;
}

int list_get(size_t index, list* pointer){
    list super_list = {pointer->val,pointer->next};
    list* search = list_node_at(index, super_list);
    if( search == NULL) return 0;
    else return search->val;
}