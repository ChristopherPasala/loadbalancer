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
 * inIp :  A string containing the IP sending the request \n 
 * outIP : A string containing the IP recieving the request \n 
 * jobTime : An int containing the time to complete a job \n
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