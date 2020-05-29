import sys


def solution():
    number_of_blocks, number_of_questions = [int(x) for x in sys.stdin.readline().split()]
    blocks = sys.stdin.readline()
    
    csum = [[0 for _ in range(26)] for __ in range(number_of_blocks + 1)]
    for i in range(number_of_blocks):
        for j in range(26):
            csum[i+1][j] = csum[i][j]
        csum[i+1][ord(blocks[i]) - ord('A')] += 1
    
    answer = 0
    for _ in range(number_of_questions):
        left_index, right_index = [int(x) for x in sys.stdin.readline().split()]
        sub_blocks_csum = [csum[right_index][i] - csum[left_index - 1][i] for i in range(26)]
        answer += 1 if sum([1 for number_of_letters in sub_blocks_csum if (number_of_letters % 2) == 1]) <= 1 else 0

    return answer


if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for tc in range(testcase):
        answer = solution()
        print('Case #{0}: {1}'.format(tc+1, answer))
