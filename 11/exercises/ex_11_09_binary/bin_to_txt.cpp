#include <iostream>
#include <fstream>

using namespace std;


template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}

int main() {

    string text = "new_text.txt";
    string binary = "text.bin";

    cout << "Copy text from " << binary << " to " << text << endl;

    ifstream ifs {binary, ios_base::binary};
    if (!ifs) {cout << "Something wrong with input file " << binary << endl; return 1; }

    ofstream ofs {text};
    if (!ofs) {cout << "Something wrong with output file " << text << endl; return 1; }

    for (char ch; ifs.read(as_bytes(ch), sizeof(char));) {
        ofs << ch;
    }

    cout << "Done." << endl;
    return 0;
}
