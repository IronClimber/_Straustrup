#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string ifile = "file.txt";
    ifstream ifs{ifile};
    if (!ifs) { 
        cout << "Somthing wrong with input file " << ifile << endl;
        return 1;
    }

    int space = 0;
    int alpha = 0;
    int digit = 0;
    int xdigit = 0;
    int upper = 0;
    int lower = 0;
    int alnum = 0;
    int cntrl = 0;
    int punct = 0;
    int print = 0;
    int graph = 0;

    cout << "Counting..." << endl;

    for(char ch; ifs.get(ch);) {
        if (isspace(ch))  { ++space;  }
        if (isalpha(ch))  { ++alpha;  }
        if (isdigit(ch))  { ++digit;  }
        if (isxdigit(ch)) { ++xdigit; }
        if (isupper(ch))  { ++upper;  }
        if (islower(ch))  { ++lower;  }
        if (isalnum(ch))  { ++alnum;  }
        if (iscntrl(ch))  { ++cntrl;  }
        if (ispunct(ch))  { ++punct;  }
        if (isprint(ch))  { ++print;  }
        if (isgraph(ch))  { ++graph;  }
    }

    string ofile = "count.txt";
    ofstream ofs{ofile};
    if (!ofs) {
        cout << "Somthing wrong with output file " << ofile << endl;
        return 1;
    }

    ofs << "SPACE:"  << '\t' << space  << endl;    
    ofs << "ALPHA:"  << '\t' << alpha  << endl;
    ofs << "DIGIT:"  << '\t' << digit  << endl;
    ofs << "XDIGIT:" << '\t' << xdigit << endl;
    ofs << "UPPER:"  << '\t' << upper  << endl;
    ofs << "LOWER:"  << '\t' << lower  << endl;
    ofs << "ALNUM:"  << '\t' << alnum  << endl;
    ofs << "CNTRL:"  << '\t' << cntrl  << endl;
    ofs << "PUNCT:"  << '\t' << punct  << endl;
    ofs << "PRINT:"  << '\t' << print  << endl;
    ofs << "GRAPH:"  << '\t' << graph  << endl;

    return 0;

}
