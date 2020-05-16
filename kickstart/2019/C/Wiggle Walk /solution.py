import sys


def add(current_row, current_column, row_start_dict, row_end_dict, column_start_dict, column_end_dict):
    row_start_dict[current_row][current_column] = current_column
    row_end_dict[current_row][current_column] = current_column
    column_start_dict[current_column][current_row] = current_row
    column_end_dict[current_column][current_row] = current_row


def merge(current_row, current_column, row_start_dict, row_end_dict, column_start_dict, column_end_dict):
    if (current_column - 1) in row_end_dict[current_row]:
        row_start_dict[current_row][row_end_dict[current_row][current_column - 1]] = current_column
        row_end_dict[current_row][current_column] = row_end_dict[current_row][current_column - 1]
        
    if (current_column + 1) in row_start_dict[current_row]:
        row_start_dict[current_row][row_end_dict[current_row][current_column]] = row_start_dict[current_row][current_column + 1]
        row_start_dict[current_row][current_column] = row_start_dict[current_row][current_column + 1]
        row_end_dict[current_row][row_start_dict[current_row][current_column + 1]] = row_end_dict[current_row][current_column]
        
    if (current_row - 1) in column_end_dict[current_column]:
        column_start_dict[current_column][column_end_dict[current_column][current_row - 1]] = current_row
        column_end_dict[current_column][current_row] = column_end_dict[current_column][current_row - 1]
        
    if (current_row + 1) in column_start_dict[current_column]:
        column_start_dict[current_column][column_end_dict[current_column][current_row]] = column_start_dict[current_column][current_row + 1]
        column_start_dict[current_column][current_row] = column_start_dict[current_column][current_row + 1]
        column_end_dict[current_column][column_start_dict[current_column][current_row + 1]] = column_end_dict[current_column][current_row]        


def get_next_position(current_row, current_column, instruction, row_start_dict, row_end_dict, column_start_dict, column_end_dict):
    if instruction == 'E':
        if current_column in row_start_dict[current_row]:
            current_column = row_start_dict[current_row][current_column] + 1
        else:
            current_column = current_column + 1
    elif instruction == 'W':
        if current_column in row_end_dict[current_row]:
            current_column = row_end_dict[current_row][current_column] - 1
        else:
            current_column = current_column - 1
    elif instruction == 'S':
        if current_row in column_start_dict[current_column]:
            current_row = column_start_dict[current_column][current_row] + 1
        else:
            current_row = current_row + 1
    else:
        if current_row in column_end_dict[current_column]:
            current_row = column_end_dict[current_column][current_row] - 1
        else:
            current_row = current_row - 1

    return current_row, current_column


def solution():
    number_of_instructions, number_of_rows, number_of_columns, starting_row, starting_column = [int(x) for x in sys.stdin.readline().split()]
    instructions = sys.stdin.readline().strip()

    row_start_dict = [{} for _ in range(number_of_rows + 1)]
    row_end_dict = [{} for _ in range(number_of_rows + 1)]
    column_start_dict = [{} for _ in range(number_of_columns + 1)]
    column_end_dict = [{} for _ in range(number_of_columns + 1)]
    current_row = starting_row
    current_column = starting_column
    add(current_row, current_column, row_start_dict, row_end_dict, column_start_dict, column_end_dict)

    for instruction in instructions:
        current_row, current_column = get_next_position(current_row, current_column, instruction, row_start_dict, row_end_dict, column_start_dict, column_end_dict)
        add(current_row, current_column, row_start_dict, row_end_dict, column_start_dict, column_end_dict)
        merge(current_row, current_column, row_start_dict, row_end_dict, column_start_dict, column_end_dict)
    
    return ' '.join([str(current_row), str(current_column)])


if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for tc in range(testcase):
        answer = solution()
        print('Case #{0}: {1}'.format(tc+1, answer))
