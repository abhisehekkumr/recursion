#include<iostream>
#include<string>
using namespace std;

void printSubstrings(string str, string ans){

     if(str.size() == 0){
          std::cout << ans << '\n';
          return;
     }

     printSubstrings(str.substr(1), ans);
     printSubstrings(str.substr(1), ans + str[0]);
}

int main(){
     string str;
     cin >> str;
     printSubstrings(str,"");
     return 0;
}
