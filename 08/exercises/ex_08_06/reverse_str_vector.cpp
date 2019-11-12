#include <iostream>
#include <vector>

using namespace std;

void print_vector(const string str, vector<string>& list) {
    cout<<str<<":"<<endl;
    for (int i = 0; i < list.size(); ++i) {
        cout<<i<<". "<<list[i]<<endl;
    }
}

void reverse_vector(vector<string>& v) {
    int n = v.size();
    //even = n%2;
    for (int i = 0; i<(n/2); ++i) {
        swap(v[i],v[n-i-1]);
    }
}

vector<string> f{"Hi", ",", "Where", "Are", "You", "?"};

int main() {
    print_vector("String vector", f);
    reverse_vector(f);
    print_vector("Reversed string vector", f);
}
