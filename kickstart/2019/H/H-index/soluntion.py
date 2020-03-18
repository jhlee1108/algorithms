import sys
import heapq


def solution():
    number_of_papers = int(sys.stdin.readline())
    citations = [int(x) for x in sys.stdin.readline().split()]
    min_heap = []
    hindices = []
    hindex = 0

    for citation in citations:
        if citation > hindex:
            heapq.heappush(min_heap, (citation, citation))
            while hindex < len(min_heap) and min_heap[0][1] <= hindex:
                heapq.heappop(min_heap)
            hindex = min(min_heap[0][1], len(min_heap))
        hindices.append(str(hindex))

    return ' '.join(hindices)


if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for tc in range(testcase):
        answer = solution()
        print(f'Case #{tc} : {answer}')
