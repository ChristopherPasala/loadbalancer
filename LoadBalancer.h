#ifndef LoadBalancer_H
#define LoadBalancer_H
#include "Webserver.h"
#include <vector>
#include <queue>

using namespace std;

class LoadBalancer{
    public:
        queue<shared_ptr<Request>> requestQ;
        void addRequest(shared_ptr<Request> request){
            requestQ.push(request);
        }
        shared_ptr<Request> getRequest(){
            if(requestQ.size() != 0){
                shared_ptr<Request> toRet = requestQ.front();
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