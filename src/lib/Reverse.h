#ifndef __REVERSE_H__
#define __REVERSE_H__

#include <string>
#include "Reverse.h"
#include "Logger.h"

/**
 * Trivial class whose only function is to reverse a string.
 * Should use std::reverse instead but want to have example with own class
 */
class Reverse {
public:
    Logger logger;
    std::string reverse(std::string &toReverse);
};

#endif
