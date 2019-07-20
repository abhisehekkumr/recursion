#include<bits/stdc++.h>
using namespace std;

int smallestSuperSequence(string str1,string str2, int i, int j){

     int dp[str1.size() + 1][str2.size() + 1];
     dp[str1.size()][str2.size()] = 0;

     for(int i = 0; i <= str1.size(); i++)
          dp[str1.size() - i][str2.size()] = i;

     for(int i = 0; i <= str2.size(); i++)
          dp[str1.size()][str2.size()-i] = i;

     for(int i = str1.size()-1; i >= 0; i--){
          for(int j = str2.size()-1; j >= 0; j--){

               if(str1[i] == str2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    //std::cout << "this " << i << " " << j << " " << dp[i][j] << '\n';
               }
               else{
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
                    //std::cout << "that " << i << " " << j << " " << dp[i][j] << " " << dp[i+1][j] << " " << dp[i][j+1] << '\n';
               }
          }
     }
     /*
     for(int i = 0; i <= str1.size(); i++){
          for(int j = 0; j <= str2.size(); j++)
               std::cout << dp[i][j] << ' ';
          std::cout << '\n';
     }*/
     return dp[0][0];
}

int main(){
     string str1, str2;
     cin >> str1;
     cin >> str2;
     std::cout << smallestSuperSequence(str1, str2,0,0) << '\n';
}
