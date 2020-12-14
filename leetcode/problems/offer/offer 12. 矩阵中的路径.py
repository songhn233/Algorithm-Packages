class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
        vis = [[False] * len(board[0]) for i in range(len(board))]

        def inside(x, y):
            return x >= 0 and x < len(board) and y >= 0 and y < len(board[0])

        def dfs(i, j, word, dep):
            if not inside(i, j) or not board[i][j] == word[dep] or vis[i][j]:
                return False
            if dep + 1 == len(word):
                return True
            vis[i][j] = True
            for t in range(0, 4):
                tx, ty = i + dx[t], j + dy[t]
                if dfs(tx, ty, word, dep + 1):
                    return True
            vis[i][j] = False
            return False
        for i in range(0, len(board)):
            for j in range(0, len(board[i])):
                if dfs(i, j, word, 0):
                    return True
        return False
