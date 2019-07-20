#include<iostream>
#include<string>
using namespace std;

int editDistance(string s, string t){

     if(s.size() == 0)
          return t.size();

     if(t.size() == 0)
          return s.size();

     if(s[0] == t[0])
          return editDistance(s.substr(1),t.substr(1));
     int ans1 = editDistance(s.substr(1),t.substr(1)) + 1;
     int ans2 = editDistance(s,t.substr(1)) + 1;
     int ans3 = editDistance(s.substr(1), t) + 1;
     return min(ans1, min(ans2 , ans3));
}

int main(){
     string s;
     string t;

     cin >> s;
     cin >> t;
     std::cout << editDistance(s,t) << '\n';
}
