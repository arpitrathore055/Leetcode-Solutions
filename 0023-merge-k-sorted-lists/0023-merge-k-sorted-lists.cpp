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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        priority_queue pq([](const ListNode* list1,const ListNode* list2){
            return list1->val > list2->val;
        },vector<ListNode*>{});
        
        for(auto& list:lists){
            if(list != nullptr){
                pq.push(list);                
            }
        }
        
        while(!pq.empty()){
            
            ListNode* frontNode=pq.top();
            pq.pop();
            if(tail==nullptr){
                head=frontNode;
                tail=frontNode;
            }
            else{
                tail->next=frontNode;
                tail=tail->next;
            }
            
            if(frontNode->next!=nullptr){
                pq.push(frontNode->next);
            }
            
        }
        
        
        return head;
        
    }
};