import sys
import queue


def solution():
    number_of_consulates, number_of_guests, number_of_minutes = [int(n) for n in sys.stdin.readline().split()]
    cw_consulates = [[] for _ in range(number_of_consulates)]
    cw_groups = set()
    acw_consulates = [[] for _ in range(number_of_consulates)]
    acw_groups = set()
    consulates = [[] for _ in range(number_of_consulates)]
    group_mapping = dict()
    group_count = dict()

    for guest in range(number_of_guests):
        start_consulate, direction = [c for c in sys.stdin.readline().split()]
        if direction == 'C':
            end_consulate = (int(start_consulate) + number_of_minutes - 1) %  number_of_consulates
            cw_consulates.append(end_consulate)
            cw_groups.add(end_consulate)
        else:
            end_consulate = (int(start_consulate) - (number_of_minutes % number_of_consulates) + number_of_consulates - 1) % number_of_consulates
            acw_consulates.append(end_consulate)
            acw_groups.add(end_consulate)
        group_mapping[guest] = (direction, end_consulate)
        group_count[group_mapping[guest]] = 0

    cw_groups = sorted(list(cw_groups))
    acw_groups = sorted(list(acw_groups), reverse=True)

    consulate_idx = 0
    for cw_group in cw_groups:
        while cw_group >= consulate_idx:
            if cw_group - consulate_idx <= number_of_minutes:
                consulates[consulate_idx].append((cw_group, 'C', cw_group - consulate_idx))
            consulate_idx += 1
        if consulate_idx < number_of_consulates and cw_group == cw_groups[-1]:
            cw_group = cw_groups[0]
            while consulate_idx < number_of_consulates:
                if number_of_consulates - consulate_idx + cw_group <= number_of_minutes:
                    consulates[consulate_idx].append((cw_group, 'C', number_of_consulates - consulate_idx + cw_group))
                consulate_idx += 1
    
    consulate_idx = number_of_consulates - 1
    for acw_group in acw_groups:
        while acw_group <= consulate_idx:
            if consulate_idx - acw_group <= number_of_minutes:
                consulates[consulate_idx].append((acw_group, 'A', consulate_idx - acw_group))
            consulate_idx -= 1
        if consulate_idx < number_of_consulates and acw_group == acw_groups[-1]:
            acw_group = acw_groups[0]
            while consulate_idx >= 0:
                if number_of_consulates - acw_group + consulate_idx <= number_of_minutes:
                    consulates[consulate_idx].append((acw_group, 'A', number_of_consulates - acw_group + consulate_idx))
                consulate_idx -= 1
    
    for i in range(number_of_consulates):
        if len(consulates[i]) == 0:
            continue
        elif len(consulates[i]) == 1:
            group_count[(consulates[i][0][1], consulates[i][0][0])] += 1
        else:
            if consulates[i][0][2] < consulates[i][1][2]:
                group_count[(consulates[i][0][1], consulates[i][0][0])] += 1
            elif consulates[i][0][2] > consulates[i][1][2]:
                group_count[(consulates[i][1][1], consulates[i][1][0])] += 1
            else:
                group_count[(consulates[i][0][1], consulates[i][0][0])] += 1
                group_count[(consulates[i][1][1], consulates[i][1][0])] += 1

    return ' '.join([str(group_count[group_mapping[i]]) for i in range(number_of_guests)])


if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for tc in range(testcase):
        answer = solution()
        print('Case #{0}: {1}'.format(tc+1, answer))
