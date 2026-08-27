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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int pos = count - n + 1;
        if (pos == 1) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        temp = head;
        for (int i = 1; i <= pos - 2; i++) {
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};