#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;//c++代替的strcut *Node next;
    Node(int val) : data(val), next(nullptr) {}
};

void Insert(shared_ptr<Node>& head, int m, int x) {
    auto newNode = make_shared<Node>(x);
    auto p = head;
    int count = 0;

    // 遍历至第m个节点
    while (p->next && count < m) {
        p = p->next;
        ++count;
    }
    // 插入新节点
    newNode->next = p->next;
    p->next = newNode;
}

int main() {
    int n;
    while (cin >> n) {  // 每组数据开始
        auto head = make_shared<Node>(-1); // 使用哑节点简化边界情况处理

        for (int i = 0; i < n; ++i) {
            int m, x;
            cin >> m >> x;
            Insert(head, m, x);
        }

        for (auto c = head->next; c != nullptr; c = c->next) {
            cout << c->data;
            if(c->next!=nullptr)
                cout<<" ";
        }
        cout << endl; // 完成一组数据的输出
    }
    return 0;
}