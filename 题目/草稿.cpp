#include <iostream>
#include <memory> // 包含 shared_ptr 所需的头文件
using namespace std;

struct ListNode {
    int data;
    shared_ptr<ListNode> next; // 使用 shared_ptr 替代原始指针

    // 构造函数
    ListNode(int x) : data(x), next(nullptr) {}
};

// 创建链表
void CreateList(shared_ptr<ListNode>& head, int len) {
    for (int i = 0; i < len; i++) {
        int num;
        cin >> num;
        // 使用构造函数初始化新节点
        auto newNode = make_shared<ListNode>(num);

        if (!head) {
            head = newNode;
        } else {
            auto p = head;
            while (p->next) {
                p = p->next;
            }
            p->next = newNode;
        }
    }
}

// 合并链表
void MergeList(const shared_ptr<ListNode>& La, const shared_ptr<ListNode>& Lb, shared_ptr<ListNode>& Lc) {
    auto dummy = make_shared<ListNode>(0); // 哑节点
    auto tail = dummy;
    auto pa = La;
    auto pb = Lb;

    while (pa && pb) {
        if (pa->data <= pb->data) {
            tail->next = pa;
            pa = pa->next;
        } else {
            tail->next = pb;
            pb = pb->next;
        }
        tail = tail->next;
    }

    // 连接剩余的节点
    tail->next = pa ? pa : pb;

    // 结果链表是从哑节点的下一个节点开始的
    Lc = dummy->next;
}

int main() {
    int M, N;
    cin >> M >> N;
    shared_ptr<ListNode> La = nullptr;
    CreateList(La, M);
    shared_ptr<ListNode> Lb = nullptr;
    CreateList(Lb, N);

    shared_ptr<ListNode> Lc = nullptr;
    MergeList(La, Lb, Lc);

    auto pc = Lc;
    while (pc) {
        cout << pc->data << " ";
        pc = pc->next;
    }
    cout << endl;

    return 0;
}