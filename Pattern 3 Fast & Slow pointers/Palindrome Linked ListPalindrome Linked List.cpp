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
            if(head==nullptr || head->next==nullptr)
            {
                return head;
            }
    
            
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
    
        bool isPalindrome(ListNode* head) 
        {
            ListNode* slow=head;
            ListNode* fast=head;
    
            while(fast!=nullptr && fast->next!=nullptr)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
    
            fast=reverse(slow);
            ListNode*temp=fast;
            slow=head;
    
            while(fast!=nullptr)
            {
                if(slow->val!=fast->val)
                {
                    reverse(temp);
                    return false;
                } 
    
                slow=slow->next;
                fast=fast->next;
            }
    
            reverse(temp);
            return true;
            
        }
    };