#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> generateParenthesis(int n) {
  vector<string> row,arr;
  vector<vector<string>> dp;
  string s;
  int i,j,m,q;
  arr.push_back(""); // 0
  dp.push_back(arr);
  arr.clear();
  arr.push_back("()"); // 1
  dp.push_back(arr);
  for(i=2;i<=n;i++){
  arr.clear();
    // 选两个数组c1,c2，对其进行排列组合，c1下标+c2下标+1==c3下标
    int step=0,left,right;
    for(step=0;step<i;step++){
      left=step;
      right=i-step-1;
      for(m=0;m<dp[left].size();m++){
        for(q=0;q<dp[right].size();q++){
          s="("+dp[left][m]+")"+dp[right][q];
          printf("dp i%d %s\n",i,s.c_str());
          arr.push_back(s);
        }
      }
    }
    dp.push_back(arr);
  }

  return dp[n];
}

void printVectorString(vector<string> arr){
  for(int i=0;i<arr.size();i++){
    printf("res is:%s\n",arr[i].c_str());
  }
}

int main(){
  int n=3;
  string s="()";
  // printf("%s",s.c_str());
  vector<string> res=generateParenthesis(n);
  printf("%d",res.size());
  printVectorString(res);
 system("pause");
}