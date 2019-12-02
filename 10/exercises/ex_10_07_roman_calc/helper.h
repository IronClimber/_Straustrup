#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "params.h"
#include <string>

void error(std::string str);
void error(std::string str1, std::string str2);
void error(std::string str1, char ch);
void keep_window_open(char sign);
void print_help(void);

#endif /* helper.h */
