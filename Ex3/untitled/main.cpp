#include <iostream>
#include <unistd.h>
#include <thread>
#include <fstream>
#include "Commands/ServerUtils.h"
#include "Lexer.h"
#include "Parser.h"
#include "Vars/ToolBox.h"
#include "Interpreter.h"

using namespace std;

int main(int args, char* argv[]) {
    try {
        if (args >= 3) {
            throw "Too Many Arguments!!!!";
        }
        if (args == 2) {
            Interpreter::initialize();
            ifstream* infile = new ifstream();
            Interpreter::getFileStream() = infile;
            try {
                infile->open(argv[1]);
            } catch (...) {
                throw "Error opening the file " + string(argv[1]);
            }
            string line;
            while (getline(*infile, line))
            {
                list<string> elements = Interpreter::getLexer().lexer(line);
                Interpreter::getParser().parser(elements);
            }
            try {
                infile->close();
            } catch (...) {
                throw "Error closing the file " + string(argv[1]);
            }
            delete infile;
        } else { //TODO CMD
            throw "Not enough arguments";
        }
    } catch (char const * str) {
        perror(str);
        return 1;
    } catch (string & str) {
        perror(str.c_str());
        return 1;
    } catch (...) {
        perror("Error!!!!");
        return 1;
    }

    ToolBox::destroy();

    /*
    ToolBox::initialize();
    int length = 0;
    string* arr = nullptr;
    //string str = " (10+23  )\"hi  hello\"";
    string str = "openDataServer 5400 10";
    //string str = "print \"hi hello\"";
    Lexer l;
    list<string> vectorArr = l.lexer(str);
    Parser parser;
    parser.parser(vectorArr);
    str = "connect 192.168.56.1 5402";
    vectorArr = l.lexer(str);
    parser.parser(vectorArr);
    //str = "var x = bind \"/instrumentation/altimeter/indicated-altitude-ft\"";
    str = "var x = 0";
    vectorArr = l.lexer(str);
    parser.parser(vectorArr);

    str = "var y = bind \"/controls/flight/rudder\"";
    vectorArr = l.lexer(str);
    parser.parser(vectorArr);
    //struct ServerParameters* params = new ServerParameters();
    //cout << typeid(params).name() << endl;
    //delete params;
    while (true) {
        //ToolBox::getClient().setFlightParameter("controls/flight/rudder", 1);
        str = "y = x+1";
        vectorArr = l.lexer(str);
        parser.parser(vectorArr);
        sleep(2);
        str = "y = x-1";
        vectorArr = l.lexer(str);
        parser.parser(vectorArr);
        sleep(2);
        //ToolBox::getClient().setFlightParameter("controls/flight/rudder", -1);
    }*/
    return 0;
}