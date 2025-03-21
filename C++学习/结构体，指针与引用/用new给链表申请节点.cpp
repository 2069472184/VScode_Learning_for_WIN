#include <iostream>
using namespace std;

struct Node 
{
    int val, k;
    Node* next;
    
    Node ( int _val, int _k ) : val(_val), k(_k), next(NULL) {}
};

int main ()
{
    Node* p = new Node(1, 10);  
    //����һ���ڴ�ռ�oֵΪ1��10�Ľṹ�壬�����ýṹ��ĵ�ַ����p
    auto q = new Node(2, 20);
    //auto�൱��Node *p
    
    p->next = q;
    
    Node* head = p;
    Node* l = head;
    
    while ( l )
    {
        cout << l->val << " " << l->k << endl;
        l = l->next;
    }
    
    return 0;
}