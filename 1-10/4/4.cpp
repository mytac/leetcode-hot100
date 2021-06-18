#include <iostream>
#include <vector>
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
 vector<int> nums3;
 int i=0,j=0,len1=nums1.size(),len2=nums2.size();
 while(i<len1&&j<len2){
   if(nums1[i]<=nums2[j]){
     nums3.push_back(nums1[i++]);
   }else{
    nums3.push_back(nums2[j++]);
   }
 }
 while(i<len1){
  nums3.push_back(nums1[i++]);
 }
 while(j<len2){
  nums3.push_back(nums2[j++]);
 }
int len3=nums3.size();
 return ((len3)%2==1)?nums3[(i+j)/2]:(nums3[len3/2-1]+nums3[(len3/2)])/2.0;
}

int main(){
  vector<int> v1,v2; 
  v1={2};
  v2={};
  printf("%.2f",findMedianSortedArrays(v1,v2));
  system("pause");
  return 1;
}

/* 执行用时：
52 ms
, 在所有 C++ 提交中击败了
28.38%
的用户
内存消耗：
87.6 MB
, 在所有 C++ 提交中击败了
16.49%
的用户 */