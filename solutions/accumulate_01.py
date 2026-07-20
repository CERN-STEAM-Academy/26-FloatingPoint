
from decimal import Decimal, getcontext

def foo(precision: int):
    getcontext().prec = precision
    s = Decimal(0)
    tenth = Decimal('0.1')
    for _ in range(10000):
        s += tenth
    print(f"decimal{precision}: {s}  (err: {s - 1000})")

foo(2)
foo(5)
