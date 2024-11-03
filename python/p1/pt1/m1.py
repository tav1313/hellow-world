import random
from threading import Thread

import pytest


class A1:
    fi1 = None

    def __init__(self):
        self.setfi1(5566)

    def setfi1(self, value):
        self.fi1 = value

    pass


def test_do1(f1):
    a1 = A1()
    A1.fi1 = 1213
    print(f"\nclazzz a1: {a1.fi1} A1: {A1.fi1}")
    print(f1)
    assert f1 < 13


# @pytest.mark.repeat(2)
@pytest.mark.parametrize('et', range(1))
def test_do2(et, f1, f2):
    print(f"\nf1 value is {f1}")
    # f2
    assert f1 > 12


@pytest.fixture
def f1():
    return 1 + random.randint(2, 44)


@pytest.fixture
def f2():
    print("\nf2 start")
    yield
    print('destroy 1122')
