#include <iostream>
#include <vector>
#include <climits>
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
    int pairSum(ListNode* head) {
        ListNode*temp=head;
        vector<int> vec;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=vec.size()-1;
        int sum;
        int ans=INT_MIN;
        while(i<=j){
            sum=vec[i]+vec[j];
            ans=max(sum,ans);
            i++;
            j--;
        }
        return ans;
    }
};