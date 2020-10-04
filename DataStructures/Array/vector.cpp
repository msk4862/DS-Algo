#include<iostream>
using namespace std;

class vector {
    int *arr;
    int size;
    int capacity;
    static const int DEFAULT_CAPACITY = 10;

    public:
    vector(int capacity = DEFAULT_CAPACITY) {
        arr = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    bool is_out_of_bounds(int index) {
        if(index < 0 || index >= size) return 1;
        return 0;
    }

    int get(int index) {
        if(is_out_of_bounds) cout<<"Index out of bounds!";
        return arr[index];
    }

    void set(int index, int val) {
        if(is_out_of_bounds) cout<<"Index out of bounds!";
        arr[index] = val;
    }

    void push_back(int val) {
        if(size == capacity) {
            int* temp = new int[size + DEFAULT_CAPACITY];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            temp[size++] = val;
            arr = temp;
            delete temp;
        }

        arr[size++] = val;
    }

    void erase(int index) {
        if(is_out_of_bounds) cout<<"Index out of bounds!";

        for (int i = index; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
    }   

    int size() {
        return size;
    } 

    void print() {
        for (int i = 0; i < size; i++) {
            cout<<this->arr[i]<<" ";
        }
    }
};


int main() {
    vector v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    
    v.print();
}