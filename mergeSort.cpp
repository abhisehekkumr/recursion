#include<iostream>
using namespace std;

void merge(int arr[], int lower, int mid, int high){
     int n1 = mid + 1- lower;
     int n2 = high - mid;

     int arr1[n1],arr2[n2];

     for(int i = 0; i < n1; i++)
          arr1[i] = arr[lower + i];

     for(int i = 0; i < n2; i++)
          arr2[i] = arr[mid + 1 + i];

     int i = 0, j = 0, k = lower;

     while(i < n1 && j < n2){

          if(arr1[i] < arr2[j])
               arr[k] = arr1[i++];
          else
               arr[k] = arr2[j++];
          k++;
     }

     while(i < n1)
          arr[k++] = arr1[i++];

     while(j < n2)
          arr[k++] = arr2[j++];
}

void mergeSort(int arr[], int lower, int high){

     if(lower < high){
          int mid = (lower + high)/2;
          mergeSort(arr,lower,mid);
          mergeSort(arr,mid+1, high);
          merge(arr,lower,mid,high);
     }
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     mergeSort(arr,0,n-1);

     for(int i = 0; i < n; i++)
          std::cout << arr[i] << ' ';
     std::cout << '\n';
     return 0;
}
