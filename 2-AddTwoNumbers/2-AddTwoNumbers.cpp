// Last updated: 12/27/2025, 3:45:34 PM
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* toReturn = new ListNode(-1);
        ListNode* curr = toReturn;
        int carry = 0;
        for(;l1!=nullptr; l1=l1->next) {
            if(toReturn->val == -1) curr = toReturn;
            else {
                curr->next = new ListNode();
                curr = curr->next;
            }
            if(l2) {
                curr->val = l1->val + l2->val + carry;
                carry = 0;
                l2 = l2->next;
            }
            else {
                curr->val = l1->val + carry;
                carry = 0;
            }
            if(curr->val >= 10) {
                while(curr->val >= 10) {
                    curr->val -= 10;
                    carry++;
                }
            }
        }

        while(l2) {
            if(toReturn->val == -1) curr = toReturn;
            else {
                curr->next = new ListNode();
                curr = curr->next;
            }
            curr->val = l2->val + carry;
            carry = 0;
            if(curr->val >= 10) {
                while(curr->val >= 10) {
                    curr->val -= 10;
                    carry++;
                }
            }
            l2 = l2->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        return toReturn;
    }
};