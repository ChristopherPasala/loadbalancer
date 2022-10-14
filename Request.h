#ifndef Request_H
#define Request_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;
/**
 * @brief Represents a request workload \n 
 * 
 * **Public Attributes** \n
 * inIp :  The IP sending the request \n 
 * outIP : The IP recieving the request \n 
 * jobTime : The time to complete a job \n
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