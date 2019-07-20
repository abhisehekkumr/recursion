/*
given 2D matrix of cost find minimum cost required to go to location
0,0 to m,n
*/

#include<bits/stdc++.h>
using namespace std;

int minCost(int **input, int si, int sj, int ei, int ej){

     if(sj == ej && si == ei)
          return input[ei][ej];

     if(sj > ej || si > ei)
          return INT_MAX;

     int opetion1 = minCost(input,si + 1, sj, ei,ej);
     int opetion2 = minCost(input,si + 1, sj + 1, ei,ej);
     int opetion3 = minCost(input,si, sj + 1, ei,ej);
     return input[si][sj] + min(opetion1, min(opetion2, opetion3));
}

int main(){

     int n,m;
     cin >> n >> m;

     int **input = new int*[n];
     for(int i = 0; i < n; i++)
          input[i] = new int[m];

     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++)
               cin >> input[i][j];
     }

     std::cout << minCost(input,0,0,n-1,m-1) << '\n';

     for(int i = 0; i < n; i++)
          delete [] input[i];
     delete [] input;
     return 0;
}
