//https://www.acwing.com/problem/content/27/

//д��һ

Definition for singly-linked list. 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        if (!head) return head;
        
        ListNode* q = new ListNode(-1);
        q->next = head;
        auto p = q;  //pΪ�����������β�ڵ�
        
        while (p->next)
        {
            ListNode* k = p->next;  //k������������
            while ( k && p->next->val == k->val ) k = k->next;
            
            if ( k == p->next->next ) p = p->next;
            else p->next = k;
        }
        
        return q->next;
    }
};