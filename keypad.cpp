#include<iostream>
#include<string>
using namespace std;

int keypad(int number, string pattern[], string output[]){
     if(number == 0){
          output[0] = "";
          return 1;
     }

     int n = number%10;
     int count = keypad(number/10, pattern,output);
     string str = pattern[n];

     for(int i = 0; i < count; i++){
          string s = output[i];
          output[i] = s + str[0];
          int jump = count;
          for(int j = 1; j < str.length(); j++){
               output[i+jump] = s + str[j];
               jump += count;
          }
     }

     return (str.length())*count;
}

int main(){

     int number;
     cin >> number;
     string pattern[10];
     pattern[2] = "abc";
     pattern[3] = "def";
     pattern[4] = "ghi";
     pattern[5] = "jkl";
     pattern[6] = "mno";
     pattern[7] = "pqrs";
     pattern[8] = "tuv";
     pattern[9] = "wxyz";

     //std::cout << number << '\n';

     string *output = new string[1000];
     int count = keypad(number,pattern,output);
     for(int i = 0; i < count; i++)
          std::cout << output[i] << '\n';
}
