#include<iostream>
#include <stack>
#include<string>

using namespace std;

bool isValid(string s) {
  stack<char> st;
  int i=0;
  char a;
  for(i=0;i<s.size();i++){
    a=s[i];
    switch(a){
      case '(':
      case '{':
      case '[':
        st.push(a);
        break;
      case ')':if(st.top()=='('){st.pop();break;}else{return false;};
      case ']':if(st.top()=='['){st.pop();break;}else{return false;};
      case '}':if(st.top()=='{'){st.pop();break;}else{return false;};
      default: break;
    }
    return true;
  }
}

int main(){
 string s="{[]}";
 int i=isValid(s);
 cout<<i;
 system("pause");
}