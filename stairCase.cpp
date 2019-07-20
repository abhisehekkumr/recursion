/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count how many possible ways the child can run up to the stairs.
 You need to return all possible number of ways.
Time complexity of your code should be O(n).
*/

#include<iostream>
using namespace std;


long long staircase(long long n){

     if(n < 0)
          return 0;

     if(n == 0 || n == 1)
          return 1;

     return staircase(n-1) + staircase(n-2) + staircase(n-3);
}
int main(){
     long long n;
     cin >> n;
     std::cout << staircase(n) << '\n';
}
