from collections import deque


def bfs(start, adj_list):
    queue = deque([(start, 0)])
    visited = set([start])
    while queue:
        city, time = queue.popleft()
        if city == n:
            return time
        for neighbor in adj_list[city]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append((neighbor, time + 1))
    return -1


n, m = map(int, input().split())
railways = [[] for _ in range(n + 1)]
roads = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v = map(int, input().split())
    railways[u].append(v)
    railways[v].append(u)

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i != j and j not in railways[i]:
            roads[i].append(j)

train_time = bfs(1, railways)
bus_time = bfs(1, roads)

if train_time == -1 or bus_time == -1:
    print(-1)
else:
    print(max(train_time, bus_time))
