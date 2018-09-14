#include <iostream>

using namespace std;

template<class T> struct Stack {

  struct Node {
    Node * next;
    T data;
    Node(T val) {
      next = NULL;
      data = val;
    }
  };

  Node * head;
  int size;

  Stack() {
    head = NULL;
    size = 0;
  }

  void push(T val) {
    Node * node = new Node(val);
    node->next = head;
    head = node;
    size++;
  }

  void pop() {
    if (size == 0)
      throw runtime_error("Cannot pop from the empty stack");
    head = head->next;
    size--;
  }

  T top () {
    if (size == 0)
      throw runtime_error("Cannot pop from the empty stack");
    return head->data;
  }

  bool isEmpty() {
    return size == 0;
  }
};


int main() {
  Stack<int> * stack = new Stack<int>();
  stack->push(5);
  stack->push(6);
  cout << stack->size << " " << stack->isEmpty() << " " << stack->top() << endl;
  stack->pop();
  cout << stack->size << " " << stack->isEmpty() << " " << stack->top() << endl;
  return 0;
}
