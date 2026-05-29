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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp1 = head;

        while (temp1 != NULL) {
            length++;
            temp1 = temp1->next;
        }

        if (n == length) {
            return head->next; // delete head
        }

        int pos = length - n;
        ListNode* temp2 = head;

        for (int i = 1; i < pos; i++) {
            temp2 = temp2->next;
        }

        temp2->next = temp2->next->next;
        return head;
    }
};
