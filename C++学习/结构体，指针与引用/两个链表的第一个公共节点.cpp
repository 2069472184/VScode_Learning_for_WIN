//https://www.acwing.com/problem/content/description/62/

//TLE
/* 
 //Definition for singly-linked list.
 //struct ListNode {
 //    int val;
 //    ListNode *next;
 //    ListNode(int x) : val(x), next(NULL) {}
 //};
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        ListNode* ans;
        while ( headA )
        {
            ListNode* k = headB;
            while ( k )
            {
                if ( headA == k ) return headA;
                k = k->next;
            }
            
            headA = headA->next;
        }
        
        return NULL;
    }
}; 
 */

//ѭ����������ͬ��ʱ���Ȼ���ཻ��λ��
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
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        
        while ( a != b )
        {
            //����lista+listb��listb+lista������·����a��b�ཻʱ������·��һ�����
            if (b) b = b->next;
            else b = headA;
            if (a) a = a->next;
            else a = headB;
        }
        
        return a;
    }
};