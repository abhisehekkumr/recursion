#include<bits/stdc++.h>
using namespace std;

void getStrings(int n,vector<string> &v, int opening = 0, int closing = 0,string str = ""){
     if(closing == n && opening == n){
          //std::cout << "/* message */" << '\n';
          v.push_back(str);
          //std::cout << "/* message */" << '\n';
          return;
     }

     if(opening == n){
          getStrings(n,v,opening,closing+1,str + ')');
          return;
     }

     if(opening == closing){
          getStrings(n,v,opening+1,closing,str + '(');
          return;
     }

     getStrings(n,v,opening+1,closing,str + '(');
     getStrings(n,v,opening,closing+1,str + ')');
}

std::vector<string>* findParenthesis(int n)
{

    std::vector<string> v;
    getStrings(n,v);

    std::vector<string> *vs = new std::vector<string>();
    for(int i = 0; i < v.size(); i++)
          (*vs).push_back(v[i]);
    return vs;
}

int main(){
     int n;
     cin >> n;

     vector<string> *v = findParenthesis(n);
     for(int i = 0; i < v->size(); i++)
          std::cout << (*v)[i] << '\n';
}
