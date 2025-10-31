#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Order {
    int orderId;
    long long timestamp;
    string customerName;
};

void merge(vector<Order> &orders, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<Order> left(n1);
    vector<Order> right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = orders[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = orders[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i].timestamp <= right[j].timestamp)
            orders[k++] = left[i++];
        else
            orders[k++] = right[j++];
    }

    while (i < n1)
        orders[k++] = left[i++];
    while (j < n2)
        orders[k++] = right[j++];
}

void mergeSort(vector<Order> &orders, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(orders, start, mid);
        mergeSort(orders, mid + 1, end);
        merge(orders, start, mid, end);
    }
}

void printOrders(const vector<Order> &orders) {
    for (size_t i = 0; i < orders.size(); i++) {
        cout << orders[i].orderId << " "
             << orders[i].timestamp << " "
             << orders[i].customerName << endl;
    }
}

int main() {
    vector<Order> orders;

    Order o1 = {101, 1696500001LL, "Pratik"};
    Order o2 = {102, 1696500003LL, "Om"};
    Order o3 = {103, 1696500002LL, "Rushikesh"};
    Order o4 = {104, 1696500005LL, "Aditya"};
    Order o5 = {105, 1696500004LL, "xyz"};

    orders.push_back(o1);
    orders.push_back(o2);
    orders.push_back(o3);
    orders.push_back(o4);
    orders.push_back(o5);

    cout << "Before Sorting:\n";
    printOrders(orders);

    mergeSort(orders, 0, orders.size() - 1);

    cout << "\nAfter Sorting (by timestamp):\n";
    printOrders(orders);

    return 0;
}

