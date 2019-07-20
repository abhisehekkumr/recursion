#include<iostream>
#include<cstring>
using namespace std;

int MAX = 0;

bool safe(int arr[][15], int n, int row, int col){

     // horizonal rows
     for(int j = 0; j < n; j++){
          if(arr[row][j])
               return false;
     }

     // vertical columns
     for(int i = 0; i < n; i++){
          if(arr[i][col])
               return false;
     }

     // left diagonal
     for(int i = 0; i < n; i++){
          if(row + i < n && col + i < n && arr[row  + i][col + i])
               return false;
          if(row - i >= 0 && col - i >= 0 && arr[row  - i][col - i])
               return false;
     }

     // right diagonal

     for(int i = 0; i < n; i++){

          if(row + i < n && col - i >= 0 && arr[row  + i][col - i])
               return false;
          if(row - i >= 0 && col + i < n && arr[row  - i][col + i])
               return false;
     }
     return true;
}

bool Queen(int arr[][15], int row, int n){

     if(row == n){


          for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++)
                    cout << arr[i][j] << " ";
               //std::cout << '\n';
          }

          std::cout  << '\n';
          return true;
     }

     bool flag = false;

     for(int j = 0; j < n; j++){

          if(safe(arr,n,row,j)){
               arr[row][j] = 1;
               flag = Queen(arr,row + 1, n);
          }

          else
               arr[row][j] = 0;

          if(flag)
               arr[row][j] = 0;

     }

     return true;
}
void printQueen(int n){
     int arr[n][15];
     MAX = n;
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               arr[i][j]= 0;
     }

     Queen(arr, 0, n);
}


int main(){
     int n;
     cin >> n;
     printQueen(n);
}
