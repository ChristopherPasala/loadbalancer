#ifndef Webserver_H
#define Webserver_H
#include "Request.h"

class Webserver{
    private:
        shared_ptr<Request> request;
        //signify no job currently
        int jobStart =-1;
        string name; 
        bool finished = true;
    public:
        Webserver(){
        }
        Webserver(string name){
            this->name = name;
        }
        void setName(string name){
            this->name = name;
        }
        bool getFinished(){
            return finished;
        }
        void setFinished(bool val){
            finished = val;
        }
        string getName(){
            return name;
        }
        int getjobStart(){
            return jobStart;
        }
        bool isJobDone(int currentTime){
            if(jobStart == -1){
                //cout << this->getName() << " does not have a job " <<jobStart<<  endl;
                return true;
            }
            //cout << this->getName() << " jobendTime: "<< jobStart+request->jobTime << " currenttime: " << currentTime << endl;
            if((jobStart+request->jobTime) <= currentTime)   {
                return true;
            }
            return false;
        }
        void setRequest(int currentTime, shared_ptr<Request> request){
            this->jobStart = currentTime;
            this->request = request;
        }
       shared_ptr<Request> getRequest(){
            return request;
        }

};

#endif