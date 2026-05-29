#include <iostream>
#include <vector>
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
    ListNode*next;
    int val;
    ListNode(int d){
        val=d;
        next=NULL;
    }
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int> vec;
        ListNode*temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<vec.size();i+=2){
            temp->val=vec[i];
            temp=temp->next;
        }
        for(int i=1;i<vec.size();i+=2){
            temp->val=vec[i];
            temp=temp->next;
        }
        return head;
    }
};