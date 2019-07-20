#include<iostream>
using namespace std;

void printInterleavingStrings(char input1[],char input2[],string ans){

     if(input1[0] == '\0' && input2[0] == '\0'){
          std::cout << ans << '\n';
          return;
     }

     if(input1[0] != '\0')
          printInterleavingStrings(input1+1, input2, ans + input1[0]);

     if(input2[0] != '\0')
          printInterleavingStrings(input1, input2+1, ans + input2[0]);
}

int main(){
     char input1[1000];
     char input2[1000];
     cin.getline(input1,1000);
     cin.getline(input2,1000);
     printInterleavingStrings(input1, input2, "");
     return 0;
}
