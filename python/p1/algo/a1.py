from random import randint
from functools import partial
import time


def generate_list(size):
    ret_value = []
    for i in range(size):
        ret_value.append(randint(1, 99))

    return ret_value


def sort_bubble(lst):
    for i in range(len(lst) - 1):
        # print("iteration: ", i)
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


def sort_bubble2(lst):
    for i in range(len(lst) - 1):
        for j in range(len(lst) - i - 1):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]


def search_linear(lst, value):
    for i in enumerate(lst):
        if i[1] == value:
            return i[0]

    return None


def search_bin(lst, value):
    pass


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    lst = [9, 1, 6, 5, 3]
    print("linear search idx: ", search_linear(lst, 55))
    sort_bubble(lst)
    print("bubbled list: ", lst)

    lst = [9, 1, 6, 5, 3]
    sort_bubble1(lst)
    print("bubbled list1: ", lst)

    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.
    lst = [1, 4, 5, 9]
    for i, v in enumerate(lst):
        print(i, ' ', v)
    return name


def measure_sort_time(list_size, sort_func):
    lst = generate_list(list_size)
    start_time = time.time()
    sort_func(lst)
    end_time = time.time()
    print("time passed:", end_time - start_time)


def set_time(flag):
    return time.process_time() if flag else time.time()


def measure_time1(func, is_proc_time=False):
    start_time = set_time(is_proc_time)
    func_ret_value = func()
    end_time = set_time(is_proc_time)

    if func_ret_value:
        print("func_ret_value: ", func_ret_value)

    print("func_name: ", func)
    print("time passed:", end_time - start_time)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # print_hi('PyCharm')
    # measure_sort_time(10 * 1000, sort_bubble1)
    # measure_time1(lambda: sort_bubble2(generate_list(10 * 1000)))
    measure_time1(partial(sort_bubble1, generate_list(10 * 1000)), True)
    # measure_time1(partial(sort_bubble1, generate_list(10 * 1000)))
    # measure_time1(partial(sort_bubble2, generate_list(10 * 1000)))
    measure_time1(lambda: search_linear(generate_list(10 * 1000), 55))
