//
// Created by nikita on 15.10.2024.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;


int main() {
    int numbers[5] {1009, 10007, 100003, 1000003, 10000019};
    vector <vector<long double>> res ;
    vector <long double> res1;
    res.emplace_back(res1);
    res.emplace_back(res1);
    res.emplace_back(res1);
    res.emplace_back(res1);
    res.emplace_back(res1);
    cout << setiosflags(ios::left);


    for (int item =0; item < 5; item++){
        auto start = std::chrono::high_resolution_clock::now();
        for (int i=2; i < numbers[item]-1; i++){
            if (numbers[item] % i == 0){ break;}
        }
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        res[item].emplace_back(elapsed.count());
    }


    for (int item =0; item < 5; item++){
        auto start = std::chrono::high_resolution_clock::now();
        for (int i=2; i < numbers[item]-1; i++){
            if ( i%2==0 && numbers[item] % i == 0){ break;}
        }
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        res[item].emplace_back(elapsed.count());
    }


    for (int item =0; item < 5; item++){
        auto start = std::chrono::high_resolution_clock::now();
        int N_end = sqrt(numbers[item]) + 1;

        for (int i=2; i < N_end; i++){
            if (numbers[item] % i == 0){ break;}
        }
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        res[item].emplace_back(elapsed.count());
    }


    for (int item =0; item < 5; item++){
        auto start = std::chrono::high_resolution_clock::now();
        int N_end = sqrt(numbers[item]) + 1;
        for (int i=2; i < N_end; i++){
            if ( i%2==0 && numbers[item] % i == 0){ break;}
        }
        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        res[item].emplace_back(elapsed.count());
    }



    cout << setw(10) << "" << setw(30) << "Перебор от 2 до N" << setw(30) << "Перебор от 2 до sqrt(N)" << endl;
    cout << setw(10) << "N" << setw(15) << "все" << setw(15) <<"нечетные" << setw(15) <<"все" << setw(15) <<"нечетные"<<endl;

    for (int row_n=0; row_n < res.size(); row_n++ ){
        cout << setw(10) << numbers[row_n];
        for (int i=0; i < res[row_n].size(); i++){
            cout << setw(15) << setprecision(9) << fixed << res[row_n][i] ;
        }
        cout << endl;
    }

    return 0;
}
