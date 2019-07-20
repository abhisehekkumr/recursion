#include<iostream>
using namespace std;

int stringToNumber(char arr[], int number = 0){

     if(arr[0] == '\0')
          return number;
     return stringToNumber(arr+1, number*10 + (arr[0] - '0'));
}

int main(){
     char str[10];
     cin.getline(str,10);
     cout << stringToNumber( str) << endl;
}
