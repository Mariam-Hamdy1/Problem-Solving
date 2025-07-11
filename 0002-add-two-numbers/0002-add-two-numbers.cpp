/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        
        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int val1 = (p1 != nullptr) ? p1->val : 0;
            int val2 = (p2 != nullptr) ? p2->val : 0;
            
            int sum = val1 + val2 + carry;
            
            carry = sum / 10;
            int digit = sum % 10;
            
            current->next = new ListNode(digit);
            current = current->next;
            
            if (p1 != nullptr) {
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                p2 = p2->next;
            }
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead;
        
        return result;
    }
};