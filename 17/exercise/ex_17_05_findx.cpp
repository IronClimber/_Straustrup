#include <iostream>
#include <string.h>

//Need for check if not found
//If not found return nullptr
char* findx(const char* s, const char* x) {
    
	
	while(*s) {
        bool result = true;
		for (int i = 0; i < strlen(x); ++i) {
			if(s[i] != x[i]) { result = false; }
 			break;
		}
		if (result) { return (char*)(s); }
		++s; 
    }
	return nullptr;


}

int main() {

	char str1[] {"Hello, Robot Rob!"};
	char str2[] {"Rob"};

	char* p = findx(str1,str2);
	
    std::cout << str1 << " " << static_cast<void*>(p) 
			  << " " << p-str1 << std::endl;





}
