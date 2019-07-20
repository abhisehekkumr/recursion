#include<iostream>
using namespace std;

int minCost(int n){

     if(n <= 3)
          return n;

     int res = n;

     for(int i = 1; i <= n; i++){
          if(i*i > n)
               break;
          else
               res = min(res, 1+minCost(n - i*i));
     }
     return res;
}

int main(){
     int n;
     cin >> n;
     std::cout << minCost(n) << '\n';
}
