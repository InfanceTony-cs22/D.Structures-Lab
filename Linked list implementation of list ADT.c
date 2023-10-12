#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct List* createList() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

void insert(struct List* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void display(struct List* list) {
    struct Node* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct List* myList = createList();

    insert(myList, 10);
    insert(myList, 20);
    insert(myList, 30);

    display(myList);

    return 0;
}
