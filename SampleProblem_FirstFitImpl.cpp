#include <iostream>
#include<fstream>
#include<map>
#define ll long long
using namespace std;
//static int cost;

int main()
{
    ifstream input; ofstream output;
    string inputfilename, outputfilename;
    cout << "Enter File Name:"; cin >> inputfilename;cout << endl;
    outputfilename = inputfilename;
    inputfilename += ".in";
    outputfilename += ".out";
    input.open(inputfilename); output.open(outputfilename);
    int x,n;
    input >> x>>n;
    int* p = (int*)malloc(sizeof(int) * n);
    map<int, int> m;
    //ll maxSlice = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        int pizza;
        input >> pizza;
        if (m[pizza] == 0) {
            //p[index++] = pizza;
            m[pizza] = i;
            //maxSlice += pizza;
            if (x > pizza) {
                p[index++] = i;
                x -= pizza;
            }
        }
    }
    output << index << endl;
    for (int i = 0; i < index; i++) {
        output << p[i] << " ";
    }
}
