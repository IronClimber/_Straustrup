#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    while (cin) {

        //get line
        cout<<"Type some string:"<<endl;
        string line;
        getline(cin, line);
        cout<<endl<<"Result:"<<endl; 

        for (char ch : line) {
            cout << "'" << ch << "'";
            if (ch != '\t') { cout << "      "; }

            if (isspace(ch))  { cout << setw(7) << "SPACE";  } 
		    else { cout << setw(7) << "-----"  ; }
            if (isalpha(ch))  { cout << setw(7) << "ALPHA";  } 
			else { cout << setw(7) << "-----"  ; }
            if (isdigit(ch))  { cout << setw(7) << "DIGIT";  } 
			else { cout << setw(7) << "-----"  ; }
            if (isxdigit(ch)) { cout << setw(8) << "XDIGIT"; } 
			else { cout << setw(8) << "------" ; }
            if (isupper(ch))  { cout << setw(7) << "UPPER";  } 
			else { cout << setw(7) << "-----"  ; }
            if (islower(ch))  { cout << setw(7) << "LOWER";  } 
			else { cout << setw(7) << "-----"  ; }
            if (isalnum(ch))  { cout << setw(7) << "ALNUM";  } 
			else { cout << setw(7) << "-----"  ; }
            if (iscntrl(ch))  { cout << setw(7) << "CNTRL";  } 
			else { cout << setw(7) << "-----"  ; }
            if (ispunct(ch))  { cout << setw(7) << "PUNCT";  } 
			else { cout << setw(7) << "-----"  ; }
            if (isprint(ch))  { cout << setw(7) << "PRINT";  } 
			else { cout << setw(7) << "-----"  ; }
            if (isgraph(ch))  { cout << setw(7) << "GRAPH";  } 
			else { cout << setw(7) << "-----"  ; }
            cout << endl;
        }
        cout << endl;
    }


    return 0;

}
