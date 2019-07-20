#include<iostream>
using namespace std;

long long paths(int n, char p = 'b', char pp = 'c'){

     if( n == 0 || n == 1)
          return n;

     if(pp == 'w' && p == 'b')
          return paths(n-1,'r','b');

     if(pp == 'r' &&  p == 'b')
          return paths(n-1,'w','b');

     if(p == 'w')
          return paths(n-1,'r','w') + paths(n-1,'b','w');

     if(p == 'r')
          return paths(n-1,'w','r') + paths(n-1,'b','r');

     if(pp == 'c')
          return paths(n-1,'r','b') + paths(n-1,'w','b');
     return  0;
}

int main(){
     int n;
     cin >> n;
     std::cout << paths(n) << '\n';
}
