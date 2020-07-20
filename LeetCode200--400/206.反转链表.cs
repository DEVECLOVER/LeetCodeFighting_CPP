/*
 * @lc app=leetcode.cn id=206 lang=csharp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode ReverseList(ListNode head) {
            if (head == null || head.next == null)
            {
                return head;
            }
            ListNode tempNode = ReverseList(head.next);
            head.next.next = head;
            head.next = null;
            return tempNode;
    }
}
// @lc code=end

