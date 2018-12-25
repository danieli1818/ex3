//
// Created by daniel on 12/20/18.
//

#include "Lexer.h"

using namespace std;

void Lexer::addSpaces(string &str) {
    bool isInQuotes = false; //"
    for (size_t i = 0; i < str.length() - 1; ++i) {
        if (str[i] == '"') {
            isInQuotes = !isInQuotes;
        } else {
            if (isInQuotes || str[i] == ' ' || str[i + 1] == ' ') {
                continue;
            }
            if ((isOperatorOrBrackets(str[i]) && str[i + 1] != '=') || (isOperatorOrBrackets(str[i + 1]) && (str[i] != '=' || str[i + 1] != '='))) {
                str.insert(i + 1, 1, ' ');
            } else {
                if ((str[i] == ',' && str[i + 1] != ' ') || str[i + 1] == ',') {
                    str.insert(i + 1, 1, ' ');
                }
            }
        }
    }
    if (str[str.length() - 1] != ' ') {
        str.insert(str.length(), 1, ' ');
    }
}

list<string> Lexer::split(string str, const string &delimiter) {
    size_t pos = 0;
    std::string token;
    list<string> arr;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        if (!token.empty()) {
            arr.push_back(token);
        }
        str.erase(0, pos + delimiter.length());
    }
    return arr;
}

void Lexer::replaceTabs(string &str) {
    for (auto & character : str) {
        if (character == '\t') {
            character = ' ';
        }
    }
}

list<string> Lexer::lexer(string& data) {
    if (data.empty()) {
        list<string> arrResult;
        return arrResult;
    }
    replaceTabs(data);
    addSpaces(data);
    list<string> arrResult;
    if (data.find('\"') != string::npos) {
        list<string> arrQuotes = split(data, "\"");
        std::list<string>::iterator it = arrQuotes.begin();
        for (int i = 0; i < arrQuotes.size(); ++i) {
            if (i % 2 == 0) {
                addSpaces(*it);
                list<string> temp = split(*it, " ");
                arrResult.insert(arrResult.end(), temp.begin(), temp.end());
            } else {
                arrResult.push_back("\"" + *it + "\"");
            }
            it++;
        }
    } else {
        arrResult = split(data, " ");
    }
    return arrResult;
}



