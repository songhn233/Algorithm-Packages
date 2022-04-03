function removeElements(head, val) {
    head = new ListNode(0, head);
    var pre = head, cur = head.next;
    while (cur) {
        if (cur.val === val) {
            pre.next = cur.next;
        }
        else {
            pre = pre.next;
        }
        cur = cur.next;
    }
    return head.next;
}
