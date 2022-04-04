function swapPairs(head) {
    head = new ListNode(0, head);
    var p = head.next, q = head;
    while (p && p.next) {
        q.next = p.next;
        var tmp = p.next.next;
        p.next.next = p;
        p.next = tmp;
        q = p;
        p = tmp;
    }
    return head.next;
}
