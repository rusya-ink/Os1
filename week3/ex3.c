#include <stdio.h>
#include <stdlib.h>
struct linked_list{
    struct node * node;
};

struct node{
    int data;
    struct node *next;
};
void print_list_sub(struct node *list){
    if(list!=0){
        printf("%d\n", list->data);
        print_list_sub(list->next);
    }
}
void print_list(struct linked_list *list){
    print_list_sub(list->node);
}



void insert_node(struct linked_list *list, int data){
    struct node *node = malloc(sizeof (struct node));

    node->data=data;
    node->next=list->node;
    list->node=node;
}

void delete_node_sub(struct node * list, int data, struct node *prev){
    if(list!=0){
        if(list->data==data){
            prev->next=list->next;
            free(list);
        }else{
            delete_node_sub(list->next, data, list);
        }
    }
}
void delete_node(struct linked_list *list, int data){
    if(list->node!=0&&list->node->data==data){
        free(list->node);
        list->node=0;
    }else{
        delete_node_sub(list->node, data, list->node);
    }
}
int main()
{
    struct linked_list list;
    list.node=0;
    print_list(&list);
    insert_node(&list, 10);
    insert_node(&list, 30);
    insert_node(&list, 7);
    print_list(&list);
    delete_node(&list, 10);
    delete_node(&list, 11);
    delete_node(&list, 0);
    print_list(&list);
    delete_node(&list, 30);
    delete_node(&list, 7);
    print_list(&list);

}
