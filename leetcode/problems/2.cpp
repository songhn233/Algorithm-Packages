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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode newNode=ListNode(0);
        ListNode *nowNode=&newNode;
        int rest=0;
        while(l1||l2||rest)
        {
            rest+=(l1?l1->val:0);
            rest+=(l2?l2->val:0);
            l1=(l1?l1->next:l1);
            l2=(l2?l2->next:l2);
            int val=rest%10;
            rest/=10;
            nowNode->next=new ListNode(val);
            nowNode=nowNode->next;
        }
        return newNode.next;
    }
};