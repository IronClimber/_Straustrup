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

void reverse_vector(vector<int>& v) {
    int n = v.size();
    //even = n%2;
    for (int i = 0; i<(n/2); ++i) {
        swap(v[i],v[n-i-1]);
    }
}

vector<int> f;

int main() {
    fibonacci(1,4,f,5);
    print_vector("Фибоначчи", f);
    reverse_vector(f);
    print_vector("Перевёрнутый вектор", f);
}
