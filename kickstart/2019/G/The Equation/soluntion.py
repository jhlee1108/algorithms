import sys


def solution():
    answer = 0
    number_of_integers, limit = [int(n) for n in sys.stdin.readline().split()]
    universe = [int(n) for n in sys.stdin.readline().split()]

    for i in range(0, 51):
        mask = pow(2, i)
        cnt = 0
        for number in universe:
            if (number & mask) == mask:
                cnt += 1
        if cnt > (number_of_integers // 2):
            answer += mask

    if sum([number ^ answer for number in universe]) > limit:
        return -1

    for i in range(50, -1, -1):
        mask = answer | pow(2, i)
        if sum([number ^ mask for number in universe]) <= limit:
            answer = mask

    return answer


if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for tc in range(testcase):
        answer = solution()
        print('Case #{0}: {1}'.format(tc+1, answer))
