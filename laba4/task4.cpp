//
// Created by nikita on 17.10.2024.
//
#include <iostream>
#include <vector>

using namespace std;

// 1. Рекурсивная реализация без оптимизации
int fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}


// 2. Рекурсивная реализация с кеш-памятью
int fibonacci_recursive_memo(int n, std::vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1){
        return memo[n];
    }
    memo[n] = fibonacci_recursive_memo(n - 1, memo) + fibonacci_recursive_memo(n - 2, memo);
    return memo[n];
}


// 3. Итеративная реализация с временным массивом
int fibonacci_iterative_with_array(int n) {
    if (n <= 1) return n;
    std::vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}


// 4. Итеративная реализация с вычислением "на лету"
int fibonacci_iterative_in_place(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;

    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}


int main() {
    int n = 10;

    // Рекурсивная без оптимизации
    std::cout << "Recursive without optimization: " << fibonacci_recursive(n) << std::endl;

    // Рекурсивная с кеш-памятью
    std::vector<int> memo(n + 1, -1);
    std::cout << "Recursive with memoization: " << fibonacci_recursive_memo(n, memo) << std::endl;

    // Итеративная с временным массивом
    std::cout << "Iterative with array: " << fibonacci_iterative_with_array(n) << std::endl;

    // Итеративная "на лету"
    std::cout << "Iterative in-place: " << fibonacci_iterative_in_place(n) << std::endl;

    return 0;
}
