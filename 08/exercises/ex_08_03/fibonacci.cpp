#include <iostream>
#include <vector>

using namespace std;

void print_vector(const string str, vector<int>& list) {
    cout<<str<<":"<<endl;
    for (int i = 0; i < list.size(); ++i) {
        cout<<i<<". "<<list[i]<<endl;
    }
}

//!!!!But what if v not Empty???
void fibonacci(int x, int y, vector<int>& v, int n) {
    if (n<2) {
        cout<<"Error: n<2."<<endl;
        return;
    }
    v.push_back(x);
    v.push_back(y);
    for (int i=2; i<n; ++i) {
        v.push_back(v[i-1]+v[i-2]);
    }
}

vector<int> f;

int main() {
    fibonacci(3,7,f,13);
    print_vector("Фибоначчи:", f);
}
