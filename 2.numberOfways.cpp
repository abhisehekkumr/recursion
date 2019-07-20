/*
Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N'
using the sum of the given three numbers.
*/

/*
     As this is recurive solution with complexity almost 3^n
     thats why it's speed will decrease exponentially for giving result as
     n will slowly increase
*/
long long ways(long long n){


     if(n < 0)
          return 0;

     if(n == 0)
          return 1;
     return ways(n-1) + ways(n-3) + ways(n-5);
}

#include<iostream>
using namespace std;

int main(){
     long long n;
     cin >> n;
     std::cout << ways(n) << '\n';
}
