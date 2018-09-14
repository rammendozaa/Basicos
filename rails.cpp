#include <iostream>
#include <stack>
using namespace std;

bool compare(stack <int> sta, stack <int> B)
{
  if(sta.size() != B.size())
    return false;
  while(!sta.empty() && !B.empty())
  {
    if(sta.top() != B.top())
      return false;
    sta.pop();
    B.pop();
  }
  return true;
}

int main(void)
{
  bool igu;
  int auxInt, num, auxNum, auxTop, fijo;
  while(cin >> fijo && fijo != 0)// >> auxInt)
  {
    while(cin >> auxInt && auxInt != 0){
    stack <int> A, B, sta, aux, Bmin;
  
    auxNum = fijo;
    B.push(auxInt);
    A.push(auxNum);
    auxNum--;
    for(int i = 0 ; i < fijo - 1 ; i++)
    {
      cin >> auxInt;
      B.push(auxInt);
      A.push(auxNum);
      auxNum--;
    }
    stack <int> copia(B);
    while(!copia.empty())
    {
      Bmin.push(copia.top());
      copia.pop();
    }
    while(!A.empty() && !Bmin.empty())// && !Bmin.empty() && !aux.empty())
    {
      if(A.top() == Bmin.top())
      {
        sta.push(A.top());
        A.pop();
        Bmin.pop();
      }
      else if(!aux.empty() && !Bmin.empty() && aux.top() == Bmin.top())
      {
        sta.push(aux.top());
        aux.pop();
        Bmin.pop();
      }
      else
      {
        aux.push(A.top());
        A.pop();
      }
    }
    while(!aux.empty() && !Bmin.empty())
    {
      if(aux.top() == Bmin.top())
      {
        sta.push(aux.top());
        aux.pop();
        Bmin.pop();
      }
      else
        break;
    }
    igu = compare(B, sta);
    if(igu == true)
      cout<<"Yes"<<"\n";
    else
      cout<<"No"<<"\n";
    }
    cout << "\n";
  }
  return 0;
}