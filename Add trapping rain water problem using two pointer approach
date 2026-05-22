#include<iostream>
using namespace std;

int trapBrute(int arr[], int n) {
    int total = 0;
    for(int i = 1; i < n-1; i++) {
        int leftMax = 0, rightMax = 0;
        for(int j = 0; j <= i; j++) leftMax = max(leftMax, arr[j]);
        for(int j = i; j < n; j++) rightMax = max(rightMax, arr[j]);
        total += min(leftMax, rightMax) - arr[i];
    }
    return total;
}

int trapTwoPointer(int arr[], int n) {
    int left = 0, right = n-1;
    int leftMax = 0, rightMax = 0;
    int total = 0;

    while(left < right) {
        if(arr[left] < arr[right]) {
            if(arr[left] >= leftMax) leftMax = arr[left];
            else total += leftMax - arr[left];
            left++;
        } else {
            if(arr[right] >= rightMax) rightMax = arr[right];
            else total += rightMax - arr[right];
            right--;
        }
    }
    return total;
}

void visualize(int arr[], int n) {
    int maxH = 0;
    for(int i = 0; i < n; i++) maxH = max(maxH, arr[i]);
    cout << "\nVisualization:" << endl;
    for(int h = maxH; h >= 1; h--) {
        for(int i = 0; i < n; i++)
            cout << (arr[i] >= h ? "#" : " ") << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    int arr[n];
    cout << "Enter heights: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    visualize(arr, n);
    cout << "\nWater trapped (brute): " << trapBrute(arr, n) << endl;
    cout << "Water trapped (two pointer): " << trapTwoPointer(arr, n) << endl;

    cout << "\n--- Example ---" << endl;
    int ex[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Heights: 0 1 0 2 1 0 1 3 2 1 2 1" << endl;
    cout << "Water trapped: " << trapTwoPointer(ex, 12) << endl;

    return 0;
}
