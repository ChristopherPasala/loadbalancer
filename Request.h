#ifndef Request_H
#define Request_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;
/**
 * @brief Represents a request workload
 * 
 */
class Request{
    public:
        string inIP;
        string outIP;
        int jobTime;
        /**
         * @brief defualt constructor
         * 
         */
        Request();
};

#endif