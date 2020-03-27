import sys


def solution():
    number_of_pages, number_of_torn_out_pages, number_of_readers = [int(n) for n in sys.stdin.readline().split()]
    torn_out_pages = [int(n) for n in sys.stdin.readline().split()]
    reader_pages = [int(n) for n in sys.stdin.readline().split()]
    answer = 0

    exists_page = [True for _ in range(number_of_pages + 1)]
    for torn_out_page in torn_out_pages:
        exists_page[torn_out_page] = False
    
    reading_pages = [0 for _ in range(number_of_pages + 1)]
    for page in range(1, number_of_pages + 1):
        current_page = page
        while current_page <= number_of_pages:
            if exists_page[current_page]:
                reading_pages[page] += 1
            current_page += page
    
    answer = sum([reading_pages[i] for i in reader_pages])

    return answer


if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for tc in range(testcase):
        answer = solution()
        print('Case #{0}: {1}'.format(tc+1, answer))
