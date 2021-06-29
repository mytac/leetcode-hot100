#include <iostream>
#include <string>
#include <vector>

#define MIN(a,b) (a>b?b:a)

using namespace std;
 
int maxArea(vector<int>& height) {
  int i=0,len=height.size();
  int j=len-1;
  int temp=0,max=0;
  while(i<j){
    temp=MIN(height[i],height[j])*(j-i);
    if(temp>max){
      max=temp;
    }
    if(height[i]<height[j]){
      i++;
    }else{
      j--;
    }
  }
  return max;
}

int main(){
  vector<int> nums={1,8,6,2,5,4,8,3,7};
  printf("%d",maxArea(nums));
  system("pause");
  return 1;
}