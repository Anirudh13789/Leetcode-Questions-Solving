#include <iostream>
#include <vector>
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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
        
    }
};