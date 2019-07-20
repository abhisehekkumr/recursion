#include<iostream>
#include<string>
using namespace std;

void swap(char *a, char *b){

     char temp = *a;
     *a = *b;
     *b = temp;
}

void printpermuatitions(char arr[], int n, int j){

     if(j == n){
          std::cout << arr << '\n';
          return;
     }

     for(int i = j; i < n; i++){
          swap(arr+i, arr+j);
          printpermuatitions(arr,n,j+1);
          swap(arr+i,arr+j);
     }
}

int main(){
     std::cout << "string of lenght 3" << '\n';
     char str[10];
     cin.getline(str,10);
     std::cout << "all permuations of string" << '\n';
     printpermuatitions(str,3,0);
     return 0;
}
