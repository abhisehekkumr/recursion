#include<iostream>
#define mod 1000000007
using namespace std;

long long balancedTrees(long long h){

     if(h == 0 || h == 1)
          return h;

     long long x = balancedTrees(h-1);
     long long y = balancedTrees(h-2);
     return ((x)%mod*x)%mod + ((2)%mod*(x*y)%mod)%mod;
}


int main(){
     int h;
     cin >> h;
     std::cout << balancedTrees((long long)h) << '\n';
}
