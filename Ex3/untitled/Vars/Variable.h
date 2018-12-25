//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_VARIABLE_H
#define UNTITLED_VARIABLE_H

#include <string>

using namespace std;

class Variable { //TODO
    double m_data;
    string m_pathToVariable;
    string m_bindedVariable;
    bool m_isBinded;
    bool m_updated;
public:
    Variable();
    void setData(double data, bool changeInSimulator);
    double getData();
    bool isBinded();
    string& getBindedPath();
    string& getBindedVariable();
    bool updated();
    bool setUpdate(bool update);
    void bind(string pathToVariable);
    void bind(Variable* var, string& varName);
    ~Variable() = default;
};


#endif //UNTITLED_VARIABLE_H
