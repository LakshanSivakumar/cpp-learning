// References and pointers self-test.
//
// Fill in every TODO, then compile and run. The tests start out failing; the goal is "Failed: 0".
// Rules: no looking things up while writing a tier. Check afterwards.
//
// Build:
//   g++ -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -fsanitize=address,undefined -g challenge.cpp -o challenge && ./challenge
// (unused-parameter warnings disappear as you fill the functions in)

#include <cstddef>
#include <iostream>
#include <vector>

// ============================================================
// Tier 1: references
// ============================================================

// 1. Swap two ints. The call site must not use &.
void swap_ref(int& a, int& b) {
    // TODO
    int temp{a};
    a = b;
    b = temp;
}

// 2. Return a reference to whichever argument is bigger (so larger(x, y) = 0; changes the bigger variable).
int& larger(int& a, int& b) {
    // TODO
    return a > b ? a : b;
}

// 3. Add 1 to every element. Use a range-based for with a reference.
void increment_all(std::vector<int>& v) {
    
    for (auto &element: v){
        element++;
    }
}

// 4. Sum the elements without copying the vector.
int sum(const std::vector<int>& v) {
    // TODO
    int total{0};
    for (auto &element: v){
        total+= element;
    }
    return total;
}

// ============================================================
// Tier 2: pointers
// ============================================================

// 5. Pointer to the first element equal to target, or nullptr.
int* find_first(int* arr, int n, int target) {
    // TODO
    for (int i = 0; i < n; i++){
        if (*(arr+i) == target){
            return arr+i;
        }
    }
    return nullptr;
}

// 6a. Write the smallest and largest value through the pointers. Assume n >= 1.
void min_max(const int* arr, int n, int* min, int* max) {
    *min = *arr;
    *max = *arr;
    for (int i = 1; i < n; i++){
        if (*(arr+i) > *max){
            *max = *(arr+i);
        }
        if (*(arr+i) < *min){
            *min = *(arr+i);
        }
    }
}

// 6b. Same thing, with references.
void min_max_ref(const int* arr, int n, int& min, int& max) {
    // TODO
    min = *arr;
    max = *arr;
    for (int i = 1; i < n; i++){
        if (*(arr+i) > max){
            max = *(arr+i);
        }
        if (*(arr+i) < min){ 
            min = *(arr+i);
        }
    }
}

// 7. Allocate n ints with new[], set each to value, return the pointer. The caller frees it with delete[].
int* make_filled(int n, int value) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = value;
    }
    return arr;
}

// ============================================================
// Tier 3: the traps (predict first, then run)
// ============================================================
//
// Q8. Why is this broken? Fix it two different ways. Enable it by changing #if 0 to #if 1 and read the warning.
#if 1
int& bad() {
    int x = 5;
    return x;
}
#endif
// Q8 my explanation:
//
// Q8 fix 1: int bad ()
// Q8 fix 2: static int x = 5

// Q9. Write your prediction in the comment, THEN run.
void predict_q9() {
    int a = 1, b = 2;
    int* p = &a;
    int* q = &b;
    p = q;
    *p = 10;
    std::cout << "Q9:  " << a << ' ' << b << ' ' << (p == q) << '\n';
}
// Q9 my prediction: Q: 1 10 1

// Q10. Write your prediction in the comment, THEN run.
void predict_q10() {
    int a = 1, b = 2;
    int& r = a;
    r = b;
    r = 99;
    std::cout << "Q10: " << a << ' ' << b << '\n';
}
// Q10 my prediction: Q10: 99 2

// Q11. Declare one pointer-to-const and one const pointer, both to ints (put them in a function or in main).
// For each, write which of  *p = 5;  and  p = &other;  compiles, then check with the compiler.
// Q11 my answer:

// ============================================================
// Tier 4: singly linked list (raw pointers)
// ============================================================

struct Node {
    int value;
    Node* next;
};

// Insert a new node at the front. head is a reference to the caller's pointer, so it can be changed.
void push_front(Node*& head, int v) {
    // TODO
    Node *n = new Node{v, head};
    head = n;

}

// Print as: 3 -> 2 -> 1 -> null
void print(const Node* head) {
    for (const Node*p = head; p != nullptr; p = p->next){
        std::cout << p->value << " -> ";
    }
    std::cout << "null" << '\n';
}

int length(const Node* head) {
    // TODO
    int count{0};
    for (const Node*p = head; p != nullptr; p = p->next){
        count++;
    }
    return count;
}

// Reverse the list in place (relink the nodes; do not allocate new ones).
void reverse(Node*& head) {
    Node *prev = nullptr;
    Node *next = nullptr;
    for (Node *p = head; p != nullptr; p = next){
        next = p->next;
        p->next = prev;
        prev = p;

    }
    head = prev;
}

// Delete every node and leave head as nullptr.
void free_list(Node*& head) {

    while (head != nullptr){
        Node *next = head->next;
        delete head;
        head = next;
    }

}

// ============================================================
// Test harness (nothing to edit below this line)
// ============================================================

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

bool list_equals(const Node* head, const std::vector<int>& expected) {
    for (int e : expected) {
        if (head == nullptr || head->value != e) return false;
        head = head->next;
    }
    return head == nullptr;
}

void test_tier1() {
    int x = 3, y = 9;
    swap_ref(x, y);
    check(x == 9 && y == 3, "swap_ref");

    int a = 4, b = 7;
    larger(a, b) = 0;
    check(a == 4 && b == 0, "larger returns a reference to the bigger one");
    int c = 8, d = 2;
    larger(c, d) = -1;
    check(c == -1 && d == 2, "larger, first argument bigger");

    std::vector<int> v{1, 2, 3};
    increment_all(v);
    check(v == std::vector<int>({2, 3, 4}), "increment_all");
    std::vector<int> empty;
    increment_all(empty);
    check(empty.empty(), "increment_all empty");

    check(sum(std::vector<int>{1, 2, 3, 4}) == 10, "sum");
    check(sum(std::vector<int>{}) == 0, "sum empty");
    check(sum(std::vector<int>{-5, 5, -2}) == -2, "sum negatives");
}

void test_tier2() {
    int arr[] = {4, 8, 15, 8, 23};
    int* p = find_first(arr, 5, 8);
    check(p == arr + 1, "find_first returns the first match");
    check(find_first(arr, 5, 23) == arr + 4, "find_first last element");
    check(find_first(arr, 5, 99) == nullptr, "find_first missing");
    check(find_first(arr, 0, 4) == nullptr, "find_first empty");

    int lo = 0, hi = 0;
    int m[] = {5, -2, 9, 0, 9, -2};
    min_max(m, 6, &lo, &hi);
    check(lo == -2 && hi == 9, "min_max (pointers)");
    int one[] = {7};
    min_max(one, 1, &lo, &hi);
    check(lo == 7 && hi == 7, "min_max single element");

    lo = hi = 0;
    min_max_ref(m, 6, lo, hi);
    check(lo == -2 && hi == 9, "min_max_ref");

    int* f = make_filled(4, 6);
    check(f != nullptr, "make_filled returns memory");
    if (f != nullptr) {
        bool all = true;
        for (int i = 0; i < 4; ++i) {
            if (f[i] != 6) all = false;
        }
        check(all, "make_filled fills every element");
        delete[] f;
    }
}

void test_tier4() {
    Node* head = nullptr;
    check(length(head) == 0, "length of empty list");

    push_front(head, 1);
    push_front(head, 2);
    push_front(head, 3);
    check(list_equals(head, {3, 2, 1}), "push_front builds 3 -> 2 -> 1");
    check(length(head) == 3, "length 3");

    reverse(head);
    check(list_equals(head, {1, 2, 3}), "reverse");
    reverse(head);
    check(list_equals(head, {3, 2, 1}), "reverse twice restores the order");

    std::cout << "list: ";
    print(head);

    free_list(head);
    check(head == nullptr, "free_list leaves head as nullptr");

    Node* empty = nullptr;
    reverse(empty);
    check(empty == nullptr, "reverse empty");
    free_list(empty);
    check(empty == nullptr, "free_list empty");

    Node* single = nullptr;
    push_front(single, 5);
    reverse(single);
    check(list_equals(single, {5}), "reverse single node");
    free_list(single);
}

int main() {
    test_tier1();
    test_tier2();
    std::cout << "\n--- Tier 3: compare with your written predictions ---\n";
    predict_q9();
    predict_q10();
    std::cout << "---\n\n";
    test_tier4();

    std::cout << "\nPassed: " << passed << "  Failed: " << failed << '\n';
    return failed == 0 ? 0 : 1;
}
