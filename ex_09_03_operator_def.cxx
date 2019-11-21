#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Name_pairs {
private:
	vector<string> name;
	vector<double> age;
public:
	string get_name(int i) const { return name[i]; }
	double get_age(int i) const { return age[i]; }
	int size() const { return name.size(); }
		
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

//???? return? if failed
ostream& operator<<(ostream& os, const Name_pairs& np) {
	for (int i = 0; i < np.size(); ++i) {
        os<<i<<". "<<np.get_name(i)
        <<"-"<<np.get_age(i)
        <<endl;
    }
    return os;
} 

bool operator==(const Name_pairs& a, const Name_pairs& b) {
	if (a.size() == b.size()) {		
		for (int i = 0; i < a.size(); ++i) {
			if (a.get_name(i) != b.get_name(i) ||
			     a.get_age(i) != b.get_age(i)) {
			     return false;	
		    }
		}
		return true;
	}
	return false;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b) {
	return !(a==b);
}

int main()
{
	Name_pairs np;
	np.read_names();
	np.read_ages();
	np.sort();
	cout<<np;
}