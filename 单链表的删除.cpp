#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;
    Node(int val) : data(val), next(nullptr) {}
};

// 创建链表（头插入）
void creatlist(shared_ptr<Node>& head, int n) {
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        auto newnode = make_shared<Node>(num);
        newnode->next=head;
        head=newnode;
    }
}

// 删除链表中的重复元素
int removeDuplicates(shared_ptr<Node>& head) {
    unordered_set<int> seen;
    shared_ptr<Node> current = head;
    shared_ptr<Node> prev = nullptr;
    int count = 0;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            // 当前节点是重复节点，跳过它
            prev->next = current->next;
            count++;
        } else {
            // 当前节点不是重复节点，添加到集合中
            seen.insert(current->data);
            prev = current;
        }
        current = current->next;
    }

    return count;
}

// 输出链表内容
void printList(const shared_ptr<Node>& head) {
    auto current = head;
    bool isFirst = true;
    while (current != nullptr) {
        if (!isFirst) {
            cout << " ";
        }
        cout << current->data;
        isFirst = false;
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    shared_ptr<Node> node1 = nullptr;
    creatlist(node1, n);

    // 输出原始链表
    cout<<n<<endl;
    printList(node1);

    // 删除重复元素并获取删除的节点数
    int count = removeDuplicates(node1);

    cout << n-count << endl;

    // 输出删除重复元素后的链表
    printList(node1);

    return 0;
}