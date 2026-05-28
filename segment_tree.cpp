#include<iostream>
using namespace std;

class SegmentTree {
    int* tree;
    int* minTree;
    int n;

    void buildSum(int arr[], int node, int start, int end) {
        if(start == end) { tree[node] = arr[start]; return; }
        int mid = (start + end) / 2;
        buildSum(arr, 2*node, start, mid);
        buildSum(arr, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void buildMin(int arr[], int node, int start, int end) {
        if(start == end) { minTree[node] = arr[start]; return; }
        int mid = (start + end) / 2;
        buildMin(arr, 2*node, start, mid);
        buildMin(arr, 2*node+1, mid+1, end);
        minTree[node] = min(minTree[2*node], minTree[2*node+1]);
    }

    int querySum(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 0;
        if(l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return querySum(2*node, start, mid, l, r) +
               querySum(2*node+1, mid+1, end, l, r);
    }

    int queryMin(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return INT_MAX;
        if(l <= start && end <= r) return minTree[node];
        int mid = (start + end) / 2;
        return min(queryMin(2*node, start, mid, l, r),
                   queryMin(2*node+1, mid+1, end, l, r));
    }

    void update(int node, int start, int end, int idx, int val) {
        if(start == end) { tree[node] = minTree[node] = val; return; }
        int mid = (start + end) / 2;
        if(idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
        minTree[node] = min(minTree[2*node], minTree[2*node+1]);
    }

public:
    SegmentTree(int arr[], int size) {
        n = size;
        tree = new int[4*n];
        minTree = new int[4*n];
        buildSum(arr, 1, 0, n-1);
        buildMin(arr, 1, 0, n-1);
    }

    int rangeSum(int l, int r) { return querySum(1, 0, n-1, l, r); }
    int rangeMin(int l, int r) { return queryMin(1, 0, n-1, l, r); }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree st(arr, n);

    int l, r;
    cout << "Enter range (l r) for sum query: ";
    cin >> l >> r;
    cout << "Sum [" << l << "," << r << "]: " << st.rangeSum(l, r) << endl;
    cout << "Min [" << l << "," << r << "]: " << st.rangeMin(l, r) << endl;

    cout << "\n--- Example ---" << endl;
    int ex[] = {1, 3, 5, 7, 9, 11};
    SegmentTree st2(ex, 6);
    cout << "Array: 1 3 5 7 9 11" << endl;
    cout << "Sum [1,3]: " << st2.rangeSum(1, 3) << endl;
    cout << "Min [0,4]: " << st2.rangeMin(0, 4) << endl;
    st2.update(1, 10);
    cout << "After update index 1 to 10:" << endl;
    cout << "Sum [1,3]: " << st2.rangeSum(1, 3) << endl;

    return 0;
}