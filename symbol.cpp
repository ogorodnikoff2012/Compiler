#include "symbol.h"
#include <iostream>
#include <sstream>

using namespace std;

Symbol::Symbol()
{
    type = OTHER;
    data = "";
}

Symbol Symbol::readSymbol(istream &in)
{
    int anchor = in.tellg();
    //Skipping whitespaces
    int ch = in.peek();
    while(ch <= ' ')
    {
        in.get();
        ch = in.peek();
    }

    Symbol s;
    s = readIdentifier(in);
    if(s.type == IDENTIFIER)
    {
        return s;
    }

    /*s = readString(in);
    if(s.type == LITERAL)
    {
        return s;
    }

    s = readLParen(in);
    if(s.type == LPAREN)
    {
        return s;
    }

    s = readRParen(in);
    if(s.type == RPAREN)
    {
        return s;
    }

    s = readLBrak(in);
    if(s.type == LBRAK)
    {
        return s;
    }

    s = readRBrak(in);
    if(s.type == RBRAK)
    {
        return s;
    }

    s = readLBrace(in);
    if(s.type == LBRACE)
    {
        return s;
    }

    s = readRBrace(in);
    if(s.type == RBRACE)
    {
        return s;
    }

    s = readBar(in);
    if(s.type == BAR)
    {
        return s;
    }

    s = readEql(in);
    if(s.type == EQL)
    {
        return s;
    }

    s = readPeriod(in);
    if(s.type == PERIOD)
    {
        return s;
    }
*/
    in.seekg(anchor);
    s.type = OTHER;
    s.data = "";
    s.children.clear();
    return s;
}

string Symbol::toString()
{
    stringstream ans;
    ans << "<symbol type=";
    ans << (int)type;
    ans << ">\n<data>";
    ans << data;
    ans << "</data>";
    for(int i = 0; i < children.size(); i++)
    {
        ans << '\n';
        ans << children[i].toString();
    }
    ans << "\n</symbol>";
    return ans.str();
}

Symbol Symbol::readIdentifier(istream &in)
{
    int anchor = in.tellg();
    int ch = in.peek();
    Symbol s;
    if(!islower(ch) && !isupper(ch))
    {
        in.seekg(anchor);
        return s;
    }

    s.type = IDENTIFIER;
    s.data.push_back(in.get());
    ch = in.peek();

    while(islower(ch) || isupper(ch) || isdigit(ch))
    {
        s.data.push_back(in.get());
        ch = in.peek();
    }

    return s;
}
