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
        printf("Memory allocation error");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
Node* createList( int n) {
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
void printList(Node* head) {
    Node* current = head;
    printf("NULL<-->");
    while (current != NULL) {
        printf("%d <--> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;

    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Enter number of elements: ");
        scanf("%d", &n);
        if (n<=0) {
            printf("Nhap lai \n");
        }
    }

    Node* head = createList(n);
    printList(head);
    int add;
    printf("Enter number of elements: ");
    scanf("%d", &add);
    head = insertEnd(head, add);
    printList(head);

    return 0;
}