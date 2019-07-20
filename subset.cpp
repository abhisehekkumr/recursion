#include<iostream>
using namespace std;

int power(int base, int n){
     int res= 1;
     while(n){

          if(n & 1)
               res = res*base;
          base = base*base;
          n = n >> 1;
     }
     return res;
}

int getSubset(int arr[], int n, int **output){

     if(n == 0){
          output[0][0] = 0;
          return 1;
     }

     int ans1 = getSubset(arr+1,n-1,output);

     for(int i = 0; i < ans1; i++){
          int length = output[i][0];
          for(int j = length+1; j > 1; j--)
               output[i + ans1][j] = output[i][j-1];
          output[i + ans1][1] = arr[0];
          output[i + ans1][0] = length+1;
     }

     return 2*ans1;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     int size = power(2,n);

     int **output = new int*[size];
     for(int i = 0; i < size; i++)
          output[i] = new int[20];

     int count = getSubset(arr,n,output);
     for(int i = 0; i < count; i++){
          for(int j = 1; j <= output[i][0]; j++)
               std::cout << output[i][j] << ' ';
          std::cout << '\n';
     }


     for(int i = 0; i < size; i++)
          delete [] output[i];
     delete [] output;
}
