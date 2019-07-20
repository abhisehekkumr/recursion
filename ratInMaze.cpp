#include<iostream>
using namespace std;

void ratShowMePaths(int arr[3][3], int n, int flag [3][3], int x = 0, int y = 0){

     if(x == n-1 && y == n-1){
          flag[x][y] = 1;
          for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++)
                    std::cout << flag[i][j] << ' ';
               std::cout << '\n';
          }
          std::cout << '\n';
          return;
     }

     if(x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0 || flag[x][y] == 1)
          return;

     flag[x][y] = 1;
     ratShowMePaths(arr,n,flag,x+1,y);
     ratShowMePaths(arr,n,flag,x-1,y);
     ratShowMePaths(arr,n,flag,x,y+1);
     ratShowMePaths(arr,n,flag,x,y-1);
     flag[x][y] = 0;
}

int main(){
     int n = 3;
     //cin >> n;

     int arr[3][3];
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               cin >> arr[i][j];
     }

     int flag[3][3];
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               flag[i][j] = 0;
     }
     ratShowMePaths(arr,n,flag);
}
