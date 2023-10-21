#include <iostream>
void heapify(int arr[], int size, int rootIndex) {
    int largest = rootIndex; // Assume the root as the largest element
    int leftChild = 2 * rootIndex + 1; // Left child index
    int rightChild = 2 * rootIndex + 2; // Right child index

    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

     if (largest != rootIndex) {
        std::swap(arr[rootIndex], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}


void heapSort(int arr[], int size) {
    // Build a max-heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

   
    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); // Move current root to the end

        heapify(arr, i, 0); // Reduce the heap size and heapify the root
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, size);

    heapSort(arr, size);

    std::cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
