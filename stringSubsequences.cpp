#include<iostream>
using namespace std;
int power(int number, int n){

     int res = 1;
     while(n){

          if(n & 1)
               res = res*number;
          n = n >> 1;
          number = number*number;
     }
     return res;
}

int subsequences(string arr, string output[]){

     if(arr.empty()){
          output[0] = "";
          return 1;
     }

     int count = subsequences(arr.substr(1), output);
     for(int i = 0; i < count; i++)
          output[i + count] = arr[0] + output[i];
     return 2*count;
}

int main(){

     string str;
     cin >> str;

     int n = power(2,str.size());
     string *output = new string[n];
     int count = subsequences(str,output);

     for(int i = 0; i < count; i++)
          std::cout << output[i] << '\n';
     delete [] output;
}
