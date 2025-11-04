/*Pratik Chandane/* 

#include <bits/stdc++.h>
using namespace std;

struct Order {
    int order_id;
    long long timestamp;
    double value;
};

// Merge function
void merge(vector<Order>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Order> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].timestamp <= R[j].timestamp)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(vector<Order>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Helper: Generate random orders
vector<Order> generateOrders(int n) {
    vector<Order> orders(n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        orders[i].order_id = i + 1;
        orders[i].timestamp = rand() % 1000000000 + 1;
        orders[i].value = (double)(rand() % 100000) / 100.0;
    }
    return orders;
}

// Print orders (for small examples)
void printOrders(const vector<Order>& orders, int limit = 10) {
    for (int i = 0; i < min(limit, (int)orders.size()); i++) {
        cout << "Order " << orders[i].order_id 
             << " | Timestamp: " << orders[i].timestamp 
             << " | Value: " << orders[i].value << "\n";
    }
}

int main() {
    int n = 20; // number of orders (can increase up to 1 million)
    vector<Order> orders = generateOrders(n);

    cout << "Orders before sorting:\n";
    printOrders(orders);

    mergeSort(orders, 0, n - 1);

    cout << "\nOrders after sorting by timestamp:\n";
    printOrders(orders);

    return 0;
}

/*output

Orders before sorting:
Order 1 | Timestamp: 27308 | Value: 120.96
Order 2 | Timestamp: 10506 | Value: 146.64
Order 3 | Timestamp: 21293 | Value: 69.85
Order 4 | Timestamp: 24706 | Value: 233.89
Order 5 | Timestamp: 25010 | Value: 99.03
Order 6 | Timestamp: 22968 | Value: 237.5
Order 7 | Timestamp: 22676 | Value: 25.44
Order 8 | Timestamp: 11388 | Value: 292.19
Order 9 | Timestamp: 26050 | Value: 61
Order 10 | Timestamp: 2762 | Value: 180.62

Orders after sorting by timestamp:
Order 11 | Timestamp: 1216 | Value: 100.74
Order 18 | Timestamp: 1600 | Value: 262.44
Order 10 | Timestamp: 2762 | Value: 180.62
Order 14 | Timestamp: 3316 | Value: 2.57
Order 19 | Timestamp: 7895 | Value: 225.77
Order 2 | Timestamp: 10506 | Value: 146.64
Order 8 | Timestamp: 11388 | Value: 292.19
Order 17 | Timestamp: 14597 | Value: 115.69
Order 13 | Timestamp: 16880 | Value: 230.26
Order 15 | Timestamp: 17169 | Value: 45.88/*




