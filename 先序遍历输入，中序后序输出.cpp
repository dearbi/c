#include <bits/stdc++.h>
using namespace std;

struct node {
    char data;
    shared_ptr<node> lch, rch;
};

using bitree = shared_ptr<node>;

// 先序输入构造二叉树
bitree creat() {
    char x;
    cin >> x;
    if (x == '#') return nullptr; // '#' 表示空节点

    bitree t = make_shared<node>();
    t->data = x;
    t->lch = creat(); // 递归构造左子树
    t->rch = creat(); // 递归构造右子树
    return t;
}

// 中序遍历
void inorder(bitree t) {
    if (t == nullptr) return;
    inorder(t->lch);
    cout << t->data << " ";
    inorder(t->rch);
}

// 后序遍历
void postorder(bitree t) {
    if (t == nullptr) return;
    postorder(t->lch);
    postorder(t->rch);
    cout << t->data << " ";
}

int main() {
    // 先序输入构建二叉树
    bitree t = creat();

    // 输出中序遍历
    cout << "Inorder: ";
    inorder(t);
    cout << endl;

    // 输出后序遍历
    cout << "Postorder: ";
    postorder(t);
    cout << endl;

    return 0;
}
