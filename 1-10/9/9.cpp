#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std; 

unordered_map<char,string> phoneMap{
      {'2',"abc"},
      {'3',"def"},
      {'4',"ghi"},
      {'5',"jkl"},
      {'6',"mno"},
      {'7',"pqrs"},
      {'8',"tuv"},
      {'9',"wxyz"}
    };

  void backTrace(int index,vector<string> &ret,string &s,string digits){
      if(index==digits.size()){
        // printf("string:%s\n",s);
        ret.push_back(s);
        return;
      }

      const string& letters=phoneMap.at(digits[index]);
      for(const char& letter:letters){
        s.push_back(letter);
        backTrace(index+1,ret,s,digits);
        s.pop_back();
      }
  }

vector<string> letterCombinations(string digits) {
    vector<string> ret={};
    if(!digits.size()) return ret;
    string s;
    backTrace(0,ret,s,digits);
    
    return ret;
    
}


int main(){
  string s="";
  vector<string> ret=letterCombinations(s);
  for(int i=0;i<ret.size();i++){
      printf("%s,",ret[i].c_str());
  }
  system("pause");
  return 1;
}
