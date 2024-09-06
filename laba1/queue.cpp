//
// Created by nikita on 05.09.2024.
//

#include <iostream>

using namespace std;


class Queue {
private:
    // int mass[100];
    // int *mass;
    // = int[100]
    int n = 0;
    int mass[100];

public:

    Queue(){}


    void enqueue(int add_elem){
        if (n != 100){
            mass[n] = add_elem;
            n++;
        } else{
            cout << "Queue is overflowing!";
        }
    }


    void dequeue(){
        if (n == 0) {
            cout << "Queue is empty\n";
        } else {
            for (int i = 0; i < n - 1; i++) {
                mass[i] = mass[i + 1];
            }
            n--;
        }
    }


    int first(){return mass[0];}


    bool isEmpty(){return (n == 0);}


    void print(){
        for (int i = 0; i < n; i++){
            cout << mass[i] <<" ";
        }
        cout << endl;
    }

};


int main(){
    Queue a;
    if (a.isEmpty()) cout << "empty" << endl;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    if (a.isEmpty()) cout << "empty" << endl;
    cout << a.first() << endl;
    a.print();
    a.dequeue();
    a.dequeue();
    a.print();
}