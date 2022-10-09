#include "Request.h"

#include <cstdlib>

Request::Request(){
    this->inIP = to_string(rand()%256) +"." + to_string(rand()%256) +"." +to_string(rand()%256) +"." +to_string(rand()%256);
    this->outIP = to_string(rand()%256) +"." + to_string(rand()%256) +"." +to_string(rand()%256) +"." +to_string(rand()%256);
    this->jobTime  = rand()%5;
}
