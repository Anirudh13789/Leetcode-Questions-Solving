#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int lengthLL(ListNode*head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int mid;
        int l=lengthLL(head);
        if(l%2==0){
            mid=l/2+1;
        }
        else if(l%2!=0){
            mid=l/2;
        }
        ListNode*temp=head;
        for(int i=0;i<mid;i++){
            temp=temp->next;
        }
        return temp;

    }   
};