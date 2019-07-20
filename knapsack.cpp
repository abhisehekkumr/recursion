#include<bits/stdc++.h>
using namespace std;

int knapSack(int *w, int *v, int n, int maxWeight){

     if(n <= 0)
          return 0;

     if(maxWeight < 0)
          return 0;

     int ans1 = 0;
     if(maxWeight - w[0] >= 0)
          ans1 =  knapSack(w+1, v+1, n-1, maxWeight - w[0]) + v[0];
     int ans2 = knapSack(w + 1, v + 1, n -1, maxWeight);
     return max(ans1 , ans2);
}

int main(){
     int n;
     cin >> n;

     int w[n], v[n];
     for(int i = 0; i < n; i++)
          cin >> w[i];

     for(int i = 0; i < n; i++)
          cin >> v[i];

     int maxWeight;
     cin >> maxWeight;
     std::cout << knapSack(w,v,n,maxWeight) << '\n';
}

/*
wi
v

1 2 4 5
5 4 8 6
*/
