import random

import pytest


def test_do1(f1):
    print(f1)
    assert f1 < 13


def test_do2(f1):
    print(f1)
    assert f1 > 12


@pytest.fixture
def f1():
    return 1 + random.randint(2, 44)