#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_names(const vector<string>& n, const vector<int>& a) {
    for (int i = 0; i < n.size(); ++i) {
        cout<<i<<". "<<n[i]<<"-"<<a[i]<<endl;
    }
}

vector<string> name;
vector<int> age;

int quantity = 5;

int main() {
    //Get name vector    
    cout<<"Get names:"<<endl;
    for (int i = 0; i < quantity; ++i) {
        cout<<"Type name: ";
        string n;
        cin>>n;
        name.push_back(n);
    }
    
    //Get age vector
    cout<<"Get ages:"<<endl;
    for (int i = 0; i < quantity; ++i) {
        cout<<"Type age: ";
        int a;
        cin>>a;
        age.push_back(a);
    }

    //print
    cout<<"Print result: "<<endl;
    print_names(name, age);
    //Save name
    vector<string> last_name = name;
    //Sort name
    cout<<"Sorting..."<<endl;
    sort(name.begin(), name.end());
    //print
    cout<<"Print result after sorting names:"<<endl;
    print_names(name, age);
    //Sort age
    vector<int> new_age;
    for (int i = 0; i < quantity; ++i) {
        for (int j = 0; j < quantity; ++j) {
            if (name[i] == last_name[j]) {
                new_age.push_back(age[j]);
            }
        }
    }
    //print
    cout<<"Print result after sorting ages:"<<endl;
    print_names(name, new_age);
    return 0;
}
