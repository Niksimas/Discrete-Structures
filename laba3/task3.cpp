//
// Created by nikita on 15.10.2024.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <cstdlib>

using namespace std;

// 1. Формирование массива общих делителей M и N с последующим поиском максимума
int gcd_common_divisors(int N, int M) {
    vector<int> divisors;
    for (int i = 1; i <= std::min(N, M); ++i) {
        if (N % i == 0 && M % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors.empty() ? 1 : *max_element(divisors.begin(), divisors.end());
}

// 2. Перебор от 1 до min(M, N)
int gcd_from_1_to_min(int N, int M) {
    int gcd = 1;
    for (int i = 1; i <= std::min(N, M); ++i) {
        if (N % i == 0 && M % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

// 3. Перебор от min(M, N) до 1
int gcd_from_min_to_1(int N, int M) {
    for (int i = std::min(N, M); i > 0; --i) {
        if (N % i == 0 && M % i == 0) {
            return i;
        }
    }
    return 1; // Этот случай невозможен, но для полной корректности
}

// 4. Алгоритм Евклида
int gcd_euclid(int N, int M) {
    while (M != 0) {
        int temp = M;
        M = N % M;
        N = temp;
    }
    return N;
}

int main() {
    vector <int> N;
    vector <int> M;
    vector <vector<long double>> res ;
    vector <long double> res1;
    int sizes = 100;

    int as=0;
    for (int MAX = 10000, MIN = 2, i=0; i < sizes; i++, MAX+=10000, MIN+=10000) {
        as = MIN + rand() % (MAX+1 -MIN);
        N.emplace_back(as);
        as = MIN + rand() % (MAX+1 -MIN);
        M.emplace_back(as);
        res.emplace_back(res1);
    }

    cout << setiosflags(ios::left);


    for (int item =0; item < sizes; item++){
        auto start = std::chrono::high_resolution_clock::now();

        gcd_common_divisors(N[item], M[item]);

        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        res[item].emplace_back(elapsed.count());
    }

    for (int item =0; item < sizes; item++){
        auto start = std::chrono::high_resolution_clock::now();

        gcd_from_1_to_min(N[item], M[item]);

        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        res[item].emplace_back(elapsed.count());
    }


    for (int item =0; item < sizes; item++){
        auto start = std::chrono::high_resolution_clock::now();

        gcd_from_min_to_1(N[item], M[item]);

        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        res[item].emplace_back(elapsed.count());
    }

    for (int item =0; item < sizes; item++){
        auto start = std::chrono::high_resolution_clock::now();

        gcd_euclid(N[item], M[item]);

        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        res[item].emplace_back(elapsed.count());
    }

    int tab = 15;

    cout << "a. Формирование массива общих делителей M и N с последующим поиском максимума в нем.\n"
            "b. Перебор от 1 до min(M, N)\n"
            "c. Перебор от min(M, N) до 1\n"
            "d. Алгоритм Евклида\n\n";

    cout << setw(10) << "№" << setw(10) << "N" << setw(10) << "M" << setw(tab) << "a" << setw(tab) <<"b" << setw(tab) <<"c" << setw(tab) <<"d"<<endl;

    for (int row_n=0; row_n < res.size(); row_n++ ){
        cout << setw(10) <<row_n+1;
        cout << setw(10) << N[row_n];
        cout << setw(10) << M[row_n];
        for (int i=0; i < res[row_n].size(); i++){
            cout << setw(tab) << setprecision(9) << fixed << res[row_n][i] ;
        }
        cout << endl;
    }

    return 0;
}
