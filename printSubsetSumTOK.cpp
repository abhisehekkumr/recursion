#include<iostream>
using namespace std;

void printSubsets(int arr[], int n, int flag[], int index, int sum){

     if(sum == 0){
          for(int i = 0; i < index; i++)
               std::cout << flag[i] << ' ';
          std::cout << '\n';
          return;
     }
     
     if(n == 0)
          return;

     if(sum < 0)
          return;



     printSubsets(arr+1,n-1,flag,index,sum);
     flag[index] = arr[0];
     printSubsets(arr+1,n-1,flag,index+1,sum - arr[0]);
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     int flag[n] = {};
     int k;
     cin >> k;

     printSubsets(arr,n,flag,0,k);
}
