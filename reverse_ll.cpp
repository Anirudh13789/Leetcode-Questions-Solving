#include <iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode*next;
    ListNode(int v){
        int val=v;
        next=NULL;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*c=head;
        ListNode*p=NULL;
        while(c!=NULL){
            ListNode*n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
};