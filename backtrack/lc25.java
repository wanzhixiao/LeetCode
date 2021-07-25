package backtrack;


class ListNode{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

class Solusion125{
    public ListNode reverseKGroup(ListNode head, int k) {
        int temp = k;
        ListNode pre = new ListNode(0,head);
        ListNode hair = pre,tail = pre;

        while(head != null){
//            while(temp%k>0 && tail != null){
//                tail = tail.next;
//                temp -= 1;
//            }
            tail = pre;
            for(int i=0; i<k;i++){
                tail = tail.next;
                if(tail == null){
                    return hair.next;
                }
            }

            ListNode nex = tail.next;
            //翻转链表
            ListNode prev = tail.next;
            ListNode p = head;
            while(prev != tail){
                ListNode right = p.next;
                p.next = prev;
                prev = p;
                p = right;
            }

            //head->tail, tail->head
            ListNode tmp = head;
            head = tail;
            tail = tmp;

            pre.next = head;
            tail.next = nex;
            pre = tail;
            head = tail.next;
        }

        return hair.next;
    }
}

public class lc25 {
    public static void main(String[] args) {

    }
}
