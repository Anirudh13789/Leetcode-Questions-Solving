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
    ListNode*next;
    int val;
    ListNode(int d){
        val=d;
        next=NULL;
    }
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        // Step 1: find length
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        // Step 2: find middle index
        int mid = len / 2;

        // Step 3: go to node just before middle
        ListNode* prev = NULL;
        temp = head;
        for (int i = 0; i < mid; i++) {
            prev = temp;
            temp = temp->next;
        }

        // Step 4: delete middle node
        prev->next = temp->next;
        delete temp;

        return head;
    }
};
