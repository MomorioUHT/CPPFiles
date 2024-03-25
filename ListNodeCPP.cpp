#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void insertNode(Node** p, int x) {
    Node* dummy = new Node;
    dummy->val = x;
    dummy->next = NULL;

    if (*p == NULL) {
        *p = dummy;
    } else {
        Node* current = *p;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = dummy;
    }
}

int main() {
    Node *p = NULL;
    int insVal = 0;
    while (1) {
        cin >> insVal;
        if (insVal < 0) break;
        insertNode(&p, insVal);
    }
    cout << "Print this list" << endl;
    
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
}