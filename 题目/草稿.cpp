#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N], temp[N];
long long count_inversions = 0;

void mergeSort(int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            count_inversions += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (int i = left; i <= right; i++) {
        a[i] = temp[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    mergeSort(1, n);

    cout << count_inversions << endl;
    return 0;
}
