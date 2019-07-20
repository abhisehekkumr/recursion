/*

Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’
being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114.
You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get?
Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’.
I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example,
but I bet you that if you got a string of length 5000 there would be tons of different decodings and
 with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument,
so she requires a program that will determine how many decodings there can be for a given string using her code.

*/

#include<iostream>
using namespace std;



long long totalCount(string arr){

     if(arr.size() == 0 || arr.size() == 1)
          return 1;


     long long output = 0;

    if((arr[0] != '1' && arr[1] != '0') || (arr[0] != '2' && arr[1] != '0'))
        output = totalCount(arr.substr(1));

     if(arr[0] != '\0' && arr[1] != '\0'){
          int number = (arr[0] - '0')*10 + (arr[1] - '0');

          if(number >= 10 && number <= 26){
               string str2 = arr.substr(2);
               output += totalCount(str2);
          }
     }

     return output;
}

int main(){
     string str;
     cin >> str;
     bool flag = true;

     for(int i = 1; i < str.size(); i++){

             if(str[i] == '0' && str[i+1] == '0'){
                 flag = false;
                 break;
             }

             if(str[i] == '0' && str[i - 1] > '2'){
                 //cout << str[i] << " " << str[i-1] << endl;
                 flag = false;
                 break;
             }
         }

     if(flag)
          std::cout << totalCount(str) << '\n';
     else
          std::cout << 0 << '\n';
}
