#include <iostream>
#include <list>
#include <string>
using namespace std;
int main(void)
{
  string linea, auxS, lista, cadena,s;
  int tam, i;
  list <string> carac;
  cin>>linea;
  cout<<linea<<endl;
    auxS = "";
    cadena = "";
    carac.erase(carac.begin(),carac.end());
    //for(int i = 0 ; i < tam ; i++)
    while(i < linea.length())
    {
      s = "";
      if(linea[i+1] == '[')
      {
        carac.push_back(auxS);
        i+=2;
        while(linea[i] != ']')
        {
          if(linea[i+1] == '[')
          {
            //i--;
            carac.emplace_front(s);
            break;
          }
          s += linea[i];
          i++;
        }
        carac.emplace_front(s);
/*        
          for(auto a: s)
            cout<<a;
          cout<<endl;
  */   
      }
      cout<<s<<endl;
      auxS += linea[i];
      carac.push_back(auxS); 
      i++;
      //for(auto a: carac)
        //  cout<<a;
    }
    for(auto a: carac)
       cout<<a;
    cout<<endl;

  return 0;
}



/*
for(auto a: list)
  cout<<a<<endl;


*/