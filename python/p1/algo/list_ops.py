from random import randint


def is_list_sorted(lst):
    return all(lst[i] <= lst[i+1] for i in range(len(lst) - 1))


def generate_list(size):
    ret_value = []

    for i in range(size):
        ret_value.append(randint(1, size))

    return ret_value