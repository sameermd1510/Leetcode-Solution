/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNodes(ListNode head) {
        List<ListNode > st=new ArrayList<>();
        ListNode h=head;
        while( h!=null){
            if(!st.isEmpty()){
                while( !st.isEmpty() && st.get(st.size()-1).val < h.val ){
                    st.remove(st.size()-1);
                }
                if(!st.isEmpty()){
                    st.get(st.size()-1).next=h;
                }
            }
            st.add(h);
            h=h.next;
            
        }
        return st.get(0);
    }
}