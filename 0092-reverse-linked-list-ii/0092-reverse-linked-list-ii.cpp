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

#define Int ListNode*
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        
          /*
        
        z x c v a
            C
            
        */
        
        Int z=head;
        Int x;
        Int c;
        Int v;
        
        int cnt=1;
        
        if(cnt!=left){
            x=head;
            
            while( cnt+1!=left) x=x->next, cnt++;  // x will pint backward of node of left.
            c=x->next; // point to left vaue of node.
            
            v=c->next;
            cnt++;
            Int C=c;
            while( cnt+1!=right){
                Int b=v->next;
                v->next=c;
                c=v;
                v=b;
                cnt++;
            }
            Int a=v->next;
            x->next=v;
            v->next=c;
            C->next=a;
            return z;
            
        }
        else{
            x=head;
            c=x; // point to left value of node.
            
            v=c->next;
            Int C=c;
            while( cnt+1!=right){
                Int b=v->next;
                v->next=c;
                c=v;
                v=b;
                cnt++;
            }
            Int a=v->next;
            v->next=c;
            
            
            x->next=a;
            return v;
            
        }
      
        return head;
    }
};