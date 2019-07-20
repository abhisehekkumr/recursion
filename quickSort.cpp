#include<iostream>
using namespace std;

void swap(int *a, int *b){
     int temp = *a;
     *a = *b;
     *b = temp;
}

int partition(int arr[], int lower, int high){

     int i = lower-1;
     int x = arr[high];

     for(int j = lower; j < high; j++){

          if(arr[j] <= x){
               i++;
               swap(arr+i,arr+j);
          }
     }

     swap(arr+i+1, arr+high);
     return i+1;
}

void quickSort(int arr[], int lower, int high){

     if (lower < high) {
          int pivot = partition(arr,lower,high);
          quickSort(arr,lower,pivot-1);
          quickSort(arr,pivot+1,high);
     }
}

int main(){

     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     quickSort(arr,0,n-1);

     for(int i = 0; i < n; i++)
          std::cout << arr[i] << ' ';
     std::cout << '\n';
     return 0;
}
