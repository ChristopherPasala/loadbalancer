#ifndef Webserver_H
#define Webserver_H
#include "Request.h"

/**
 * @brief Represents the Webserver object which processes a Request
 * 
 */
class Webserver{
    private:
        shared_ptr<Request> request;

        //signify no job currently in intial state
        int jobStart =-1;
        
        //for keeping track of which webserver is which
        string name;

        //used to determine if Webserver object has already finished or not
        bool finished = true;
    public:
        /**
         * @brief Default constructor
         * 
         */
        Webserver(){
        }
        /**
         * @brief Overwritten constructor for naming a new Webserver object
         * 
         * @param name 
         */
        Webserver(string name){
            this->name = name;
        }
        /**
         * @brief Set the name of the Webserver object
         * 
         * @param name 
         */
        void setName(string name){
            this->name = name;
        }
        /**
         * @brief Returns the state of whether the Webserver object is finished working on the Request object or not
         * 
         * @return true 
         * @return false 
         */
        bool getFinished(){
            return finished;
        }
        /**
         * @brief Set the state of whether the Webserver object is finished working on the request or not
         * 
         * @param val 
         */
        void setFinished(bool val){
            finished = val;
        }
        /**
         * @brief Get the Name of Webserver object
         * 
         * @return string 
         */
        string getName(){
            return name;
        }
        /**
         * @brief Get the time at which the Request object started to be process by the Webserver
         * 
         * @return int 
         */
        int getjobStart(){
            return jobStart;
        }
        /**
         * @brief Returns if the job being processed has finished
         * 
         * @param currentTime 
         * @return true 
         * @return false 
         */
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
        /**
         * @brief Assigns a Request object to be processed by a Webserver object
         * 
         * @param currentTime 
         * @param request 
         */
        void setRequest(int currentTime, shared_ptr<Request> request){
            this->jobStart = currentTime;
            this->request = request;
        }

        /**
         * @brief Get the Request object being processed
         * 
         * @return shared_ptr<Request> 
         */
       shared_ptr<Request> getRequest(){
            return request;
        }

};

#endif