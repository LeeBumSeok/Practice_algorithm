import sys
from collections import deque 
 
input = sys.stdin.readline 
 
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0] 
 
 
def bfs(x, y):
   q = deque([(x, y)]) 
 
   while q:
       x, y = q.popleft() 
 
       for i in range(4):
           nx = x + dx[i]
           ny = y + dy[i] 
 
           if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == 1:
               q.append((nx, ny))
               graph[nx][ny] = graph[x][y] + 1
 
n, m = map(int, input().split()) 
 
graph = deque([0 for _ in range(m)] for _ in range(n))

for i in range(n):
   x = input()
   for j in range(m):
       graph[i][j] = int(x[j])
 
for i in range(n):
   for j in range(m):
       if graph[i][j] == 1:
           bfs(i, j)

print(graph[n - 1][m - 1])