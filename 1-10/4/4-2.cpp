#include <iostream>
#include <vector>
#include <math.h>
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
using namespace std;
// 法一改良版：法一是全量都push到新数组中，这个是到一半就不再push
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
 vector<int> nums3;
 int i=0,j=0,len1=nums1.size(),len2=nums2.size();
 int middle=ceil((len1+len2)/2);
 while(i<len1&&j<len2&&(i+j)<=middle){
   if(nums1[i]<=nums2[j]){
     nums3.push_back(nums1[i++]);
   }else{
    nums3.push_back(nums2[j++]);
   }
 }
 while(i<=middle&&i<len1){
  nums3.push_back(nums1[i++]);
 }
 while(j<=middle&&j<len2){
  nums3.push_back(nums2[j++]);
 }

 return (len1+len2)%2==1?nums3[middle]:(nums3[middle]+nums3[middle-1])/2.0;
}

int main(){
  vector<int> v1,v2; 
  v1={3};
  v2={};
  printf("%.2f",findMedianSortedArrays(v1,v2));
  system("pause");
  return 1;
}

/* 
执行用时：
40 ms
, 在所有 C++ 提交中击败了
69.10%
的用户
内存消耗：
87.7 MB
, 在所有 C++ 提交中击败了
9.79%
的用户 */