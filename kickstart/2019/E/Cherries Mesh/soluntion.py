import sys
import queue


def solution():
    number_of_cherries, number_of_black_sweet_strands = [int(n) for n in sys.stdin.readline().split()]
    graph = [[] for _ in range(number_of_cherries+1)]
    visited = [False for _ in range(number_of_cherries+1)]
    for _ in range(number_of_black_sweet_strands):
        cherry1, cherry2 = [int(n) for n in sys.stdin.readline().split()]
        graph[cherry1].append(cherry2)
        graph[cherry2].append(cherry1)
    
    answer = -2
    for cherry in range(1, number_of_cherries+1):
        if visited[cherry]:
            continue
        q = queue.Queue()
        visited[cherry] = True
        q.put(cherry)
        while not q.empty():
            current_cherry = q.get()
            for neighbor_cherry in graph[current_cherry]:
                if visited[neighbor_cherry]:
                    continue
                visited[neighbor_cherry] = True
                q.put(neighbor_cherry)
                answer += 1
        answer += 2

    return answer


if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for tc in range(testcase):
        answer = solution()
        print('Case #{0}: {1}'.format(tc+1, answer))
