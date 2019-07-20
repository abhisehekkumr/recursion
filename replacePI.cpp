#include<iostream>
using namespace std;

void replacePI(char input[]){

     if(input[0] == '\0')
          return;

     if(input[0] == 'p' && input[1] == 'i'){
          int i = 0;
          while(input[i] != '\0')
               i++;
          while(i > 1){
               input[i+2] = input[i];
               i--;
          }

          input[0] = '3';
          input[1] = '.';
          input[2] = '1';
          input[3] = '4';
     }
     replacePI(input+1);
}

int main(){
     char input[100];
     cin.getline(input,100);
     replacePI(input);
     std::cout << input << '\n';
}
