#include "Request.h"

#include <cstdlib>

/**
 * @brief Construct a new Request:: Request object which will initialize a random in and out IP as well as a random job time from 0 to 30.
 * 
 */
Request::Request(){
    this->inIP = to_string(rand()%256) +"." + to_string(rand()%256) +"." +to_string(rand()%256) +"." +to_string(rand()%256);
    this->outIP = to_string(rand()%256) +"." + to_string(rand()%256) +"." +to_string(rand()%256) +"." +to_string(rand()%256);
    this->jobTime  = rand()%500;
}
