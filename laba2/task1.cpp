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

    void search(int elem){
        int k = 0;
        for (int i: array) {
            k++;
            if (i == elem){
                cout << "YES -- steps:" << k << endl;
                return;
            }
        }
        cout << "NO";
    }

    int get(int pos){
        return array[pos];
    }
};

int main() {

    R_mass a(100);
//    a.print();
    a.search(a.get(70));


}