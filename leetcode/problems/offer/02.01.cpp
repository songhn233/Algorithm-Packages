/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode *p=head;
        map<int,bool> mp;
        while(p!=nullptr) {
            mp[p->val]=true;
            while(p->next!=nullptr&&mp[p->next->val]) {
                p->next=p->next->next;
            }
            p=p->next;
        }
        return head;
    }
};