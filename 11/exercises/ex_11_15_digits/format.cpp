#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

    string ifile = "file.txt";
    ifstream ifs{ifile};
    if (!ifs) { 
        cout << "Somthing wrong with input file " << ifile << endl;
        return 1;
    }

    cout << "Formatting..." << endl;

    vector<double> vd;

    for  (double d; ifs >> d;) {
        vd.push_back(d);
    }

    string ofile = "format.txt";
    ofstream ofs{ofile};
    if (!ofs) {
        cout << "Somthing wrong with output file " << ofile << endl;
        return 1;
    }

    for (int i = 0; i < vd.size(); ++i) {
        ofs << scientific << setprecision(8) << setw(20) << vd[i];    
        if (i!=0 && (i+1)%4==0) { ofs << endl; }
    }

    cout << "Done!" << endl;

    return 0;

}
