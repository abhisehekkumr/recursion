#include<bits/stdc++.h>
using namespace std;

void printStrings(string arr, int j, int k){

     if(j == k - 1){
          for(int i = 0; i < k; i++)
               std::cout << arr[i];
               std::cout << '\n';
          return;
     }

     for(int i = j; i < arr.size(); i++){
          char c = arr[i];
          arr[i] = arr[j];
          arr[j] = c;
          printStrings(arr,j+1,k);
          c = arr[i];
         arr[i] = arr[j];
         arr[j] = c;
     }
}


int print(string arr, int k, string *output){

     if(k == 1){
          for(int i = 0; i < arr.size(); i++)
               output[i] = arr[i];
          return arr.size();
     }

     int count = print(arr,k-1,output);

     for(int i = 0; i < count; i++){
          int jump = count;
          string s = output[i];
          output[i] = arr[0] + output[i];
          for(int j = 1; j < arr.size(); j++){
               output[i + jump] = arr[j] + s;
               jump += count;
          }
     }

     return count*arr.size();
}



int main(){
     string s;
     cin >> s;
     int k;
     cin >> k;
     //string *output = new string[1000];
     //int count = print(s,k,output);
     //for(int i = 0; i < count; i++)
     //     std::cout << output[i] << '\n';


}
