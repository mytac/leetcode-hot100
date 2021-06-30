#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

// -4,-1,-1,0,1,2
vector<vector<int>> threeSum(vector<int>& nums) {
  int len=nums.size();
  vector<vector<int>> ret;
  if(len<3){
    return ret;
  }
  // 原数组排序
  sort(nums.begin(),nums.end());
  int i,j,k=0,sum;
  vector<int> temp;
  // -4 -1 -1 0 1 2
  while(k<len-1){
    if(nums[k]>0) break;
    // 双指针
    i=k+1;j=len-1;
    if(k>0&&nums[k-1]==nums[k]){k++;continue;}
    while(i<j){
      sum=nums[k]+nums[i]+nums[j];
      if(sum==0){
        temp.push_back(nums[k]);
        temp.push_back(nums[i]);
        temp.push_back(nums[j]);
        ret.push_back(temp);
        temp.clear();
        while(i<j&&nums[i+1]==nums[i]){
          i++;
        }
        while(i<j&&nums[j-1]==nums[j]){
          j--;
        }
        i++;
        j--;
      }else if(sum<0){
         i++;
      }else{
        j--;
      }
    }
    k++;
  }
  return ret;
}

int main(){
  vector<int> nums={0,0,0};
  vector<vector<int>> ret=threeSum(nums);
  for(int i=0;i<ret.size();i++){
    for(int j=0;j<3;j++){
      printf("%d,",ret[i][j]);
    }
    cout<<endl;
  }
  system("pause");
  return 1;
}



/* 添加备注

执行用时：
72 ms
, 在所有 C++ 提交中击败了
94.75%
的用户
内存消耗：
19.6 MB
, 在所有 C++ 提交中击败了
26.42%
的用户 */