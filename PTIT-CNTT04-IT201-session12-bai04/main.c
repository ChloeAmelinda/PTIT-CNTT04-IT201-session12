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
Node* createList(int size) {
    int node1;
    printf("Enter node1: ");
    scanf("%d", &node1);
    Node* head = createNode(node1);
    Node* current = head;
    for (int i = 2; i <= size; i++) {
        printf("Enter node%d: ", i);
        scanf("%d", &node1);
        Node* newNode = createNode(node1);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;

}
void printList(Node* head) {
    Node* current = head;
    printf("NULL");
    while (current != NULL) {
        printf("%d<-->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//xoa
Node* deleteEnd(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Please enter a number: ");
        scanf("%d", &n);
        if (n<=0) {
            printf("Nhap lai\n");
        }
    }
    Node* head = createList(n);
    printList(head);
    head = deleteEnd(head);
    printList(head);
    return 0;
}