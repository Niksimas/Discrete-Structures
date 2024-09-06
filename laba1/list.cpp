//
// Created by nikita on 05.09.2024.
//
//���᮪ ���� ����� �� ⮫쪮 � ��ࢮ��/��᫥����� ������ (��� �⥪ � ��।�), �� � �������� �������� � �� ����樨 �� �������.
//
//����. - List.
//����樨:
//insert(i, x) ? ��⠢��� ����� � 㪠������ ����
//remove(i) ? 㤠���� ����� � ������� �����ᮬ
//indexOf(x) ? ������ ��ࢮ�� �宦����� ����� (-laba1, �᫨ �� ������);
//isEmpty() ? �஢�ઠ �� ������ (true ? ���⮩; false ? ��� �� laba1 �����)

#include <iostream>
using namespace std;

class List{
private:
    int n = 0;
    int mass[100];
public:

    List(){}

    void insert(int elem, int pos){
        if (pos >= 100 || pos < 0){ cout << "������ ��室�� �� �।��� ᯨ᪠!\n";}
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
        //�஢�ઠ �� ������
        if (n==0) {cout << "���� ����!\n";}
        for (int i=0; i<n; i++) {
            cout << mass[i] << " ";
        }
        cout << endl;
    }


};