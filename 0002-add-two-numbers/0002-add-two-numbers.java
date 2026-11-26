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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode cur = ans;
        int nho = 0, sum = 0;
        while(l1 != null || l2 != null || nho != 0) {
            sum = nho;
            if (l1 != null) sum += l1.val;
            if (l2 != null) sum += l2.val;
            nho = sum / 10;
            cur.next = new ListNode(sum%10);
            cur = cur.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        return ans.next;
    }
}