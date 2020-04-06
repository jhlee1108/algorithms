import sys
from collections import defaultdict
from itertools import combinations


def solution():
    number_of_employees, number_of_skills = [int(n) for n in sys.stdin.readline().split()]
    employee_skills = []
    number_of_employees_who_cannot_teach_by_skills = defaultdict(int)

    for i in range(number_of_employees):
        _, *skills = [int(n) for n in sys.stdin.readline().split()]
        skills.sort()
        employee_skills.append(tuple(skills))
        
        for length_of_subset in range(1, len(skills)+1):
            for subset in combinations(skills, length_of_subset):
                number_of_employees_who_cannot_teach_by_skills[subset] += 1

    return sum([number_of_employees - number_of_employees_who_cannot_teach_by_skills[skills] for skills in employee_skills])


if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for tc in range(testcase):
        print('Case #{0}: {1}'.format(tc+1, solution()))
