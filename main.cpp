#include "LoadBalancer.h"

using namespace std;

int main(int argc, char* argv[]){
    // TODO: get from user
    int totalTime = 1000;
    int webserverSize = 30;
    int requestSize = webserverSize*2;
    
    bool serversStillWorking = false;
    LoadBalancer loadBalancer;
    int min = totalTime +1;
    int max = -1;
    for(int i=0; i < requestSize; i++){
        shared_ptr<Request> req = shared_ptr<Request> (new Request());
        if(req->jobTime > max){
            max = req->jobTime;
        }
        if(req->jobTime < min){
            min = req->jobTime;
        }
        cout << "Request created with jobtime of " <<req->jobTime << " and inIP " << req->inIP << endl;
        loadBalancer.addRequest(req);
    }
    cout << endl;
    cout << "Range of jobTimes is ["<< min << " - " << max << "]"<< endl;
    cout << "LoadBalancerQ size: " << loadBalancer.getSize() << endl;
    cout << endl;
    vector<shared_ptr<Webserver>> webservers;
    for(int i = 0; i < webserverSize; i++){
        webservers.push_back(shared_ptr<Webserver>(new Webserver("Webserver"+to_string(i))));
    }
    
    for(int i = 0; i < totalTime; i++){
        serversStillWorking = (i == 0) ? true : false;
            for(shared_ptr<Webserver> webserver : webservers){
                if(webserver->isJobDone(i)){
                    if(i != 0 && !webserver->getFinished()){
                        cout << webserver->getName() << " has finished job " <<webserver->getRequest()->inIP << " to "<<webserver->getRequest()->outIP <<" at time " << i <<  endl;
                        webserver->setFinished(true);
                    }
                    if(!loadBalancer.isQueueEmpty()){
                        webserver->setRequest(i,loadBalancer.getRequest());
                        webserver->setFinished(false);
                    }
                }
                else{
                    serversStillWorking = true;
                }
            }
            if(!serversStillWorking){
                break;
            }
        }
    return 1;
}