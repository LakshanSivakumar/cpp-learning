# Calculator with a pointer result

`bool calculate(int x, int y, char op, int* result)` returns `false` for an unknown operator or division by zero,
and otherwise writes the answer through `result`. This is the common C-style way to report an error without
reserving a return value (so `5 - 5` is not mistaken for failure).

```sh
g++ -std=c++20 -Wall -Wextra -fsanitize=address,undefined -g calculator.cpp -o calculator && ./calculator
```
