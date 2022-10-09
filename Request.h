#ifndef Request_H
#define Request_H

#include <iostream>
#include <string>

using namespace std;

class Request{
    public:
        string inIP;
        string outIP;
        int jobTime;
        Request();
};

#endif