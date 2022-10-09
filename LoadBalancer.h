#ifndef LoadBalancer_H
#define LoadBalancer_H
#include "Webserver.h"
#include <vector>
#include <queue>

class LoadBalancer{
    queue<Request> requestQ;

    void addRequest(Request request){
        requestQ.push(request);
    }
    
    Request getRequest(){
        if(requestQ.size() != 0){
            Request toRet = requestQ.front();
            requestQ.pop();
            return toRet;
        }
    }

    bool isQueueEmpty(){
        if (requestQ.size() == 0){
            return true;
        }
        return false;
    }
};

#endif