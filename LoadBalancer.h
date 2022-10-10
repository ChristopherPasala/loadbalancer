#ifndef LoadBalancer_H
#define LoadBalancer_H
#include "Webserver.h"
#include <vector>
#include <queue>

class LoadBalancer{
    public:
        queue<Request*> requestQ;
        void addRequest(Request* request){
            requestQ.push(request);
        }
        Request* getRequest(){
            if(requestQ.size() != 0){
                Request* toRet = requestQ.front();
                requestQ.pop();
                return toRet;
            }
            return nullptr;
        }
        bool isQueueEmpty(){
            if (requestQ.size() == 0){
                return true;
            }
            return false;
        }
        int getSize(){
            return requestQ.size();
        }
};

#endif