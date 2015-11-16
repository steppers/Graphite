//
// Created by steppers on 09/11/15.
//

#include "Logger.h"

Logger::Logger() {
    _file.open("log.txt", ios::out);
}

Logger::~Logger() {
    _file.close();
}

void Logger::logMessage(string source, string message) {
    unique_lock<mutex> lock(_mutex);
    if(_debug)
        cout << "[" << source << "] " << message << endl;
    _file << "[" << source << "] " << message << endl;
}

void Logger::debugEnable(bool enabled) {
    _debug = enabled;
}