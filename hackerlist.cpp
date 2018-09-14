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
		Node *aux1;
		if(head -> next == NULL)
			cout<<head->data;
		else
		{
			int contador = 0;
			aux = head;
			aux1 = head -> next;
			while(aux)	
			{
				cout<<aux->data;
				aux = aux -> next;
				contador++;
			}
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
	void alreves()
	{
		if(head -> next == NULL)
			cout<<head->data;
		else
		{
	        	Node *aux1 = head;
	        	Node *aux2 = head -> next;
			Node *auxiliar = head;
			head -> next = NULL;
			while(aux2 -> next)
			{
//				cout<<aux1->data<<" "<<aux2->data<<'\n';
				aux1 = aux2;
				aux2 = aux2 -> next;
				aux1 -> next = auxiliar;
				auxiliar = aux1;		
			}	
			aux2 -> next = aux1;
			head = aux2;	
//			head -> next = aux2 -> next;
		}
	}		

	void borrar(int pos)
	{
		int contador = 0;
		if(head -> next == NULL)
			head = NULL;
		else if(pos == 0)
			head = head -> next;
		else
		{
			Node *aux;
			Node *otro = head;
			while(contador < pos - 1)
			{
				contador++;
				otro = otro -> next;
			}
			otro -> next = otro -> next -> next;
		}
	}
/*
	void juntarord(Linked)
	{
		Node *auxA = headA;
		Node *auxB = headB;
		Node *auxiliar;
		if(auxA == NULL)
			
		else if(auxB == NULL)
		
		else
		{
			while(auxA && auxB)
			{
				if(auxA -> data >= auxB -> data)
					auxiliar = auxA;
				else 
					auxiliar = auxB;
				auxA = auxA -> next;
				auxB = auxB -> next;
			}
		}
	}
*/
};

int main() {

  LinkedList<char> * valores = new LinkedList<char>();
  LinkedList<char> * valores1 = new LinkedList<char>();
  LinkedList<char> * valores2 = new LinkedList<char>();
  string cad1, cad2;
  int i;
  int j;
  int aux1,aux2;
  cin>>cad1;
  cin>>cad2;
  aux2 = 0;
	for(i = 0; i<cad1.length() ; i++)
	{
		
		valores -> push_back(cad1[i]);
	}
	for(i = 0; i<cad2.length() ; i++)
	{
		valores1 -> push_back(cad2[i]);
	
	}       

/*
	 while(i<tam)
        {

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
		}
		valores -> push_back(cad[i]);
		i++;
        }
*/
//	valores -> prints();
  //      valores -> ultimo();
//	valores -> borra(0);
//	cout<<'\n';
//	valores -> prints();
/*	valores -> prints();
	cout<<'\n';
	valores -> alreves();
	valores -> prints(); 
	cout<<'\n';
	valores -> alreves();
	valores -> borrar(1);
	valores -> prints(); 
	cout<<'\n';
*/
	valores2 = juntarord(valores, valores1)
	valores2 -> prints();
	cout<<'\n';
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
