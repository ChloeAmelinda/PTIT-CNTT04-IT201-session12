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
Node* createList(int n) {
    int value;
    printf("Enter number of nodes: ");
    scanf("%d", &value);
    Node* head = createNode(value);
    Node* current = head;
    for (int i = 2; i <= n; i++) {
        printf("Enter number of nodes%d: ",i);
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
        printf("%d<--> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//xoa
Node* deleteNode(Node* head,int number) {
    Node* current = head;
    Node* temp;
    while (current != NULL) {
        if (current->data == number) {
            temp = current;
            if (current ==head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }else {
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                }
            }
            current=current->next;
            free(temp);
        }else {
            current = current->next;
        }
    }
    return head;
}
int main(void) {
    int n=0;
    while (n<=0) {
        printf("Enter number: ");
        scanf("%d", &n);
        if (n<=0) {
            printf("Invalid input\n");
        }

    }
    Node* head = createList(n);
    printList(head);
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    head = deleteNode(head,number);
    printList(head);
    return 0;
}