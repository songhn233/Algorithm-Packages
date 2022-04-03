var MyLinkedList = /** @class */ (function () {
    function MyLinkedList() {
        this.list = new ListNode();
        this.size = 0;
    }
    MyLinkedList.prototype.get = function (index) {
        var p = this.list;
        if (index >= this.size) {
            return -1;
        }
        else {
            while (index >= 0) {
                p = p.next;
                --index;
            }
            return p.val;
        }
    };
    MyLinkedList.prototype.addAtHead = function (val) {
        var q = new ListNode(val);
        var p = this.list;
        q.next = p.next;
        p.next = q;
        ++this.size;
    };
    MyLinkedList.prototype.addAtTail = function (val) {
        var p = this.list;
        while (p.next) {
            p = p.next;
        }
        p.next = new ListNode(val);
        ++this.size;
    };
    MyLinkedList.prototype.addAtIndex = function (index, val) {
        if (index < 0) {
            this.addAtHead(val);
        }
        else if (this.size === index) {
            var p = this.list;
            while (p.next) {
                p = p.next;
            }
            p.next = new ListNode(val);
            ++this.size;
        }
        else if (index < this.size) {
            var cur = this.list, pre = new ListNode();
            while (index >= 0) {
                pre = cur;
                cur = cur.next;
                --index;
            }
            var q = new ListNode(val);
            q.next = pre.next;
            pre.next = q;
            ++this.size;
        }
    };
    MyLinkedList.prototype.deleteAtIndex = function (index) {
        var p = this.list;
        var pre = new ListNode();
        if (index >= this.size) {
            return;
        }
        else {
            while (index >= 0) {
                pre = p;
                p = p.next;
                --index;
            }
            pre.next = p.next;
            --this.size;
        }
    };
    return MyLinkedList;
}());
