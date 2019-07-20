#include<iostream>
#include<string>
using namespace std;

void printKeypad(int number, string result, string pattern[]){

     if(number == 0){
          std::cout << result << '\n';
          return;
     }

     string str = pattern[number%10];
     for(int i = 0; i < str.length(); i++)
          printKeypad(number/10, str[i] + result, pattern);
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

     printKeypad(number,"", pattern);
}
