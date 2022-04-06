function removeNthFromEnd(head, n) {
    head = new ListNode(0, head);
    var p = head, q = head;
    while (n--) {
        p = p.next;
    }
    while (p.next) {
        p = p.next;
        q = q.next;
    }
    q.next = q.next.next;
    return head.next;
}
