#include<iostream>
using namespace std;

class vector {
    private:
        
        int *arr;
        int arr_size;
        int arr_capacity;
        static const int DEFAULT_CAPACITY = 16;

        void resize(int new_capacity) {
            arr_capacity = new_capacity;
            int* temp = new int[arr_capacity];
            for (int i = 0; i < arr_size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }

        bool is_shrinkable() {
            return arr_size <= arr_capacity/4;
        }

        bool is_out_of_bounds(int index) {
            if(index < 0 || index >= arr_size) return 1;
            return 0;
        }

    public:

        vector(int capacity = DEFAULT_CAPACITY) {
            // capacity in power of 2's
            if(capacity > DEFAULT_CAPACITY) {
                int t = 32;
                while(t < capacity) 
                    t<<=1;
                capacity = t;
            }
            arr = new int[capacity];
            arr_size = 0;
            arr_capacity = capacity;
        }

        int get(int index) {
            if(is_out_of_bounds(index)) cout<<"Index out of bounds!";
            return arr[index];
        }

        void set(int index, int val) {
            if(is_out_of_bounds(index)) cout<<"Index out of bounds!";
            arr[index] = val;
        }

        void insert(int index, int val) {

            if(is_out_of_bounds(index) || (index!=0 && arr_size+1 == arr_capacity)) cout<<"Index out of bounds!";

            // expanding array capacity
            // only for push_front
            if(arr_size+1 == arr_capacity) {
                resize(2*arr_size);
            }

            for (int i = arr_size; i > index; i--) {
                arr[i] = arr[i-1];
            }
            arr[index] = val;
            arr_size++;
        }

        void push_back(int val) {
            // expanding array capacity
            if(arr_size == arr_capacity) {
                resize(2*arr_size);
            }

            arr[arr_size++] = val;
        }

        void push_front(int val) {
            insert(0, val);
        }

        void erase(int index) {
            if(is_out_of_bounds(index)) cout<<"Index out of bounds!";

            for (int i = index; i < arr_size-1; i++) {
                arr[i] = arr[i+1];
            }
            arr_size--;

            //shrink array if its become too small
            if(is_shrinkable()) 
                resize(arr_capacity/2);
        }   

        int pop() {
            arr_size--;

            if(is_shrinkable())
                resize(arr_capacity/2);

            return arr[arr_size];
        }

        void remove(int val) {
            int *temp = new int[arr_size];
            int new_size = 0;
            for (int i = 0; i < arr_size; i++)
                if(arr[i] != val) 
                    temp[new_size++] = arr[i];

            delete[] arr;
            arr = temp;
            arr_size = new_size;

            if(is_shrinkable())
                resize(arr_capacity/2);
        }

        int find(int val) {
            for (int i = 0; i < arr_size; i++)
                if(arr[i] == val) 
                    return i;
            return -1;
        }
        

        int size() {
            return arr_size;
        } 

        int capacity() {
            return arr_capacity;
        }

        bool is_empty() {
            return arr_size == 0;
        }

        void print() {
            for (int i = 0; i < arr_size; i++) {
                cout<<arr[i]<<" ";
            }
        }
};


int main() {
    vector v;
    cout<<v.is_empty()<<" "<<v.capacity()<<endl;
    v.push_back(1);
    v.push_back(7);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.size();
    cout<<v.is_empty()<<" "<<v.size()<<endl;

    v.remove(2);
    v.push_front(2);
    v.insert(2, 10);
    v.erase(1);

    v.print();
}