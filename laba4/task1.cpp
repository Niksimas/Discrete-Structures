//
// Created by nikita on 17.10.2024.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <cstdlib>

using namespace std;

int fact(int n){
    if (n <= 1){ return 1; }
    return n * fact(n-1);
}


int double_fact(int n){
    if (n <= 3){ return n; }
    return n * double_fact(n-2);
}


int sum_to_n(int n){
    if (n <= 1){ return n;}
    return sum_to_n(n-1) + n;
}


int main(){
    for (int i=1; i < 11; i++){
        cout << i << " -- " << double_fact(i) << endl;
    }
}