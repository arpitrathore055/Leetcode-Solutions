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
        if(l1==nullptr && l2==nullptr){
            return nullptr;
        }
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        ListNode* newll=nullptr;
        ListNode* tail=nullptr;
        int prevcarry=0;
        while(l1!=nullptr && l2!=nullptr){
            ListNode* newnode=new ListNode();
            if((l1->val + l2->val + prevcarry)>9){
                newnode->val=(l1->val + l2->val +prevcarry)%10;
                prevcarry=(l1->val + l2->val +prevcarry)/10;
            }
            else
            {
                newnode->val=(l1->val + l2->val +prevcarry);
                prevcarry=0;
            }
            if(tail==nullptr){
                newll=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=tail->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            ListNode* newnode=new ListNode();
            if((l1->val + prevcarry)>9){
                newnode->val=(l1->val + prevcarry)%10;
                prevcarry=(l1->val +prevcarry)/10;
            }
            else
            {
                newnode->val=(l1->val +prevcarry);
                prevcarry=0;
            }
            tail->next=newnode;
            tail=tail->next;
            l1=l1->next;
        }
        while(l2!=nullptr){
            ListNode* newnode=new ListNode();
            if((l2->val + prevcarry)>9){
                newnode->val=(l2->val + prevcarry)%10;
                prevcarry=(l2->val +prevcarry)/10;
            }
            else
            {
                newnode->val=(l2->val +prevcarry);
                prevcarry=0;
            }
            tail->next=newnode;
            tail=tail->next;
            l2=l2->next;
        }
        if(prevcarry!=0){
            ListNode* last=new ListNode(prevcarry);
            tail->next=last;
            tail=tail->next;
        }
        tail->next=nullptr;
        return newll;
    }
};