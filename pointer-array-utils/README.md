# Pointer array utilities

Seven functions on a plain `int` array, written with pointer arithmetic only. The rule: no `arr[i]` indexing
inside the functions (indexing is allowed in the tests).

| Function | Behaviour |
|---|---|
| `print_array(arr, n)` | Prints the elements on one line |
| `swap(a, b)` | Swaps two ints through pointers |
| `find_max(arr, n, &result)` | Writes the maximum to `result`; returns `false` for an empty array |
| `reverse(arr, n)` | In place, two pointers moving inward, uses `swap` |
| `rotate_left(arr, n, k)` | In place, three reversals; handles `k > n` and `n == 0` |
| `remove_duplicates(arr, n)` | Sorted input; read/write pointers; returns the new length |
| `binary_search(arr, n, target)` | Sorted input; returns a pointer to the match or `nullptr` |

## Run the tests

```sh
g++ -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -fsanitize=address,undefined -g arrays.cpp -o arrays
./arrays
```

Expected last line: `Passed: 41  Failed: 0`

## Notes

- `remove_duplicates` does not shrink the array. It moves the unique values to the front and returns how many there are;
  the tail holds leftover values and should be ignored.
- The test suite covers empty and single-element arrays, negatives, duplicates, and the first, last and missing cases.
