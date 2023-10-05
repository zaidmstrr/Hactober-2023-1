#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // target found.
        if (arr[mid] == target)
            return mid;
        // If target is smaller, ignore right half
        if (arr[mid] > target)
            high = mid - 1;
        // If target is greater, ignore left half
        else
            low = mid + 1;
    }
    // element is not present
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 1;
    int idx = binarySearch(arr, target);

    if (idx == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index: " << result;
    return 0;
}
