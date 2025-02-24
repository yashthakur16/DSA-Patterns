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
    
    
        ListNode* reverse(ListNode* head)
        {
            ListNode* curr=head;
            ListNode* prev=nullptr;
    
            while(curr!=nullptr)
            {
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
    
            return prev;
        }
        void reorderList(ListNode* head) 
        {
            if(head==nullptr ||head->next==nullptr)
            {
                return ;
            }
            ListNode* slow=head;
            ListNode* fast=head;
    
            while(fast!=nullptr && fast->next!=nullptr)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
    
            ListNode* head2=reverse(slow);
            ListNode* head1=head;
    
         
            while(head2->next)
            {
                ListNode* temp=head1->next;
                ListNode* temp2=head2->next;
                
    
                head1->next=head2;
                head2->next=temp;
                
                head1=temp;
                head2=temp2;
                
            }
    
            return ;
            
        }
    };