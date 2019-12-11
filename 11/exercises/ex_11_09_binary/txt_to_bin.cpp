#include <iostream>
#include <fstream>

/*
How to correctly convert string to bytes?
*/

using namespace std;


template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}

int main() {

    string text = "text.txt";
    //string new_text = "new_text.txt";
    string binary = "text.bin";

    cout << "Copy text from " << text << " to " << binary << endl;

    ifstream ifs {text};
    if (!ifs) {cout << "Something wrong with input file " << text << endl; return 1; }

    ofstream ofs {binary, ios_base::binary};
    if (!ofs) {cout << "Something wrong with output file " << binary << endl; return 1; }

    string t;
    /*
    for (char ch; ifs.get(ch);) {
        ofs.write(as_bytes(ch), sizeof(char));
    }
    */

    for (char ch; ifs.get(ch);) {
        t += ch;
        //ofs.write(as_bytes(ch), sizeof(char));
    }

    //char data[text.size()] = text.c_str();

    //for (

    ofs << t;

    cout << "Done." << endl;
    return 0;
}
