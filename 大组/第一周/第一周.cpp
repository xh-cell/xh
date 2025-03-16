//单链表 ADT 
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义单链表结构
typedef struct SinglyLinkedList {
    Node* head;
} SinglyLinkedList;

// 初始化单链表
void initList(SinglyLinkedList* list) {
    list->head = NULL;
}

// 在链表头部插入节点
void insertAtBeginning(SinglyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

// 在链表尾部插入节点
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

// 显示链表内容
void displayList(SinglyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//双向链表 ADT
#include <stdio.h>
#include <stdlib.h>

// 定义双向链表节点结构
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// 定义双向链表结构
typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

// 初始化双向链表
void initDList(DoublyLinkedList* list) {
    list->head = NULL;
}

// 在双向链表头部插入节点
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

// 在双向链表尾部插入节点
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

// 显示双向链表内容
void displayDList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
