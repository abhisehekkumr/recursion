#include<bits/stdc++.h>
using namespace std;

void printNumbers(int n, int k = 1){

     if(k > n)
          return;

     for(int i = 0; i < 10; i++){

          if(k <= n){
               std::cout << k << '\n';
               printNumbers(n,k*10);
               k++;

               if(k%10 == 0)
                    return;
          }
     }
}

int main(){
     int n;
     std::cin >> n;
     printNumbers(n);
}
