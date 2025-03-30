// 此错误通常是由于IDE的include路径配置不正确导致的。要修复此问题，需要更新includePath。
// 以下是一些可能的解决步骤：
// 1. 确保你的编译器已经正确安装，并且其包含文件目录已经正确配置。
// 2. 在Trae IDE中，运行“选择IntelliSense配置...”命令，以定位系统标头。
// 3. 如果问题仍然存在，你可以手动在IDE的配置文件中添加编译器的包含文件目录。

// 假设你已经正确配置了includePath，以下是修复后的代码：
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 头插法
void head_insert(Node** head, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

// 尾插法
typedef struct LinkedList {
    Node* head;
    Node* tail;  // 专门记录尾节点
} LinkedList;

void tail_insert_opt(LinkedList* list, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// 1. 链表反转
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 2. 查找链表中间节点
Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 3. 判断链表是否有环
int hasCycle(Node* head) {
    if (head == NULL) return 0;
    Node* slow = head;
    Node* fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) return 0;
        slow = slow->next;
        fast = fast->next->next;
    }
    return 1;
}

// 4. 查找并删除元素
void deleteElement(Node** head, int val) {
    Node* temp = *head, *prev;
    if (temp != NULL && temp->data == val) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// 5. 在某位置插入一个新节点
void insertAtPosition(Node** head, int val, int position) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    if (position == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("插入位置超出链表长度\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // 测试头插法
    Node* head = NULL;
    head_insert(&head, 3);
    head_insert(&head, 2);
    head_insert(&head, 1);
    printf("头插法创建的链表: ");
    printList(head);

    // 测试链表反转
    Node* reversedHead = reverseList(head);
    printf("反转后的链表: ");
    printList(reversedHead);

    // 测试尾插法
    LinkedList list = {NULL, NULL};
    tail_insert_opt(&list, 4);
    tail_insert_opt(&list, 5);
    tail_insert_opt(&list, 6);
    printf("尾插法创建的链表: ");
    printList(list.head);

    // 测试查找中间节点
    Node* middle = middleNode(list.head);
    printf("中间节点的值: %d\n", middle->data);

    // 测试判断链表是否有环
    int cycle = hasCycle(list.head);
    printf("链表是否有环: %s\n", cycle ? "是" : "否");

    // 测试查找并删除元素
    deleteElement(&list.head, 5);
    printf("删除元素 5 后的链表: ");
    printList(list.head);

    // 测试在某位置插入一个新节点
    insertAtPosition(&list.head, 7, 1);
    printf("在位置 1 插入元素 7 后的链表: ");
    printList(list.head);

    return 0;
}