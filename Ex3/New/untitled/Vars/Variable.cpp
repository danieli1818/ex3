//
// Created by daniel on 12/18/18.
//

#include "Variable.h"
#include "ToolBox.h"

Variable::Variable() {
    m_data = 0;
    m_isBinded = false;
    m_pathToVariable = "";
    m_bindedVariable = "";
    m_updated = false;
}

void Variable::setData(double data, bool changeInSimulator) {
    if (m_isBinded && changeInSimulator) {
        if (!ToolBox::getIsClientInitialized()) {
            throw "You didn't connect to the Simulator!!!!";
        }
        ToolBox::getClient().setFlightParameter(m_pathToVariable, data);
        m_data = data;
    } else {
        m_data = data;
    }
}

double Variable::getData() {
    return m_data;
}

bool Variable::isBinded() {
    return m_isBinded;
}

string& Variable::getBindedPath() {
    return m_pathToVariable;
}

string& Variable::getBindedVariable() {
    return m_bindedVariable;
}

void Variable::bind(string pathToVariable) {
    m_pathToVariable = pathToVariable;
    m_isBinded = true;
}

void Variable::bind(Variable *var, string& varName) {
    if (var->isBinded()) {
        bind(var->getBindedPath());
    } else {
        m_bindedVariable = varName;
    }
}

bool Variable::updated() {
    return m_updated;
}

void Variable::setUpdate(bool update) {
    m_updated = update;
}


