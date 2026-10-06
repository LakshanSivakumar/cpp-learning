# cpp-learning

C++ exercises from learning the language after C. Each project has its own tests or a run command.

## Projects

| Folder | Contents |
|---|---|
| [`pointer-array-utils/`](pointer-array-utils/) | Seven array functions using pointer arithmetic only, with a 41-check test suite |
| [`calculator-pointer-result/`](calculator-pointer-result/) | Calculator that returns success/failure and writes the result through a pointer |
| [`basics/`](basics/) | Multi-file program, first class, pointers and references self-test (`pointers/challenge.cpp`, with a singly linked list) |

## Build

```sh
make test     # run the pointer-array-utils tests
make basics   # build the other programs into bin/
```

Compiled with `-std=c++20 -Wall -Wextra -Wpedantic -Wshadow -fsanitize=address,undefined -g`.

## Progress

| Date | Done |
|---|---|
| 6 Oct 2026 | Functions across two files; first class (`Player`) |
| 6 Oct 2026 | Calculator, reworked to return a status and write the result via a pointer; division by zero handled |
| 6 Oct 2026 | `pointer-array-utils`: print, swap, find max, reverse, rotate, remove duplicates, binary search. 41/41 tests pass |

| 7 Oct 2026 | References and pointers self-test: swap/larger/min_max via references and pointers, `new[]`/`delete[]`. Singly linked list from scratch: `push_front`, `print`, `length`, in-place `reverse`, `free_list`. 26/26 checks pass, ASan/UBSan clean |

Next:

- Oct 2026: `std::string`, `BankAccount` and `Fraction` classes, string utilities with `char**`
- Nov 2026: dynamic array class (destructor, copy and move, rule of five)
- Dec 2026 to Jan 2027: smart pointers, operator overloading, Black-Scholes pricer
