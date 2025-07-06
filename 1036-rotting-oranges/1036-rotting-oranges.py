class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        minutes = 0
        fresh_count = 0
        q = deque()
        rows = len(grid)
        cols = len(grid[0])
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    q.append([r, c])
                if grid[r][c] == 1:
                    fresh_count += 1
        
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        while q and fresh_count > 0:
            
            for i in range(len(q)):
                r, c = q.popleft()
                
                for dr, dc in directions:
                    row = dr + r
                    col = dc + c

                    if row < 0 or row == rows or col < 0 or col == cols or grid[row][col] != 1:
                        continue
                    
                    grid[row][col] = 2
                    q.append([row, col])
                    fresh_count -= 1
            minutes += 1
        
        return minutes if fresh_count == 0 else -1

                    
                    