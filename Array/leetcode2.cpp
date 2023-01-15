#include<stdio.h>

 struct ListNode {
      int val;
      struct ListNode *next;
};

int main()
{
    int x;
    struct ListNode *l1,*l2;
    struct ListNode *last = l1;
    for(int i=0;i<3;i++){
        scanf("%d",&x);
        l1->val = x;
    }
}