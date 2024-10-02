//
// Created by nikita on 19.09.2024.
//


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


struct R_mass{
    vector <int> array_lin;
    vector <int> array_bin;
    int size;

    R_mass(const int length) {
        srand(static_cast<unsigned int>(std::time(0)));
        size = length;
        int as = rand() % 100;
        for (int i = 0; i < length; ++i) {
            as += (rand() % 10);
            array_bin.emplace_back(as);
            array_lin.emplace_back(as);
        }
    }

    ~R_mass(){
        for (int i = 0; i < size; ++i) {
            array_bin.pop_back();
            array_lin.pop_back();
        }
    }

    void print_bin (){
        for (int i: array_bin) {
            std::cout << i << " ";
        }
        cout << endl;
    }

    void print_lin (){
        for (int i: array_lin) {
            std::cout << i << " ";
        }
        cout << endl;
    }

    int search_lin(int elem){
        int k = 0;
        for (int i: array_lin) {
            k++;
            if (i == elem){
//                cout << "YES -- steps:" << k << endl;
                return k;
            }
        }
//        cout << "NO";
        return -1;
    }

    int get_bin(int pos){
        return array_bin[pos];
    }


    int get_lin(int pos){
        return array_bin[pos];
    }


    int binarySearch(int elem) {
        int k = 0;
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (array_bin[mid] == elem) {
                k++;
                return k;
            }

            if (array_bin[mid] > elem) {
                k++;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
//        cout << "Steps: " << k << endl;
        return k;
    }

};

int main() {

    cout << "N\t"<< "Pos\t" << "  Step_bin\t" << "Step_lin" << endl;
    for (int i = 100; i < 100001; i += 100 ){
        int pos = rand() % (i -10);
        R_mass a(i);
//        a.print_bin();
        int b = a.binarySearch(a.get_bin(pos));
        int l = a.search_lin(a.get_bin(pos));
//        cout << i << "\t" << a.get_bin(pos) << "-" << pos << "\t   " <<b << "\t" << l << endl;
        cout << i << "\t   " << pos << "\t   " <<b << "\t" << l << endl;
    }
//    a.print();
//    a.search(a.get(70));


}