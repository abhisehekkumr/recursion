#include<iostream>
#define N 9
using namespace std;

bool findEmpty(int arr[N][N], int &row, int &col){

     for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){
               if(arr[i][j] == 0){
                    row = i;
                    col = j;
                    return true;
               }
          }
     }
     return false;
}

bool isSafeHorizontal(int arr[N][N], int row, int number){

     for(int i = 0; i < N; i++){
          if(arr[row][i] == number)
               return false;
     }

     return true;
}

bool isSafevertical(int arr[N][N], int col, int number){

     for(int i = 0; i < N; i++){
          if(arr[i][col] == number)
               return false;
     }

     return true;
}

bool isSafeGrid(int arr[N][N],int row, int col, int number){

     int row_factor = row - row%3;
     int col_factor = col - col%3;

     for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
               if(arr[i + row_factor][j + col_factor] == number)
                    return false;
          }
     }
     return true;
}

bool isSafe(int arr[N][N], int row, int col, int number){

     if(isSafeHorizontal(arr,row,number) &&
        isSafevertical(arr,col,number)&&
         isSafeGrid(arr,row,col,number))

         return true;
     return false;
}

bool solveSudoku(int arr[N][N]){
     int row,col;

     if(!findEmpty(arr,row,col))
          return true;

     for(int i = 1; i <= 9; i++){

          if(isSafe(arr,row,col,i)){
               arr[row][col] = i;
               if(solveSudoku(arr))
                    return true;

               arr[row][col] = 0;
          }
     }
     return false;
}

int main(){
     int arr[N][N];

     for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++)
               cin >> arr[i][j];
     }

     std::cout << solveSudoku(arr) << '\n';
}
