#include <iostream>




void print_array(int *arr, int n){
    for (int i = 0; i < n; i++){
        std::cout << *(arr+i) << " ";
    }
    std::cout << "\n";
}

void swap(int *a, int *b){
    int temp{*a};
    *a = *b;
    *b = temp; 
}

bool find_max(int *arr, int n, int *result){
    if (n == 0){
        return false;
    }
    *result = *arr;

    for (int i = 1; i < n; i++){
        if (*(arr+i) > *result){
            *result = *(arr+i);
        }
    }
    return true;
}

void reverse(int* arr, int n){
    int *left = arr;
    int *right = arr + n - 1;
    while (left < right){
        swap(left, right);
        left++;
        right--;
    }
}


void rotate_left(int *arr, int n, int k){
    if (n <= 0){
        return;
    }
    k = k % n;
    if (k == 0){
        return;
    }
    reverse(arr, k);
    reverse(arr+k, n-k);
    reverse(arr, n);
}

int remove_duplicates(int* arr, int n){
    if (n == 0){
        return 0;
    }
    int *write = arr + 1;
    for (int *read = arr+1; read < arr + n; read++){
        if (*read != *(write-1)){
            *write = *read;
            write++;
        } 
    }
    return write - arr;

}

int* binary_search(int* arr, int n, int target){

   int *low = arr;
   int * high = arr + n - 1;

   while (low <= high){
        int *mid = low + (high - low) / 2;
        if (*mid == target){
            return mid;
        }
        else if (*mid < target){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
   }
   return nullptr;

}













int passed = 0;
int failed = 0;

void check(bool condition, const char* name) {
    if (condition) {
        ++passed;
    } else {
        ++failed;
        std::cout << "FAIL: " << name << '\n';
    }
}

bool same(const int* a, const int* b, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}


int main() {
    // ---------- print_array (visual check) ----------
    {
        int a[] = {1, 2, 3};
        std::cout << "print_array should show 1 2 3: ";
        print_array(a, 3);
        std::cout << "print_array on empty (should print nothing): ";
        print_array(a, 0);
        std::cout << '\n';
    }

    // ---------- swap ----------
    {
        int x = 3, y = 9;
        swap(&x, &y);
        check(x == 9 && y == 3, "swap basic");

        int z = 5;
        swap(&z, &z);  // swapping with itself must not break
        check(z == 5, "swap same variable");
    }

    // ---------- find_max ----------
    {
        int result = -999;

        int a[] = {5, 3, 8, 1, 9, 2};
        check(find_max(a, 6, &result) && result == 9, "find_max normal");

        int b[] = {-7, -3, -10};
        check(find_max(b, 3, &result) && result == -3, "find_max all negative");

        int c[] = {42};
        check(find_max(c, 1, &result) && result == 42, "find_max single");

        int d[] = {9, 1, 2};
        check(find_max(d, 3, &result) && result == 9, "find_max max at start");

        int e[] = {1, 2, 9};
        check(find_max(e, 3, &result) && result == 9, "find_max max at end");

        int empty[1] = {0};
        result = -999;
        check(!find_max(empty, 0, &result), "find_max empty returns false");
        check(result == -999, "find_max empty leaves result untouched");
    }

    // ---------- reverse ----------
    {
        int a[] = {1, 2, 3, 4};
        int a_exp[] = {4, 3, 2, 1};
        reverse(a, 4);
        check(same(a, a_exp, 4), "reverse even length");

        int b[] = {1, 2, 3, 4, 5};
        int b_exp[] = {5, 4, 3, 2, 1};
        reverse(b, 5);
        check(same(b, b_exp, 5), "reverse odd length");

        int c[] = {7};
        reverse(c, 1);
        check(c[0] == 7, "reverse single");

        int d[] = {1, 2, 3};
        reverse(d, 0);
        int d_exp[] = {1, 2, 3};
        check(same(d, d_exp, 3), "reverse n=0 changes nothing");

        int e[] = {-1, 0, 1};
        int e_exp[] = {1, 0, -1};
        reverse(e, 3);
        check(same(e, e_exp, 3), "reverse with negatives");
    }

    // ---------- rotate_left ----------
    {
        int exp2[] = {3, 4, 5, 1, 2};
        int orig[] = {1, 2, 3, 4, 5};

        int a[] = {1, 2, 3, 4, 5};
        rotate_left(a, 5, 2);
        check(same(a, exp2, 5), "rotate_left k=2");

        int b[] = {1, 2, 3, 4, 5};
        rotate_left(b, 5, 0);
        check(same(b, orig, 5), "rotate_left k=0");

        int c[] = {1, 2, 3, 4, 5};
        rotate_left(c, 5, 5);
        check(same(c, orig, 5), "rotate_left k=n");

        int d[] = {1, 2, 3, 4, 5};
        rotate_left(d, 5, 7);  // 7 % 5 == 2
        check(same(d, exp2, 5), "rotate_left k>n");

        int e[] = {1, 2, 3, 4, 5};
        int e_exp[] = {2, 3, 4, 5, 1};
        rotate_left(e, 5, 1);
        check(same(e, e_exp, 5), "rotate_left k=1");

        int f[] = {1, 2, 3, 4, 5};
        int f_exp[] = {5, 1, 2, 3, 4};
        rotate_left(f, 5, 4);
        check(same(f, f_exp, 5), "rotate_left k=n-1");

        int g[] = {9};
        rotate_left(g, 1, 3);
        check(g[0] == 9, "rotate_left single");

        int h[] = {1, 2, 3};
        rotate_left(h, 0, 2);  // must not crash (k % 0 is undefined!)
        int h_exp[] = {1, 2, 3};
        check(same(h, h_exp, 3), "rotate_left n=0 changes nothing");
    }

    // ---------- remove_duplicates (sorted input) ----------
    {
        int a[] = {1, 1, 2, 2, 2, 3};
        int a_exp[] = {1, 2, 3};
        int len = remove_duplicates(a, 6);
        check(len == 3 && same(a, a_exp, 3), "remove_duplicates normal");

        int b[] = {4, 4, 4, 4};
        len = remove_duplicates(b, 4);
        check(len == 1 && b[0] == 4, "remove_duplicates all equal");

        int c[] = {1, 2, 3, 4};
        int c_exp[] = {1, 2, 3, 4};
        len = remove_duplicates(c, 4);
        check(len == 4 && same(c, c_exp, 4), "remove_duplicates no duplicates");

        int d[] = {5};
        len = remove_duplicates(d, 1);
        check(len == 1 && d[0] == 5, "remove_duplicates single");

        int e[1] = {0};
        len = remove_duplicates(e, 0);
        check(len == 0, "remove_duplicates empty");

        int f[] = {-3, -3, -1, 0, 0, 2};
        int f_exp[] = {-3, -1, 0, 2};
        len = remove_duplicates(f, 6);
        check(len == 4 && same(f, f_exp, 4), "remove_duplicates negatives");

        int g[] = {1, 2, 2};
        int g_exp[] = {1, 2};
        len = remove_duplicates(g, 3);
        check(len == 2 && same(g, g_exp, 2), "remove_duplicates duplicate at end");
    }

    // ---------- binary_search (sorted input) ----------
    {
        int a[] = {-5, -2, 0, 3, 7, 9, 12};
        int n = sizeof(a) / sizeof(a[0]);

        int* p = binary_search(a, n, -5);
        check(p == a, "binary_search first element");

        p = binary_search(a, n, 12);
        check(p == a + 6, "binary_search last element");

        p = binary_search(a, n, 3);
        check(p == a + 3 && (p - a) == 3, "binary_search middle + index via subtraction");

        p = binary_search(a, n, 0);
        check(p == a + 2, "binary_search negative/zero region");

        check(binary_search(a, n, 4) == nullptr, "binary_search missing in range");
        check(binary_search(a, n, -100) == nullptr, "binary_search below range");
        check(binary_search(a, n, 100) == nullptr, "binary_search above range");

        int empty[1] = {0};
        check(binary_search(empty, 0, 5) == nullptr, "binary_search empty");

        int one[] = {8};
        check(binary_search(one, 1, 8) == one, "binary_search single found");
        check(binary_search(one, 1, 7) == nullptr, "binary_search single missing");

        int two[] = {1, 2};
        check(binary_search(two, 2, 2) == two + 1, "binary_search two elements, second");
        check(binary_search(two, 2, 1) == two, "binary_search two elements, first");
    }

    std::cout << "\nPassed: " << passed << "  Failed: " << failed << '\n';
    return failed == 0 ? 0 : 1;
}