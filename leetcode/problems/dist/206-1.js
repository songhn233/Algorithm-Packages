function reverseList(head) {
    var p = null, q = head;
    while (q) {
        var tmp = q.next;
        q.next = p;
        p = q;
        q = tmp;
    }
    return p;
}
