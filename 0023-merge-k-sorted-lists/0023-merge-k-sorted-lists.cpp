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

    struct comparator{
        bool operator()(ListNode* l1,ListNode* l2) const {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*,vector<ListNode*>,comparator> minHeap;

        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        for(ListNode* listHead:lists){
            if(listHead!=nullptr){
                minHeap.push(listHead);
            }
        }
        while(!minHeap.empty()){
            ListNode* front=minHeap.top();
            minHeap.pop();

            if(head == nullptr){
                head=front;
                tail=front;
            }
            else{
                tail->next=front;
                tail=tail->next;
            }
            if(front->next != nullptr){
                minHeap.push(front->next);
            }
            tail->next=nullptr;
        }
        return head;
    }
};