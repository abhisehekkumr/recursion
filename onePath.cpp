#include<iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}
int getMaxOnes(int arr[3][3],int n,int m, int i = 0, int j = 0)
{
    std::cout << i << " " << j << '\n';
    if(i < 0 || j < 0)
        return 0;

    if(i == n || j == m)
        return 0;

    int ans = 0;
    if(arr[i][j] == 1){
        int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;

        // going up
        if(i > 0)
            ans1 = getMaxOnes(arr,n,m,i-1,j);

        // going down
        if(i < n)
            ans2 = getMaxOnes(arr,n,m,i+1,j);

        // going left
     	if(j > 0)
            ans3 = getMaxOnes(arr,n,m,i,j-1);

        // going right
        if(j < m)
            ans4 = getMaxOnes(arr,n,m,i,j+1);

        ans = max(max(ans1,ans2), max(ans3, ans4)) + 1;

	 }
    return ans;
}

int main(){
     int n,m;
     n = 3;
     m = 3;
     int arr[3][3] = { {1, 1, 1},
                       {0, 0, 1},
                       {0, 0, 0}
                  };
     std::cout << getMaxOnes(arr,n,m) << '\n';
}
