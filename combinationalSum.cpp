#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


void combinationalSum(int arr[], int n,int sum, vector<int> &k , vector<vector<int>> &v, int index = 0){

     if(sum == 0){
          //for(int i = 0; i < k.size(); i++)
          //     std::cout << k[i] << ' ';
          //std::cout << '\n';
          v.push_back(k);
          return;
     }

     if(sum < 0)
          return ;

     if(n == 0)
          return ;

     k.push_back(arr[0]);
     combinationalSum(arr,n,sum-arr[0],k,v,index+1);
     k.erase(k.begin() + index);
     combinationalSum(arr+1,n-1,sum,k,v,index);
}

int main(){

     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     sort(arr, arr+n);

     unordered_map<int,int> m;
     for(int i = 0; i < n; i++)
          m[arr[i]]++;

     int newarr[m.size()];
     int j = 0;
     for(int i = 0; i < n; i++){
          if(m.count(arr[i])){
               newarr[j] = arr[i];
               m.erase(arr[i]);
               j++;
          }
     }

     int sum;
     cin >> sum;

     n = j;

     std::vector<int> k;
     vector<vector<int>> v;
      combinationalSum(newarr,n,sum,k,v);
     for(int i = 0; i < v.size(); i++){
          for(int j = 0; j < v[i].size(); j++)
               std::cout << v[i][j] << ' ';
          std::cout << '\n';
     }
}

/*
4
2 7 5 6
16
*/
