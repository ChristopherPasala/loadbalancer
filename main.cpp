#include "LoadBalancer.h"

using namespace std;

int main(int argc, char* argv[]){
    // TODO: get from user
    int totalTime = 20;
    int webserverSize = 1;
    int requestSize = webserverSize*2;
    
    bool serversStillWorking = false;
    LoadBalancer loadBalancer;

    for(int i=0; i < requestSize; i++){
        Request* req = new Request();
        cout << "Request created with jobtime of " <<req->jobTime << endl;
        loadBalancer.addRequest(req);
    }
    
    cout << "LoadBalancerQ size: " << loadBalancer.getSize() << endl;

    vector<Webserver> webservers;
    for(int i = 0; i < webserverSize; i++){
        webservers.push_back(Webserver("Webserver"+to_string(i)));
    }
    
    for(int i = 0; i < totalTime; i++){
        serversStillWorking = false;
        if(!loadBalancer.isQueueEmpty()){
            for(Webserver webserver : webservers){
                if(webserver.isJobDone(i)){
                    cout << webserver.getName() << " has finished" << endl;
                    Request* tempReq  = loadBalancer.getRequest();
                    webserver.setRequest(i,*tempReq);
                    delete tempReq;
                    cout << webserver.getName()<< " is getting request of ipIN "<< webserver.getRequest().inIP << endl;
                }
                cout << "there are request and webserver " << webserver.getName() <<" is full at the time " << i<<  endl;  
            }
        }
        else{
            for(Webserver webserver : webservers){
                if(webserver.isJobDone(i)){
                    cout << webserver.getName() << " has finished" << endl;
                } else{
                    serversStillWorking = true;
                }
            }
            if(!serversStillWorking){
                break;
            }
        }
    }

    return 1;
}