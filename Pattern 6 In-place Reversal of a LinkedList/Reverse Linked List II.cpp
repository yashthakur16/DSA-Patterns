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
    
        void solve(ListNode* head)
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
    
        ListNode* reverseBetween(ListNode* head, int left, int right) 
        {
            if(head==nullptr || head->next==NULL || left==right)
            {
                return head;
            }
    
            int count=1;
    
            ListNode* l=head;
            ListNode* r=nullptr;
    
            ListNode* curr=head;
            ListNode* first=head;
    
            while(curr!=nullptr)
            {
                if(count==left-1)
                {
                    l=curr->next;
                    first=curr;
                }
                else if(count==right)
                {
                    r=curr;
                    break;
                }
                curr=curr->next;
                count++;
            }
    
            
    
            if(l!=first) first->next=nullptr;
            else head=r;
            
            ListNode* second=r->next;
    
            r->next=nullptr;
    
            solve(l);
    
            first->next=r;
            l->next=second;
    
    
            return head;
            
        }
    };