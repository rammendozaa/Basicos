#include <iostream>
#include <string>
#include <vector>
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
	int casos;
	cin>>casos;
	string aux;
	  Stack<char> * pila;
	bool bal = true;
	while(casos>0)
	{
	string aux;
	  Stack<char> * pila;
	bool bal = true;
	  	pila = new Stack<char>();
	string aux;
	  Stack<char> * pila;
	bool bal = true;
		cin>>aux;
		for(char c:aux)
		{
				if (c == '{')
						pila -> push(c);
				else if (c == '[')
						pila -> push(c);
				else if (c == '(')
						pila -> push(c);
				else if (c == '}'){
						if(pila -> isEmpty())
						{
	bal = false;
							break;	
						}
						else if((pila -> top()) != '{')
						{
	bal = false;
							break;
						}
						else
							pila -> pop();
				}
				else if (c == ']'){
						if(pila -> isEmpty())
						{
	bal = false;
							break;	
						}
						else if((pila -> top()) != '[')
						{
	bal = false;
							break;
						}
						else
							pila -> pop();
				}
				else if (c == ')'){
						if(pila -> isEmpty())
						{
	bal = false;
							break;	
						}
						else if((pila -> top()) != '(')
						{
	bal = false;
							break;
						}
						else
							pila -> pop();
			cout<<"NO"<<'\n';:w
				}
		}
		if(pila -> isEmpty() && bal == true)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
		aux = "";
		casos--;
	}

  return 0;
}
