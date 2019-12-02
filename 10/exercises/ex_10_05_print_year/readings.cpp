#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void error(string str) {
    throw runtime_error(str);
}

void error(string str1, string str2) {
    throw runtime_error(str1 + str2);
}

void error(string str, int i) {
    throw runtime_error(str + to_string(i));
}


const int not_a_reading = -7777;
const int not_a_month = -1;

struct Day {
    vector<double> hour {vector<double>(24,not_a_reading)};
    bool is_empty() const;
};

bool Day::is_empty() const {
    for (int i = 0; i < 24; ++i) {
        if (hour[i] != not_a_reading) { return false; }
    }
    
    return true;
}

struct Month {
    int month {not_a_month};
    vector<Day> day {32};
};

struct Year {
    int year;
    vector<Month> month{12};
};

struct Reading {
    int day;
    int hour;
    double temperature;
};

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r) {
    if (r.day<1 || 31<r.day) { return false; }
    if (r.hour<0 || 23<r.hour) { return false; }
    if (r.temperature < implausible_min || implausible_max < r.temperature) {
        return false;
    }
    return true;
}

vector<string> month_input_tbl = {
    "jan", "feb", "mar", "apr", "may", "jun",
    "jul", "aug", "sep", "oct", "nov", "dec"
};

//return -1 if wrong month
int month_to_int(string s) {
    for (int i=0; i<12; ++i) {
        if (month_input_tbl[i]==s) { return i; }
    }
    return -1;
}

vector<string> month_print_tbl = {
    "January", "February", "March", "April",
    "May", "June", "July", "August", "September",
    "October", "November", "December"
};

string int_to_month(int i) {
    if (i<0 || i>12) { error("Wrong month index"); }
    return month_print_tbl[i];
}

void end_of_loop(istream& ist, char term, const string& message) {
    //fail because no more readings
    if (ist.fail()) {
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) return;
        error(message);
    }
}

//Read format (int int double)
istream& operator>>(istream& is, Reading& r) {
    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    
    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    //cout << d << '-' << h << "-" << t << "-" << ch2 << endl;
    if (!is || ch2 != ')') {
        error("Wrong record");
    }
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream& operator>>(istream& is, Month& m) {
    char ch = 0;
    if (is >> ch && ch!='{') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month") {
        error("Wrong begin of Month");
    }
    m.month = month_to_int(mm); //ToDo month_to_int()
    //cout << mm << ":" << endl;
    Reading r;
    int duplicates = 0;
    int invalids = 0;
    for(Reading r; is >> r;) {
        if (is_valid(r)) {
            if (m.day[r.day].hour[r.hour] != not_a_reading) {
                ++duplicates;
            }
            m.day[r.day].hour[r.hour] = r.temperature;
            //cout<<"Record: "<<r.day<<" "<<r.hour<<" "<<r.temperature<<endl;
        }
        else {
            +invalids;
        }
    }

    if (invalids) {
        error("Wrong data in Month, total ", invalids);
    }
    if (duplicates) {
        error("Duplicate entries in Month, total ", duplicates);
    }
    end_of_loop(is,'}',"Wrong end of Month");
    return is;
}

istream& operator>>(istream& is, Year& y) {
    char ch;
    is >> ch;
    if (ch!='{') {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }
    
    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker!="year") {
        error("Wrong begin of Year");
    }
    y.year = yy;
    //cout << yy << endl;
    while(true) {
        Month m;
        if (!(is >> m)) { break; }
        y.month[m.month] = m;
    }

    end_of_loop(is,'}',"Wrong end of Year");
    return is;
}

ostream& operator<<(ostream& os, const Reading& r) {
    os << "(" << r.day << " " << r.hour << " " << r.temperature << ")";
}

ostream& operator<<(ostream& os, const Day& d) {
    for (int i = 0; i < 24; ++i) {
        if(d.hour[i] != not_a_reading) {
            os << d.hour[i] << endl;
        }
    }
}

ostream& operator<<(ostream& os, const Month& m) {
    os << endl << "{ month " << int_to_month(m.month);
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 24; ++j) {
            if(m.day[i].hour[j] != not_a_reading) {
                os << " " << Reading{i,j,m.day[i].hour[j]};
            }
        }
    }
    os << " }";
}

ostream& operator<<(ostream& os, const Year& y) {
    os << "{ year " << y.year;
    for (int i = 0; i < 12; ++i) {
        if (y.month[i].month != not_a_month) {
            os << y.month[i];
        }
    }
    os << " }" << endl;
}

void print_year(ostream& os, Year yy) {
    os<<yy;
}

int main() {

    //cout << "Type name of input file: ";
    string iname = "data.txt";
    //cin >> iname;
    ifstream ifs {iname};
    //Why ifs, not ist?
    if (!ifs) { error("Not possible to open file ", iname); }

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    //cout << "Type name of output file: ";
    string oname = "data_new.txt";
    //cin >> oname;
    ofstream ofs {oname};
    if (!ofs) { error("Not possible to open file ", oname); }

    vector<Year> ys;
    while(true) {
        Year y;
        if(!(ifs>>y)) { break; }
        ys.push_back(y);
    }

    cout << "Read " << ys.size() << " year entries" << endl;

    for (Year& y : ys) { print_year(ofs, y); }

    return 0;

}
