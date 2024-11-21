#include <iostream>
#include <vector>
#include <algorithm> // For std::swap
using namespace std;

struct Shoe {
    string brand;
    int price;

    Shoe(string b, int p) : brand(b), price(p) {}
};

void heapify(vector<Shoe>& heap, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && heap[left].price > heap[largest].price)
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && heap[right].price > heap[largest].price)
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

// Function for Max-Heap
void buildMaxHeap(vector<Shoe>& heap) {
    int n = heap.size();

    // Builds heap from the bottom up
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

// Function to sort and display the heap
void heapSort(vector<Shoe>& heap) {
    int n = heap.size();

    // Build the Max-Heap
    buildMaxHeap(heap);

    // One by one extraction of elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to the end
        swap(heap[0], heap[i]);

        // Call heapify on the reduced heap
        heapify(heap, i, 0);
    }
}

int main() {
    vector<Shoe> shoes;

    cout << "Enter details for 5 shoes (Brand and Price):" << endl;

    for (int i = 0; i < 5; i++) {
        string brand;
        int price;

        cout << "Shoe " << i + 1 << " Brand: ";
        cin.ignore(); 
        getline(cin, brand);

        cout << "Shoe " << i + 1 << " Price: ";
        cin >> price;

        shoes.push_back(Shoe(brand, price));
    }

    // Sort the shoes using Heap Sort
    heapSort(shoes);

    // Display the sorted shoes (most expensive to cheapest)
    cout << "\nShoes from most expensive to cheapest:\n";
    for (int i = shoes.size() - 1; i >= 0; i--) {
        cout << "Brand: " << shoes[i].brand << ", Price: $" << shoes[i].price << endl;
    }

    return 0;
}
