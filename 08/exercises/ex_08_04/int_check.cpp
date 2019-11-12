#include <iostream>
#include <vector>

using namespace std;

void print_vector(const string str, vector<int>& list) {
    cout<<str<<":"<<endl;
    for (int i = 0; i < list.size(); ++i) {
        cout<<i<<". "<<list[i]<<endl;
    }
}

void fibonacci(int x, int y, vector<int>& v, int n) {
    if (n<2) {
        cout<<"Error: n<2."<<endl;
        return;
    }
    v.clear();
    v.push_back(x);
    v.push_back(y);
    for (int i=2; i<n; ++i) {
        v.push_back(v[i-1]+v[i-2]);
        if (v[i]<v[i-1]) {
            cout<<"MAX integer: "<<v[i-1]<<endl;
            return;
        }
    }
}

vector<int> f;

int main() {
    fibonacci(0,1,f,50);
    fibonacci(2,6,f,50);
    fibonacci(7,9,f,50);
    fibonacci(45,456,f,50);
    //print_vector("Фибоначчи:", f);
}
