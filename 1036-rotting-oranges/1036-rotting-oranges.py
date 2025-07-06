class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        minutes = 0
        queue = deque()
        rows = len(grid)
        cols = len(grid[0])
        fresh_count = 0
        
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 2:
                    queue.append([row, col])
                if grid[row][col] == 1:
                    fresh_count += 1
        
        directions = [[-1,0], [1, 0], [0, -1], [0, 1]]

        while queue and fresh_count > 0:
            for i in range(len(queue)):
                r, c = queue.popleft()

                for dr, dc in directions:
                    row, col = dr + r, dc + c

                    if row < 0 or row == len(grid) or col < 0 or col == len(grid[0]) or grid[row][col] != 1:
                        continue
                    grid[row][col] = 2
                    queue.append([row, col])
                    fresh_count -= 1          
            minutes += 1
        
        return minutes if fresh_count == 0 else -1

                    
                    