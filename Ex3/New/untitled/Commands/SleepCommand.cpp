//
// Created by daniel on 12/24/18.
//

#include <unistd.h>
#include "SleepCommand.h"
#include "../Expression/ExpressionManager.h"

void SleepCommand::doCommand(list<string>::iterator &it, list<string> &args) {
    ExpressionManager em;
    double arg1 = em.calculate(it, args);
    if ((__useconds_t)arg1 != arg1) {
        throw "Not Valid Sleep Command!!!!";
    }
    usleep((__useconds_t)(arg1 * 1000));
}


