#include<iostream>
#include<string>
using namespace std;

int allcodes(string number, string output[]){

     if(number.size() == 0){
          output[0] = "";
          return 1;
     }

     string out1[10000], out2[10000];
     int n = number[0] - '0';
     char c = n + 'a'-1;
     int ans1 = allcodes(number.substr(1), out1);
     int ans2 = 0;
     char ch;
     if(number[1] != '\0'){
          int n = (number[0] - '0')*10 + (number[1] - '0');
          ch = 'a' + n-1;
          if(n <= 26)
              ans2 = allcodes(number.substr(2), out2);
     }

     int k = 0;
     for(int i = 0; i < ans1; i++){
          output[k++] = c + out1[i];
     }

     for(int i = 0; i < ans2; i++){
          output[k++] = ch + out2[i];
     }

     return ans1 + ans2;
}

int main(){
     string number;
     cin >> number;

     string *output = new string[1000];
     int count = allcodes(number,output);

     for(int i = 0; i < count; i++)
          std::cout << output[i] << '\n';
}
