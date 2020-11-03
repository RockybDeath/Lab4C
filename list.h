#ifndef _LIST_H_
#define _LIST_H_
typedef struct list{
    int val;
    struct list* next;
} list;

list* list_create(int);
list* list_add_front(int x, list* pointer);
void list_add_back(int x, list* pointer);
void list_free(list* pointer);
size_t list_length(list* pointer);
long list_sum(list* pointer);
list* list_node_at(size_t index, list super_list);
int list_get(size_t index, list* pointer);
#endif
