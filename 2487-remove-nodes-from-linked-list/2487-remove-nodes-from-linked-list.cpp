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
    
    ListNode* removeNodes(ListNode* head) {
        
        vector< pair< ListNode* , int> > st; 
        ListNode* h=head;
        while(h!=NULL ){
            if(!st.empty()){
                
                while( !st.empty() && st.back().second <h->val){
                    st.pop_back();
                }
                
                if(!st.empty()){
                    st.back().first->next=h;
                }
            }
            st.push_back({h,h->val});
            h=h->next;    
        }
        return st[0].first;
    }
};