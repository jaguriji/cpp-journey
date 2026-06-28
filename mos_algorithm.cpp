#include<iostream>
#include<cmath>
using namespace std;

struct Query {
    int l, r, idx;
};

int freq[100001];
int currAns = 0;

void add(int arr[], int pos) {
    freq[arr[pos]]++;
    if(freq[arr[pos]] == 1) currAns++;
}

void remove(int arr[], int pos) {
    freq[arr[pos]]--;
    if(freq[arr[pos]] == 0) currAns--;
}

void sortQueries(Query queries[], int q, int block) {
    for(int i = 0; i < q-1; i++)
        for(int j = 0; j < q-i-1; j++) {
            int b1 = queries[j].l / block;
            int b2 = queries[j+1].l / block;
            if(b1 > b2 || (b1 == b2 && queries[j].r > queries[j+1].r))
                swap(queries[j], queries[j+1]);
        }
}

void mosAlgorithm(int arr[], int n, Query queries[], int q) {
    int block = (int)sqrt(n);
    sortQueries(queries, q, block);

    int answers[q];
    int currL = 0, currR = -1;
    currAns = 0;

    for(int i = 0; i < q; i++) {
        int l = queries[i].l, r = queries[i].r;
        while(currR < r) add(arr, ++currR);
        while(currL > l) add(arr, --currL);
        while(currR > r) remove(arr, currR--);
        while(currL < l) remove(arr, currL++);
        answers[queries[i].idx] = currAns;
    }

    cout << "Distinct elements in each range:" << endl;
    for(int i = 0; i < q; i++)
        cout << "Query " << i+1 << ": " << answers[i] << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    Query queries[q];
    for(int i = 0; i < q; i++) {
        cout << "Enter range " << i+1 << " (l r): ";
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    mosAlgorithm(arr, n, queries, q);

    cout << "\n--- Example ---" << endl;
    int ex[] = {1, 2, 1, 3, 4, 2, 4};
    Query exQ[] = {{0,4,0},{1,3,1},{2,6,2},{3,5,3}};
    cout << "Array: 1 2 1 3 4 2 4" << endl;
    mosAlgorithm(ex, 7, exQ, 4);

    return 0;
}