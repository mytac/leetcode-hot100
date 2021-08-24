#include<stdio.h>
#include<stdlib.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* makeListNode(int *arr,int len){
  ListNode *head,*l,*p;
  head=new ListNode();
  l=head;
  int i=0;
  for(i=0;i<len;i++){
    p=new ListNode(*(arr+i));
    l->next=p;
    l=l->next;
  }
  return head->next;
}


ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode *h,*i,*j,*t;
  int step=0;
  h=i=j=head; // i为删除的那个节点的前驱
  // j先走到n个，如果在此之前为空，退出报错
  while(j!=NULL&&step<(n+1)){
    j=j->next;
    step++;
  }
  if(step!=n+1){
    h=h->next;
  }else{
    while(j!=NULL){
    i=i->next;
    j=j->next;
  }
  // 上面走完，i所指向的位置即为删除的节点的前驱
  t=i->next->next;
  i->next=t;
  }
  return h;
}

void readNodeList(ListNode *head){
  ListNode *h;
  h=head;
  while(h!=NULL){
    printf("%d",h->val);
    h=h->next;
  }
}

int main(){
 int arr[2]={1,2};
 ListNode *p,*h;
 p=makeListNode(arr,2);
 h=removeNthFromEnd(p,2);
 readNodeList(h);
  system("pause");
  return 1;
}