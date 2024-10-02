//
// Created by nikita on 19.09.2024.
//
//
// Created by nikita on 19.09.2024.
//


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


struct R_mass{
    vector <int> array;
    int size;

    R_mass(const int length) {
        srand(static_cast<unsigned int>(std::time(0)));
        size = length;

        int as = rand() % 100;
        for (int i = 0; i < length; ++i) {
            as += (rand() % 10);
            array.emplace_back(as);
        }
    }

    void print (){
        for (int i: array) {
            std::cout << i << " ";
        }
        cout << endl;
    }

    int binarySearch(int elem) {
        int k = 0;
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (array[mid] == elem) {
                k++;
                cout << "Steps: " << k << endl;
                return mid;
            }

            if (array[mid] > elem) {
                k++;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        cout << "Steps: " << k << endl;
        return -1;
    }

    int get(int pos){
        return array[pos];
    }
};

int main() {

    R_mass a(100);
    a.print();
    int d = a.binarySearch(a.get(26));

    cout << "Pos_elem: " << d;



}