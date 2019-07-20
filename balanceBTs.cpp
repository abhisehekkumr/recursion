/*
     given height h find out total number of possible balanced binary trees that can
     be formed.

     for given perticular height number of height is related with

     height = x*x + 2*x*y;

     x --> height(h-1)
     y --> height(h-2)
*/

#include<bits/stdc++.h>
using namespace std;

int balanceBTs(int height){

     if(height == 1 || height == 0)
          return 1;

     int x = balanceBTs(height - 1);
     int y = balanceBTs(height - 2);

     int m = pow(10,9) + 7;
     long x1 = (long)x*x;
     long y1 = (long)x*y*2;

     int ans1 = (int)(x1%m);
     int ans2 = (int)(y1%m);
     return (ans1 + ans2)%m;
}

int main(){
     int h;
     cin >> h;
     cout << balanceBTs(h) << endl;
}
