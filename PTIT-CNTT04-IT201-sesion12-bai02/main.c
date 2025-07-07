#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Not enough space\n");
        return NULL;

    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
Node* createList(int n) {
    int value;
    printf("Enter number of elements: ");
    scanf("%d", &value);
    Node* head = createNode(value);
    Node* current = head;
    for (int i = 2; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &value);
        Node* newNode = createNode(value);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}



//ham in
void printList(Node* node) {
    Node* current = node;
    printf("NULL<-->");
    while (current != NULL) {
        printf("%d <--> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Enter number of elements: ");
        scanf("%d", &n);
        if (n<=0) {
            printf("Not enough space\n");
        }
    }
    Node* head = createList(n);
    printList(head);
    return 0;
}