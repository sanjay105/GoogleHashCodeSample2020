#include <iostream>
#include<fstream>
#include<map>
#include<queue>
#define ll long long
using namespace std;
//modified sort approach using maxheap
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
    priority_queue<int> p;
    map<int, int> m;
    //ll maxSlice = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        int pizza;
        input >> pizza;
        if (m[pizza] == 0) {
            m[pizza] = i;
            p.push(pizza);
        }
    }
    vector<int> res;
    while (!p.empty()) {
        if (x > p.top()) {
            res.push_back(m[p.top()]);
            x -= p.top();
        }
        p.pop();
    }
    cout << res.size() << endl;
    output << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        output << res[i] << " ";
    }
}
