//
// Created by nikita on 17.10.2024.
//
#include <iostream>
#include <vector>
using namespace std;


// �㭪�� ��� ࠧ������� ���ᨢ� (partition)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// �����ᨢ��� �㭪�� ��� ���஢�� �����
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5}; // ����� ����� ���筮�� ���ᨢ�
    int n = arr.size();

    cout << "��室�� �����: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1); // �맮� �㭪樨 ���஢��

    cout << "�����஢���� �����: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
