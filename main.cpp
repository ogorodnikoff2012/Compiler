#include <iostream>
#include <fstream>
#include "symbol.h"

using namespace std;

int main()
{
    ifstream in("text.txt");
    Symbol s = Symbol::readSymbol(in);
    cout << s.toString();
    return 0;
}

