//
// Created by nikita on 05.09.2024.
//

// using encoding IBM866

#include <iostream>
using namespace std;

const int max_size = 100;

class Stack{
private:

    int n = 0;
    int mass[max_size];

public:
    Stack(){}

    bool isEmpty(){return (n==0);}

    void print() {
        if (n==0) {cout << "List is empty!\n";}
        for (int i=0; i<n; i++) {
            cout << mass[i] << " ";
        }
        cout << endl;
    }

    void push(int new_elem){
        if (n == max_size){
            cout << "Stack is overflow!\n";
        }else{
            mass[n] = new_elem;
            n++;
        }
    }

    void pop(){
        if (!isEmpty()){
            n--;
        }
    }

    int last(){
        int item = mass[n-1];
        pop();
        return item;
    }

};


int main(){
    Stack a;
    a.push(1);
    a.push(13);
    a.push(51);
    a.push(46);
    a.push(29);
    a.push(27);
    a.print();
    cout << a.last() << endl;
    a.print();
}