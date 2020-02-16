#include <iostream>
#include<fstream>
#include<map>
#define ll long long
using namespace std;
void swap(int* a, int x, int y) {
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
}
int quickSort(int* a, int start, int end) {
    if (start >= end)
        return 0;
    int pivot = a[end];
    int t = start-1;
    for (int i = start; i < end; i++) {
        if (a[i] >= pivot) {
            swap(a, t + 1, i);
            t++;
        }
    }
    swap(a, t + 1, end);
    quickSort(a, start, t);
    quickSort(a, t + 1, end);
}
int main()
{
    ifstream input; ofstream output;
    string inputfilename, outputfilename;
    cout << "Enter Input File Name:"; cin >> inputfilename;cout << endl;
    cout << "Enter Output File Name:"; cin >> outputfilename;cout << endl;
    input.open(inputfilename); output.open(outputfilename);
    int x,n;
    input >> x>>n;
    int* p = (int*)malloc(sizeof(int) * n);
    map<int, int> m;
    ll maxSlice = 0;
    for (int i = 0; i < n; i++) {
        input >> p[i];
        m[p[i]] = i;
        maxSlice += p[i];
    }
    if (maxSlice < x) {
        output << n << endl;
        for (int i = 0; i < n; i++) {
            output << i<<" ";
        }
    }
    else {
        quickSort(p, 0, n - 1);
        int temp=n,curSize=0;
        for (int i = 0; i < n; i++) {
            cout << p[i] << "-->";
            if (curSize+p[i] > x) {
                cout << i;
                temp = i ;
                break;
            }
            else {
                curSize += p[i];
            }
        }
        output << temp << endl;
        for (int i = 0; i < temp; i++) {
            output << m[p[i]] << " ";
        }
    }
}

