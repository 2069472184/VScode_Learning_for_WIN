//https://www.acwing.com/problem/content/33/

//����
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
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) return head;
        
        ListNode* p = head;
        ListNode* q = head->next;

        while (q)
        {
            ListNode* tem = q->next;
            q->next = p;
            p = q;
            q = tem;
        }
        
        head->next = NULL;
        
        return p;
    }
};

//�ݹ�
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
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) return head;  //��ֹ������͵ݹ�ĳ���
        
        auto Head = reverseList(head->next);  
        //��ת������һ������е�ͷ�ڵ�head֮���������ת�����ͷ�ڵ���head->next��������ָ��NULL;

        head->next->next = head;   
        //����Ҫ�÷�תͷ�ڵ�����ָ��ǰ��һ���ڵ㣨��head�����Ϳ�����head->next->next = head;
        head->next = NULL;
        //������һ������е�ͷ�ڵ�����ָ��NULL

        return Head;
    }
};