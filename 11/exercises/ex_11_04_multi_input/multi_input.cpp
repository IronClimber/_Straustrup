#include <iostream>
#include <sstream>

//34 023 23 23 0x23 0xA 1 010
//0x34 0x3 10 cat 012 0xcar 12 1ku

using namespace std;

int main() {
    
    
    while(cin) {

        //get line
        cout<<"Type DEC, OCT, HEX numbers in random order: "<<endl;
        string line;
        getline(cin, line);
        cout<<endl<<"Result:"<<endl;        

        //process line
        istringstream ss{line};
        for(string word; ss>>word;) {

            //process number
            istringstream ws{word};
            char ch;
            int value;
            ws.get(ch);
            if (ch == '0') {
                ws.get(ch);
                //hex
                if (ch == 'x') { 
                    if (!(ws>>hex>>value) || !ws.eof()) { 
                        cout<<word<<'\t'<<"---"<<'\t'<<"not a number"<<endl;
                        continue; 
                    }
                    cout<<word<<'\t'<<"HEX"<<'\t';
                }
                //oct
                else {
                    ws.unget();
                    if(!(ws>>oct>>value) || !ws.eof()) { 
                        cout<<word<<'\t'<<"---"<<'\t'<<"not a number"<<endl;
                        continue; 
                    }
                    cout<<word<<'\t'<<"OCT"<<'\t';
                }            
            }
            //dec
            else {
                ws.unget();
                if(!(ws>>dec>>value) || !ws.eof()) { 
                    cout<<word<<'\t'<<"---"<<'\t'<<"not a number"<<endl;
                    continue; 
                }
                cout<<word<<'\t'<<"DEC"<<'\t'; 
            }

            //print result
            cout<<"converted to decimal "<<dec<<value<<endl;
        }
        cout<<endl;
    }

    return 0;

}
