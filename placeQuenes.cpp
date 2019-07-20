#include<iostream>
using namespace std;


bool isSafe(int **arr, int n, int row, int col){

     // horizontal
     for(int i = 0; i < n; i++){
          if(arr[row][i] == 1)
               return false;
     }

     // vertical
     for(int i = 0; i < n; i++){
          if(arr[i][col] == 1)
               return false;
     }

     // left diagonal
     for(int i = 0; i < n; i++){

          if(row + i < n && col + i < n && arr[row+i][col + i] == 1)
               return false;

          if(row - i >= 0 && col - i >= 0 && arr[row-i][col-i] == 1)
               return false;
     }

     // right diagonal
     for(int i = 0; i < n; i++){

          if(row - i >= 0 && col+i < n && arr[row - i][col + i] == 1)
               return false;

          if(row + i < n && col - i >= 0 && arr[row+i][col-i] == 1)
               return false;
     }
     return true;
}

bool quenes(int **arr, int n, int row = 0){

     if(row == n){
          for(int i = 0; i < n; i++){
               for(int j = 0; j <  n; j++)
                    std::cout << arr[i][j] << ' ';
               std::cout << '\n';
          }
          std::cout << '\n';
          return true;
     }

     bool flag = false;
     for(int i = 0; i < n; i++){

          if(isSafe(arr,n,row,i)){
               arr[row][i] = 1;
               flag = quenes(arr,n,row+1);
          }else
               arr[row][i] = 0;

          if(flag)
               arr[row][i] = 0;
     }

     return true;
}

void placeQuenes(int n){

     int **arr = new int*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new int[n];
          for(int j = 0; j < n; j++)
               arr[i][j] = 0;
     }

     quenes(arr,n);

     for(int i = 0; i < n; i++)
          delete [] arr[i];
     delete[] arr;
}

int main(){
     int n;
     cin >> n;
     placeQuenes(n);
}
