#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    shared_ptr<node> next;
    node(int val) : data(val), next(nullptr) {}
};

void nodelist(shared_ptr<node>& head, int len) {
    shared_ptr<node> tail = nullptr;
    for (int i = 0; i < len; i++) {
        int x; cin >> x;
        auto newnode = make_shared<node>(x);
        if (head == nullptr) {
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
}

int main() {
    shared_ptr<node> head = nullptr;
    int n; cin >> n;
    nodelist(head, n);

    // Count even and odd numbers
    int c1 = 0, c2 = 0;
    shared_ptr<node> current = head;
    while (current != nullptr) {
        if ((current->data) % 2 == 0) c1++;
        else c2++;
        current = current->next;
    }
    cout << c1 << " " << c2 << endl;

    // Print even numbers
    current = head;
    bool first = true;
    while (current != nullptr) {
        if ((current->data) % 2 == 0) {
            if (!first) cout << " ";
            cout << current->data;
            first = false;
        }
        current = current->next;
    }
    cout << "\n";

    // Print odd numbers
    current = head;
    first = true;
    while (current != nullptr) {
        if ((current->data) % 2 != 0) {
            if (!first) cout << " ";
            cout << current->data;
            first = false;
        }
        current = current->next;
    }
    cout << "\n";

    return 0;
}