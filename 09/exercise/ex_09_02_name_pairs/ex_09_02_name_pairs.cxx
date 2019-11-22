#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Name_pairs {
private:
	vector<string> name;
	vector<double> age;
public:	
	void read_names();
	void read_ages();
	void print();
	void sort();
};

void Name_pairs::read_names(void) {
	cout<<"---Read names---"<<endl;
	while(cin) {
        cout<<"Type name: ";
        string n;
        cin>>n;
        if (n == "NoName") {
            break;
        }
        name.push_back(n);
    }	
}

void Name_pairs::read_ages(void) {
    cout<<"---Get ages---"<<endl;
    for (int i = 0; i < name.size(); ++i) {
        cout<<name[i]<<" age is ";
        double a;
        cin>>a;
        age.push_back(a);
    }	
}

void Name_pairs::sort(void) {
	//Save name
    vector<string> last_name = name;
    //Sort name
    std::sort(name.begin(), name.end());
    //Sort age
    vector<double> new_age;
    for (int i = 0; i < name.size(); ++i) {
        for (int j = 0; j < name.size(); ++j) {
            if (name[i] == last_name[j]) {
                new_age.push_back(age[j]);
            }
        }
    }
    age = new_age;
}

void Name_pairs::print(void) {
    for (int i = 0; i < name.size(); ++i) {
        cout<<i<<". "<<name[i]
        <<"-"<<age[i]
        <<endl;
    }
}

int main()
{
	Name_pairs np;
	np.read_names();
	np.read_ages();
	np.sort();
	np.print();
}