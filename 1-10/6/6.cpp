#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
  int len1=s.size(),len2=p.size();
  int dp[len1+1][len2+1];
  int i=0,j=0;
  // 初始化
  dp[0][0]=1; // 两个都为空串时，完全匹配！
  for(i=1;i<=len1;i++){
    dp[i][0]=0;
  }
  for(j=1;j<=len2;j++){
    if(j==1||p[j-1]!='*'){ // 首位不管是不是*都不匹配
      dp[0][j]=0;
    }else{
      dp[0][j]=dp[0][j-2];
    }
  }

  for(i=1;i<=len1;i++){
    for(j=1;j<=len2;j++){
      switch(p[j-1]){
        case '*':{
          if(p[j-2]==s[i-1]||p[j-2]=='.'){
            dp[i][j]=dp[i][j-1]||dp[i-1][j];
            if(j>1){
                dp[i][j]=dp[i][j]||dp[i][j-2];
            }
            // dp[i][j]=dp[i][j-1]  // aa-a*
            // dp[i][j]=dp[i-1][j]  // aaq-aa*
            // dp[i][j]=dp[i][j-2]  // ab-ab*
            printf("(i=%d,j=%d) v=%d\n",i,j,dp[i][j]);
          }else{
            dp[i][j]=dp[i][j-2];
            printf("(i=%d,j=%d) v=%d\n",i,j,dp[i][j]);
          }
          break;
        }
        case '.':{
          dp[i][j]=dp[i-1][j-1];
          printf("(i=%d,j=%d) v=%d\n",i,j,dp[i][j]);
          break;
        }
        default:{
          dp[i][j]=s[i-1]!=p[j-1]?0:dp[i-1][j-1];
          printf("(i=%d,j=%d) v=%d\n",i,j,dp[i][j]);
        }
      }


      // if(p[j-1]!='*'){
      //  dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
      // }else{
      //     if(s[i - 1] == p[j - 2] || p[j - 2] == '.'){
      //       dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
      //       if(j > 1) dp[i][j] = dp[i][j] || dp[i][j - 2];
      //     }else{
      //       dp[i][j]=dp[i][j-2];
      //     }
      // }
    }
  }

  if(dp[len1][len2]==1){
    return true;
  }
  return false;
}

int main(){
  string s("aaa");
  string p("ab*a*c*a");
  // printf("%d",isMatch(s,p));
  // cout<<s.size();
  cout<<isMatch(s,p);
  system("pause");
  return 1;
}