#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void insertSortNode(Node** p, int x) {
    Node* dummy = new Node;
    dummy->val = x;
    dummy->next = NULL;

    if (*p == NULL) { //Empty List
        dummy->next = *p;
        *p = dummy;
    } else {
        Node* current = *p;
        while (current->next != NULL && current->next->val < x) {
            current = current->next;
        }
        dummy->next = current->next;
        current->next = dummy;
    }
}

int main() {
    Node *p = NULL;
    int insVal = 0;
    while (1) {
        cin >> insVal;
        if (insVal < 0) break;
        insertSortNode(&p, insVal);
    }
    cout << "Print the list node" << endl;
    
    while (p != NULL) {
        if (p->next == NULL) cout << p->val;
        else cout << p->val << "-";
        p = p->next;
    }
}