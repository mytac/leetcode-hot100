#include<iostream>

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

void readNodeList(ListNode *head){
  ListNode *h;
  h=head;
  while(h!=NULL){
    printf("%d ",h->val);
    h=h->next;
  }
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode *i,*j,*h,*t;
  i=l1;
  j=l2;
  if(!i&&!j) return h;
  if(i==NULL||j==NULL){
    return i==NULL?j:i;
  }else{
  if(i->val<=j->val){
    t=i;
    i=i->next;
  }else{
    t=j;
    j=j->next;
  }
  }

  h=t;
  t->next=NULL;
  // printf("h is %d\n",h->val);
  while(i!=NULL&&j!=NULL){
   if((i->val)<=(j->val)){
     t->next=i;
     t=t->next;
     i=i->next;
   }else{
     t->next=j;
     t=t->next;
     j=j->next;
   }
   t->next=NULL;
  }
  while(i!=NULL){
    t->next=i;
    t=t->next;
    i=i->next;
  }
  while(j!=NULL){
    t->next=j;
    t=t->next;
    j=j->next;
  }
  return h;
}

int main(){
  ListNode *l1,*l2,*r;
  int arr1[2]={-9,3};
  int arr2[2]={5,7};
  l1=makeListNode(arr1,2);
  l2=makeListNode(arr2,2);
  r=mergeTwoLists(l1,l2);
  readNodeList(r);
 system("pause");
}