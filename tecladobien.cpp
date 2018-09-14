#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T> struct LinkedList {

  struct Node {
    Node * next;
    T data;
    Node(T val) {
      next = NULL;
      data = val;
    }
  };

  Node * head;
  Node * tail;
  int size;

  LinkedList() {
    tail = head = NULL;
    size = 0;
  }

  void push_back(T val) {
    Node * node = new Node(val);
    if (size == 0) {
      tail = head = node;
    }
    else {
      tail->next = node;
      tail = node;
    }
    size++;
  }

  void pop_back() {
    if (size == 0) {
      throw runtime_error("Cannot erase from the empty list");
    }
    if (size == 1) {
      head = tail = NULL;
    }
    else {
      Node * prev = head;
      Node * last = head->next;
      while (last && last->next) {
        last = last->next;
        prev = prev->next;
      }
      prev->next = NULL;
      tail = prev;
    }
    size--;
  }

  bool exists(T val) {
    if (size == 0) {
      return false;
    }
    Node * current = head;
    while (current) {
      if (current->data == val) {
        return true;
      }
      current = current->next;
    }
    return false;
  }
	void prints(){
		int auxs = size;
		Node *aux;
		aux = head;
//		aux -> next = head -> next;
		while(auxs > 0)
		{
			cout<<aux -> data;
			aux = aux -> next,
			auxs--;
		}
	}
	void push_front(T val){
		Node * node = new Node(val);
		node -> next = head;
		head = node;
		size++;
	}	
	
	void ultimo(){
		Node *aux, *prev, *last;
		prev = head;
		int counter,i;
		counter = 0;
		while(prev)
		{
			prev = prev -> next;
			counter++;
		}
		cout<<" "<<counter;
		last = head;
		for(i=0;i<counter-1;i++)
		{
			last = last -> next;//head = head -> next;
		}
		cout<< last-> data;
	}
	void borra(int pos){
		int contador = 0;
		Node *aux;
		aux = head;
		while(aux)
		{
			if(pos == 0)
			{
				aux = aux -> next;
				aux -> next = aux -> next -> next;
				break;//	return 0;
			}
			else if(contador == pos -2)
			{
				aux = aux -> next;
				aux -> next = aux -> next -> next;
				break; //return 0;
			}
			else
			{
				contador++;
				aux = aux -> next;
			}
			cout<<contador;
		}
/*		size--;
		Node *imp;
	//	imp= head;
		int auxs = size;
		while(auxs > 0)
		{
			cout<<imp -> data;
			imp = imp -> next;
			auxs--;
		}
*/		}
};

int main() {

  LinkedList<char> * valores = new LinkedList<char>();
  string cad;
  int i = 0;
  int j;
  int aux1,aux2;
  cin>>cad;
  aux2 = 0;
  int tam = cad.length();
        while(i<tam)
        {
/*
                if(cad[i] == '[')
                {
                        aux1 = i;
                        j = i;
                        while(cad[j] != ']')
                                j++;
                        aux2 = j;
			j--;
			while(j > aux1)
                        {
				if(cad[j] == '[')
				{
					i=j;
					break;
				}
                                valores -> push_front(cad[j]);
                                j--;
                        }
			i = aux2 + 1;
                }
		else if(cad[i] == ']')
			i++;
		else
		{
			i = aux2; 
			valores -> push_back(cad[i]);
                	i++;
			aux2++;
		}*/
		valores -> push_back(cad[i]);
		i++;
        }
//	valores -> prints();
  //      valores -> ultimo();
	valores -> borra(0);
	cout<<'\n';
//	valores -> prints();


/*
  list->push_back(1);
  if (list->exists(1))
    cout << ":)" << endl;
  cout << list->size << endl;
  list->pop_back();
  if (!list->exists(1))
    cout << ":(" << endl;
  cout << list->size << endl;
 */ return 0;
}
