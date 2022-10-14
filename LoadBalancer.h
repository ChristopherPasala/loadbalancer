#ifndef LoadBalancer_H
#define LoadBalancer_H
#include "Webserver.h"
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief LoadBalancer class that hold the request queue along with capabalities to manipulate it
 * 
 *  
 */
class LoadBalancer{
    public:
        queue<shared_ptr<Request>> requestQ;
        /**
         * @brief Used for adding Request shared pointer to the request queue
         * 
         * @param request 
         */
        void addRequest(shared_ptr<Request> request){
            requestQ.push(request);
        }

        /**
         * @brief Used to get a Request shared pointer from the queue
         * 
         * @return shared_ptr<Request> 
         */
        shared_ptr<Request> getRequest(){
            if(requestQ.size() != 0){
                shared_ptr<Request> toRet = requestQ.front();
                requestQ.pop();
                return toRet;
            }
            return nullptr;
        }
        /**
         * @brief Used to check if the Request queue is empty
         * 
         * @return true 
         * @return false 
         */
        bool isQueueEmpty(){
            if (requestQ.size() == 0){
                return true;
            }
            return false;
        }
        /**
         * @brief Used to get the size of the Request queue
         * 
         * @return int 
         */
        int getSize(){
            return requestQ.size();
        }
};

#endif