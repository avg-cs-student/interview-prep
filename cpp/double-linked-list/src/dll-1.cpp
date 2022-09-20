#include <iostream>

struct Node {
  Node *prev;
  Node *next;
  int key;
  int val;

  Node(int key, int val) : prev(nullptr), next(nullptr), key(key), val(val) {}
  ~Node() {}
};

class DLL {
private:
  int len;
  Node *head;
  Node *tail;

public:
  DLL() {
    this->head = new Node(-1, -1);
    this->tail = new Node(-2, -2);
    this->head->next = this->tail;
    this->tail->prev = this->head;
    this->len = 0;
  }

  void print_list() {
    Node *cur = this->head->next;
    while (cur != this->tail) {
      std::cout << "Node key: " << cur->key;
      std::cout << "\tNode val: " << cur->val << std::endl;
      cur = cur->next;
    }
  }

  void insert_at_front(Node *t) {
    t->prev = this->head;
    t->next = this->head->next;
    t->next->prev = t;
    t->prev->next = t;
    this->len++;
  }

  void push_to_back(Node *t) {
    t->next = this->tail;
    t->prev = this->tail->prev;
    t->prev->next = t;
    t->next->prev = t;
    this->len++;
  }

  ~DLL() {
    Node *target = this->head;
    while (target != this->tail) {
      this->head = this->head->next;
      delete(target);
      target = this->head;
    }
    delete(this->tail);
  }
};

int main() {
  DLL *myDll = new DLL();

  for (int i = 10; i > 0; i--) {
    myDll->insert_at_front(new Node(i,i)); 
  }

  for (int i = 11; i < 21; i++) {
    myDll->push_to_back(new Node(i,i)); 
  }

  myDll->print_list();

  delete(myDll);

  return 0;
}
