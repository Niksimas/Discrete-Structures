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

void printAsc(int n) {
    if (n == 0) return;
    printAsc(n - 1);
    cout << n << " ";
}


void printMinusToPlus(int n) {
    if (n <=0) {cout << "0 "; return; }
    cout << "-" << n << " ";
    printMinusToPlus(n-1);
    cout <<  n << " ";
}


void printEven(int n) {
    if (n < 0) return;
    printEven(n - 2);
    if (n % 2 == 0) {
        cout << n << " ";
    }
}


int main(){
    printAsc(10);
    cout << endl;
    printMinusToPlus(10);
    cout << endl;
    printEven(10);
}