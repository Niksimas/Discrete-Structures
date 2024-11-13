//
// Created by nikita on 17.10.2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <malloc.h>

using namespace std;


// 1. Рекурсивная реализация без оптимизации
int fibonacci_recursive(int n) {
//    cout << n << endl;
    if (n < 2) return 1;
    if (n == 2) return 1;
    int a = fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    return a;
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


long getMemoryUsage() {
    std::ifstream file("/proc/self/status");
    std::string line;

    while (std::getline(file, line)) {
        if (line.rfind("VmRSS:", 0) == 0) {
            cout << line << endl;
            size_t end = line.find('\t');
            string a = line.substr(end, 10);
            return std::stol(a);
        }
    }
    return 0;
}

#include <sys/resource.h>
#include <unistd.h>
void printMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Memory usage: " << usage.ru_maxrss << " KB\n";  // Максимальное использование памяти
}


int main() {
    int n = 46;

    auto start = std::chrono::high_resolution_clock::now();
    printMemoryUsage();
    int result = fibonacci_recursive(n);
    printMemoryUsage();
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    // Выводим результат и использованную память
    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
    std::cout << "Time = " << elapsed.count() << std::endl<< std::endl;



//    start = std::chrono::high_resolution_clock::now();
////    printMemoryUsage();
//    vector<int> memo(n + 1, -1);
////    result = fibonacci_recursive_memo(n, memo);
//    printMemoryUsage();
//    end = std::chrono::high_resolution_clock::now();
//    elapsed = end - start;
//
//    // Выводим результат и использованную память
//    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
//    std::cout << "Time = " << elapsed.count() << std::endl<< std::endl;
//
//
//
//    start = std::chrono::high_resolution_clock::now();
//    result = fibonacci_iterative_with_array(n);
//    end = std::chrono::high_resolution_clock::now();
//    elapsed = end - start;
//
//    // Выводим результат и использованную память
//    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
//    std::cout << "Time = " << elapsed.count() << std::endl<< std::endl;
//
//
//
//    start = std::chrono::high_resolution_clock::now();
//    result = fibonacci_iterative_in_place(n);
//    end = std::chrono::high_resolution_clock::now();
//    elapsed = end - start;
//
//    // Выводим результат и использованную память
//    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
//    std::cout << "Time = " << elapsed.count() << std::endl<< std::endl;



    return 0;
}