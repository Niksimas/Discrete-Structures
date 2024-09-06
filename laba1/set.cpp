//
// Created by nikita on 05.09.2024.
//

//using file encoding: IBM866

#include <iostream>
using namespace std;


class Set{

private:
    int n = 0;
    int mass[100];

public:

    Set(){}

    void add(int new_elem){
        if (n == 100){
            cout << "Set is overload!\n";
        }else {
            if (this->contains(new_elem) == -1) {
                mass[n] = new_elem;
                n++;
            }
        }
    }

    void delete_elem(int elem){
        int pos = this->contains(elem);
        if (pos != -1){
            for (int i = pos; i < n; i++){
                mass[i] = mass[i+1];
            }
            n--;
        }
    }

    int contains(int elem){
        if (n != 0) {
            for (int item = 0; item < n; item++) {
                if (mass[item] == elem) { return item; }
            }
        }
        return -1;
    }

    bool isEmpty(){return (n==0);}

    void print() {
        if (n==0) {cout << "Set is empty!\n";}
        for (int i=0; i<n; i++) {
            cout << mass[i] << " ";
        }
        cout << endl;
    }
};

int main (){
    Set a;
    a.add(1);
    a.add(25);
    a.add(36);
    a.add(78);
    a.add(9);
    a.print();
    a.delete_elem(36);
    a.print();
    a.add(2);
    a.add(29);
    a.add(86);
    a.add(78);
    a.add(11);
    a.print();
    a.delete_elem(9);
    a.print();
};