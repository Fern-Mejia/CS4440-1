
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define BUFFER_SIZE 10;

using namespace std;


int main(){
    int pipe (int pipefd[2]);

    pid_t pid;
    pid=fork();
    

char buffer;

     //Children Process 
   
    
    if (pid==0){    

      int pidC=getppid();
            cout<<"\n Children Process";
            cout<<"\n Pid = "<< pidC;
            ssize_t write (int pipe[0]);

        
        
    }
    //Parent Process
    else {
        int pidP = getppid() ;
        cout<<"Parent Process"<<endl;
         cout<<"Pid = "<< pidP;
        ssize_t read (int pipe[1]);

            
    }
    return 0 ;
    


}