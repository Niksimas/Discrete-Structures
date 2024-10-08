//
// Created by nikita on 05.09.2024.
//

// using encoding IBM866


#include <iostream>
using namespace std;

const int max_size = 100;

class List{
private:

    int n = 0;
    int mass[max_size];
public:

    List(){}

    int indexOf(int item){
        if (isEmpty()){
            return -1;
        }else{
            for (int i =0; i<n; i++){
                if (mass[i] == item){
                    return i;
                }
            }
            return -1;
        }
    }

    bool isEmpty(){return (n==0);}

    void print() {
        if (isEmpty()) {cout << "List is empty!\n";}
        for (int i=0; i<n; i++) {
            cout << mass[i] << " ";
        }
        cout << endl;
    }

    void insert(int elem, int pos){
        if (pos >= max_size || pos < 0){ cout << "List index out of range!\n";}
        else if (n==max_size){ cout << "List is overload!\n";}
        else{
            if (pos >= n){ insert(elem); }
            else{
                for (int i = n - 1; i > pos - 1; i--){
                    mass[i+1] = mass[i];
                }
                mass[pos] = elem;
                n++;
            }
        }
    }

    void insert(int elem){
        insert(elem, n);
    }

    void remove(int pos){
        if (pos >= max_size || pos < 0){ cout << "List index out of range!\n";}
        else if (isEmpty()){ cout << "List is empty!\n";}
        else{
            for (int i = pos; i < n; i++ ){
                mass[i] = mass[i+1];
            }
            n--;
        }
    }
};


int main(){
    List a;

    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.print();
    cout << a.indexOf(3) << endl;
    a.remove(2);
    a.print();
    a.insert(5, 0);
    a.insert(6, 0);
    a.insert(7, 0);
    a.print();

}