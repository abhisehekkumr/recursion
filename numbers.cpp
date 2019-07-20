#include<bits/stdc++.h>
using namespace std;
void printIncreasingNumbers1(int n, int number) {
     //std::cout << number << '\n';
    int input = number;
    for(int i = n; i > 0; i--)
        input = input/10;

    if(input != 0)
        return;

	if(n == 0){
        cout << 0;// << endl;
        return;
    }

    if(n == 1){
        for(int i = 0; i < 10; i++)
            cout << i << " ";
        //cout << endl;
        return;
    }
    int result = number/10;
    int num = number;
    for(int i = n; i > 1; i--)
        num = num/10;

    for(int i = 1; i <= 9; i++){
        if(num < i){
            cout << result*10 + i << " ";
           // std::cout << "number : " << number << '\n';
       }
    }



    printIncreasingNumbers1(n,number+10);
}

void printNUmber(int n, string start = "1"){
     
}

int main(){
     int n;
     cin >> n;

     int number = 1;
     for(int i = n; i > 1; i--)
          number = number*10;
     printIncreasingNumbers1(n,number);
}
