class MaxQueue:

    def __init__(self):
        self.deque = collections.deque()
        self.queue = collections.deque()

    def max_value(self) -> int:
        return self.deque[0] if self.deque else -1

    def push_back(self, value: int) -> None:
        while self.deque and value > self.deque[-1]:
            self.deque.pop()
        self.deque.append(value)
        self.queue.append(value)

    def pop_front(self) -> int:
        t = self.queue.popleft() if self.queue else -1
        if self.deque and t == self.deque[0]:
            self.deque.popleft()
        return t
