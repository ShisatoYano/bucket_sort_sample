#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// function to sort input array of size n by bucket sort
void bucket_sort(float array[], int n)
{
    // create n empty buckets
    vector<float> buckets[n];

    // put each elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucket_idx = n * array[i];
        buckets[bucket_idx].push_back(array[i]);
    }

    // sort each buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // concatenate all buckets into array
    int array_idx = 0;
    for (int i = 0; i < n; i++) {
        for (float element : buckets[i]) {
            array[array_idx++] = element;
        }
    }
}

int main() {
    float array[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(array) / sizeof(array[0]);
    cout << "Input array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    bucket_sort(array, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    return 0;
}
