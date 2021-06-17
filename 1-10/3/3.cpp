#include <iostream>
#include <string.h>
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
using namespace std;


// 查询选定窗口中是否有重复字符
bool hasDuplicate(int start,int end,string s){
  int i=start,j;
  for(i;i<end;i++){
    j=i+1;
    while(j<=end){
      if(s[i]==s[j++]) return true;
    }
  }
  return false;
}

int lengthOfLongestSubstring(string s) {
  int len=s.length();
  if(len<2){
    return len;
  }
  int win=1,i=0;
  int ret=0;

  while(i+win<len){
    // 只要找到一个不重复的子串，就增大窗口；
    if(!hasDuplicate(i,i+win,s)){
      ret=win;
      win++;
    }else if(i+win<len){
      i++;
    }
  }

  return ret+1;
    
}


int main(){
  string s="pwwkew";
  printf("%d",lengthOfLongestSubstring(s));
  system("pause");
  return 1;
}

/* 执行用时：
228 ms , 在所有 C++ 提交中击败了 8.47% 的用户
内存消耗：
316.9 MB , 在所有 C++ 提交中击败了4.98% 的用户 */