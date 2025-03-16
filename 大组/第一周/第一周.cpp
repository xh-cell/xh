//������ ADT 
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ���嵥����ṹ
typedef struct SinglyLinkedList {
    Node* head;
} SinglyLinkedList;

// ��ʼ��������
void initList(SinglyLinkedList* list) {
    list->head = NULL;
}

// ������ͷ������ڵ�
void insertAtBeginning(SinglyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

// ������β������ڵ�
void insertAtEnd(SinglyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// ��ʾ��������
void displayList(SinglyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//˫������ ADT
#include <stdio.h>
#include <stdlib.h>

// ����˫������ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// ����˫������ṹ
typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

// ��ʼ��˫������
void initDList(DoublyLinkedList* list) {
    list->head = NULL;
}

// ��˫������ͷ������ڵ�
void insertAtBeginningD(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head != NULL) {
        list->head->prev = newNode;
    }

    list->head = newNode;
}

// ��˫������β������ڵ�
void insertAtEndD(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// ��ʾ˫����������
void displayDList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
