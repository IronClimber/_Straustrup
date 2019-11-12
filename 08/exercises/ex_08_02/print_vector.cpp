#include <iostream>
#include <vector>

using namespace std;

void print_vector(const string str, vector<int>& list) {
    cout<<str<<":"<<endl;
    for (int i = 0; i < list.size(); ++i) {
        cout<<i<<". "<<list[i]<<endl;
    }
}

vector<int> tomatoes {34,234,234,23,124};

int main() {
    print_vector("Помидоры", tomatoes);
}
