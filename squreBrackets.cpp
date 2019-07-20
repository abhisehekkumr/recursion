#include<bits/stdc++.h>
using namespace std;


int numberOfExpressions(int opening, int closing, bool arr[], int total, int index){

     if(opening > total || closing > total)
          return 0;

     if(opening == total && closing == total)
          return 1;

     if(opening == closing || arr[index])
          return numberOfExpressions(opening+1, closing, arr,total, index+1);

     else if(opening == total)
          return numberOfExpressions(opening,closing+1,arr,total, index+1);
     else
          return (numberOfExpressions(opening+1,closing,arr,total, index+1) +
                  numberOfExpressions(opening,closing+1,arr,total, index+1));
}

int main(){
     int d;
     cin >> d;

     while(d--){
          int n,k;
          cin >> n >> k;

          bool arr[2*n];

          for(int i = 0; i < 2*n; i++)
               arr[i] = false;

          for(int i = 0; i < k; i++){
               int element;
               cin >> element;
               arr[element - 1] = true;
          }

          std::cout << numberOfExpressions(0,0,arr,n,0) << '\n';
     }

}
