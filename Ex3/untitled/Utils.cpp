//
// Created by daniel on 12/20/18.
//

#include "Utils.h"

vector<string> Utils::split(string str, string delimiter) {
    size_t pos = 0;
    std::string token;
    vector<string> arr;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        if (!token.empty()) {
            arr.push_back(token);
        }
        str.erase(0, pos + delimiter.length());
    }
    return arr;
}


