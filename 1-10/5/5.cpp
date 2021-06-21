// dp
#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
  int len=s.size();
  string s2=s;
  int l=2,max=1,maxI=0,j=0;

  int arr[len][len];

  for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      arr[i][j]=i==j?1:0;
    }
  }

  for(l=2;l<=len;l++){
    for(int i=0;i<len;i++){
      j=l+i-1;
      if(j>=len){
        break;
      }else if(s[i]==s[j]){
        if(j - i < 3){
           arr[i][j]=1;
        }else{
          arr[i][j]=arr[i+1][j-1];
        }
      }
      if(arr[i][j]&&l>max){
        max=l;
        maxI=i;
      }
    }
  }
  return s.substr(maxI,max);
}

int main(){
  string s1("babad");
  printf("%s",longestPalindrome(s1).c_str());
  system("pause");
  return 1;
}

/* 执行用时：
420 ms
, 在所有 C++ 提交中击败了
43.74%
的用户
内存消耗：
11.4 MB
, 在所有 C++ 提交中击败了
66.60%
的用户 */