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
    int val;
    ListNode*next;
    ListNode(int v){
        int val=v;
        next=NULL;
    }
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        ListNode* temp = head;

        while (temp != NULL) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = values.size() - 1;

        while (i < j) {
            if (values[i] != values[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
