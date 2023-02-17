# SORT
def sort_bubble(lst):
    for i in range(len(lst) - 1):
        j = 0
        while j < len(lst) - 1 - i:
            if lst[j] > lst[j + 1]:
                tmp = lst[j]
                lst[j] = lst[j + 1]
                lst[j + 1] = tmp
            j = j + 1

    return lst


def sort_bubble1(lst):
    for i in range(len(lst) - 1):
        swap_happened = False

        for j in range(len(lst) - i - 1):
            if lst[j] > lst[j + 1]:
                swap_happened = True
                lst[j], lst[j + 1] = lst[j + 1], lst[j]

        if not swap_happened:
            break

    return lst


def sort_bubble2(lst):
    for i in range(len(lst) - 1):
        for j in range(len(lst) - i - 1):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]

    return lst


def sort_shaker1(lst):
    if not lst:
        return None

    left = 0
    right = len(lst) - 1

    while left <= right:
        for i in range(right, left, -1):
            if lst[i - 1] > lst[i]:
                lst[i - 1], lst[i] = lst[i], lst[i - 1]

        left += 1

        for i in range(left, right, 1):
            if lst[i] > lst[i + 1]:
                lst[i], lst[i + 1] = lst[i + 1], lst[i]

        right -= 1

    return lst


def comb_sort(lst):
    factor = 1.247  # Фактор уменьшения
    n = len(lst)
    step = n

    while step > 1 or flag:
        if step > 1:
            step = int(step / factor)

        flag, p = False, 0

        while p + step < n:
            if lst[p] > lst[p + step]:
                lst[p], lst[p + step] = lst[p + step], lst[p]
                flag = True

            p += 1

    return lst


def insert_sort(lst):
    for i in range(1, len(lst)):
        x = lst[i]
        j = i

        while j > 0 and lst[j - 1] > x:
            lst[j] = lst[j - 1]
            j -= 1

        lst[j] = x

    return lst
