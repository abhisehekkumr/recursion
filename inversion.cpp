#include<iostream>
using namespace std;

long long merge(int arr[], int temp[], int lower, int mid, int high){
    long long count = 0;
    int i = lower;
    int j = mid;
    int k = lower;

    while( i <= (mid - 1) && (j <= high)){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }

    while(i <= (mid - 1))
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = lower; i <= high; i++)
        arr[i] = temp[i];
    return count;
}

long long mergeSort(int arr[], int temp[], int lower, int high){
     long long count = 0;
     if(high > lower){
          int mid = (lower + high)/2;
          count = mergeSort(arr,temp,lower,mid);
          count += mergeSort(arr,temp,mid+1,high);
          count += merge(arr,temp,lower,mid+1,high);
     }
     return count;
}


int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     int temp[n];
     long long count = mergeSort(arr,temp,0,n-1);
     std::cout << count << '\n';
}
