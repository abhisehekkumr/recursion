#include<iostream>
using namespace std;

long numberOfNumbers(long arr[], long n, long fact[], long freq[]){
     if(n == 0 || n == 1)
          return 0;

     long ans = 0;

     long divide = 1;
     for(long i = 0; i < 10; i++)
          divide *= fact[freq[i]];

     for(long i = arr[0]+1; i < 10; i++){

          if(freq[i] > 0)
               ans += (freq[i]*fact[n-1])/divide;
     }

     freq[arr[0]]--;
     ans += numberOfNumbers(arr+1,n-1,fact,freq);
     return ans;
}

long result(long num){

     long number = 0;
     int size = 0;

     while(num){
          number = number*10 + num%10;
          num = num/10;
          size += 1;
     }

     long arr[size];
     long fact[size+1];
     long freq[10];
     fact[0] = 1;
     for(int i = 0; i < 10; i++)
          freq[i] = 0;

     for(int i = 0; i < size; i++){
          arr[i] = number%10;
          number = number/10;
          freq[arr[i]]++;
          fact[i+1] = (i+1)*fact[i];
     }
     /*
     std::cout << "number" << '\n';
     for(int i = 0; i < size; i++)
          std::cout << arr[i] << ' ';
     std::cout << '\n';

     std::cout << "size" << '\n';
     std::cout << size << '\n';

     std::cout << "freq" << '\n';
     for(int i = 0; i <10; i++)
          std::cout << freq[i] << ' ';
     std::cout << '\n';

     std::cout << "fact" << '\n';
     for(int i = 0; i <= size; i++)
          std::cout << fact[i] << ' ';
     std::cout << '\n';*/
     return numberOfNumbers(arr,size,fact,freq);

}

int main(){
     long n;
     cin >> n;
     /*
     long arr[n];
     long fact[n+1];
     long freq[10] = {};
     fact[0] = 1;
     for(long i = 0; i < n; i++){
          cin >> arr[i];
          fact[i+1] =(i + 1)*fact[i];
          freq[arr[i]]++;
     }

     std::cout << numberOfNumbers(arr,n,fact,freq) << '\n';
     */
     std::cout << result(n) << '\n';
}
