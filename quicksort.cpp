#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int partition(vector<int>& array, int low, int high) {
    int pivot = array[high]; // choose last element as pivot
    int i = low - 1; //index for smaller element

    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            ++i; // increment smaller element index
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]); //move the pivot element to correct position
    return i + 1;
}

void quickSort(vector<int>& array, int low, int high) {
    stack<pair<int, int>> stack; //stack to store ranges of subarrays

    // push initial range tostack
    stack.push({low, high});

    // continue until stack is empty
    while (!stack.empty()) {
        // get current range from stack
        pair<int, int> range = stack.top();
        stack.pop();

        int firstObject = range.first;
        int secondObject = range.second;

        if (firstObject < secondObject) {
            //partition the array and get the pivot index
            int pivotIndex = partition(array, firstObject, secondObject);

            //push left and right subarray ranges to stack
            stack.push({firstObject, pivotIndex - 1}); // left subarray
            stack.push({pivotIndex + 1, secondObject}); // right subarray
        }
    }
}

//function to print the array
void printarray(const vector<int>& array) {
    for (int value : array) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    
    //create an array of size n
    vector<int> array(n);

    //input elements of the array from user
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    cout << "original: ";
    printarray(array);

    quickSort(array, 0, array.size() - 1);

    cout << "sorted: ";
    printarray(array);

    return 0;
}
