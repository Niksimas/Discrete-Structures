//
// Created by nikita on 05.09.2024.
//

// using encoding IBM866


#include <iostream>
using namespace std;

class List{
private:
    int n = 0;
    int mass[100];
public:

    List(){}

    void insert(int elem, int pos){
        if (pos >= 100 || pos < 0){ cout << "List index out of range!\n";}
        else{
            for (int i = n - 1; i > pos; i++){
                mass[i] = mass[i-1];
            }
        }
    }

    void remove(){}

    int indexOf(int item){
        if (n==0){
            return -1;
        }else{
            for (int i =0; i<n; i++){
                if (mass[i] == item){
                    return i;
                }
            }
        }
    }

    bool isEmpty(){return (n==0);}

    void print() {
        if (n==0) {cout << "List is empty!\n";}
        for (int i=0; i<n; i++) {
            cout << mass[i] << " ";
        }
        cout << endl;
    }


};