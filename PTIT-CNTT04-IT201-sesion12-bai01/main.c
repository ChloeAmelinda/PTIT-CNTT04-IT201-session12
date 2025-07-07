#include <stdio.h>
#include <stdlib.h>
//cau truc
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
//khoi tao
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


//ham do dai
int length(Node* node) {
    int count = 0;
    Node* current = node;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
Node* createLinked( int n) {
    int value;
    printf("Enter value node1: ");
    scanf("%d", &value);
    Node* head = createNode(value);
    Node* current = head;
    for (int i = 2; i <=n; i++) {
        printf("Enter value node%d: ", i);
        scanf("%d", &value);
        Node* newNode = createNode(value);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Please enter:");
        scanf("%d", &n);
        if (n<=0) {
            printf("Nhap lai");
        }
    }

    Node* head = createLinked(n);
    printList(head);

    return 0;
}