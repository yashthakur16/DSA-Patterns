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
    
        void reverse(ListNode* head)
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
    
            return ;
            
        }
    
        ListNode* kNode(ListNode* head, int k)
        {
            int count=1;
    
            ListNode* curr=head;
    
            while(curr!=NULL && count<k)
            {
                curr=curr->next;
                count++;
            }
    
            return curr;
    
    
        }
    
    
    
        ListNode* reverseKGroup(ListNode* head, int k) 
        {
    
            if(head==NULL||head->next==NULL || k==1)
            {
                return head;
            }
    
            ListNode* curr=head;
            ListNode* prev=NULL;
    
    
            
            while(curr!=NULL)
            {
                ListNode* kthNode=kNode(curr,k);
    
                if(kthNode==NULL) return head;
    
                ListNode* forward=kthNode->next;
                
                kthNode->next=NULL;
    
                if(curr==head) head=kthNode;
                else prev->next=kthNode;
                
                reverse(curr);
    
                prev=curr;
                curr->next=forward;
                curr=forward;
    
    
            }
    
            return head;
    
    
    
            
        }
    };