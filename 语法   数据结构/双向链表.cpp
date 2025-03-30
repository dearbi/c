#include <bits/stdc++.h>
#include <memory>

using namespace std;

struct Node
{
    int data;
    shared_ptr<Node> next; // 使用 shared_ptr 管理下一个节点
    weak_ptr<Node> fr; // 使用 weak_ptr 避免循环引用

    Node(int val) : data(val), next(nullptr) {} // 构造函数初始化数据成员
};

void createList(shared_ptr<Node>& head, int n) {
    shared_ptr<Node> tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        auto newnode = make_shared<Node>(num);
        if (!head) {
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            newnode->fr = tail;
            tail = newnode;
        }
    }
}

shared_ptr<Node> search(const shared_ptr<Node>& head, int key) {
    auto p = head;
    while (p) {
        if (p->data == key) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void display(const shared_ptr<Node>& head, const shared_ptr<Node>& p) {
    if (p->next && !p->fr.expired()) { // 前驱和后继都存在
        auto fr = p->fr.lock(); // 从 weak_ptr 转换到 shared_ptr
        printf("%d %d\n", fr->data, p->next->data);
    } else if (p->next) { // 只有后继
        printf("%d\n", p->next->data);
    } else if (!p->fr.expired()) { // 只有前驱
        auto fr = p->fr.lock();
        printf("%d\n", fr->data);
    } else {
        printf("\n"); // 当前节点既没有前驱也没有后继
    }
}

int main() {
    int n, m, key;
    scanf("%d %d", &n, &m); // 读取节点数量和查询次数
    shared_ptr<Node> head = nullptr; // 初始化为空指针

    createList(head, n); // 创建链表

    for (int i = 0; i < m; ++i) {
        scanf("%d", &key);
        auto p = search(head, key);
        if (p) {
            display(head, p);
        } else {
            printf("Node with data %d not found.\n", key);
        }
    }

    return 0;
}