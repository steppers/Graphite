//
// Created by steppers on 09/11/15.
//

#ifndef SSIMCPP_LOGGER_H
#define SSIMCPP_LOGGER_H

#include <iostream>
#include <fstream>
#include <mutex>
#include <chrono>
#include <string>

using namespace std;

class Logger {
public:
    Logger();
    ~Logger();

    void logMessage(string source, string message);
    void debugEnable(bool enabled);

private:
    bool _debug = false;
    ofstream _file;
    mutex _mutex;
};


#endif //SSIMCPP_LOGGER_H
