#ifndef Webserver_H
#define Webserver_H
#include "Request.h"

class Webserver{
    private:
        Request request;
        //signify no job currently
        int jobStart = -1;
        string name; 
    public:
        Webserver(){
        }
        Webserver(string name){
            this->name = name;
        }
        void setName(string name){
            this->name = name;
        }
        string getName(){
            return name;
        }
        int getjobStart(){
            return jobStart;
        }
        bool isJobDone(int currentTime){
            if(jobStart == -1){
                return true;
            }
            cout << this->getName() << " jobendTime: "<< jobStart+request.jobTime << " currenttime: " << currentTime << endl;
            if((jobStart+request.jobTime) < currentTime)   {
                return true;
            }
            return false;
        }
        void setRequest(int currentTime, Request request){
            this->jobStart = currentTime;
            this->request = request;
        }
        Request getRequest(){
            return request;
        }

};

#endif