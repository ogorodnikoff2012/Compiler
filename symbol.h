#ifndef SYMBOL_H
#define SYMBOL_H

#include "symbol_type.h"
#include <vector>
#include <string>

class Symbol
{
private:
    SymbolType type;
    std::string data;
    std::vector<Symbol> children;
    Symbol();
    static Symbol readIdentifier(std::istream &in);
public:
    static Symbol readSymbol(std::istream &in);
    std::string toString();
};

#endif // SYMBOL_H
