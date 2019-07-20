/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
You need to figure out the total number of ways W, in which you can make change for Value V using coins of
denominations D.
Note : Return 0, if change isn't possible.
*/

#include<iostream>
using namespace std;

int coinChange(int n, int denominations[], int size){

     if(n == 0)
          return 1;

     if(n < 0)
          return 0;

     if(size == 0)
          return 0;

     int first = coinChange(n-denominations[0],denominations,size);
     int second = coinChange(n,denominations + 1, size -1);
     return first + second;
}
int main(){

     int d;
     cin >> d;

     int arr[d];

     for(int i = 0; i < d; i++)
          cin >> arr[i];
     int n;
     cin >> n;
     std::cout << coinChange(n,arr,d) << '\n';
}
