//
// Created by nikita on 05.09.2024.
//
//Список дает доступ не только к первому/последнему элементу (как стек и очередь), но и позволяет обращаться к любой позиции по индексу.
//
//Англ. - List.
//Операции:
//insert(i, x) ? вставить элемент в указанное место
//remove(i) ? удалить элемент с заданным индексом
//indexOf(x) ? индекс первого вхождения элемента (-laba1, если не найден);
//isEmpty() ? проверка на пустоту (true ? пустой; false ? хотя бы laba1 элемент)

#include <iostream>
using namespace std;

class List{
private:
    int n = 0;
    int mass[100];
public:

    List(){}

    void insert(int elem, int pos){
        if (pos >= 100 || pos < 0){ cout << "Индекс выходит за пределы списка!\n";}
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
        //Проверка на пустоту
        if (n==0) {cout << "Лист пуст!\n";}
        for (int i=0; i<n; i++) {
            cout << mass[i] << " ";
        }
        cout << endl;
    }


};