#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

ifstream input;
ofstream output;

int main(int argc, char *argv[]){
    pid_t pid;
    pid=fork();
    
    if (pid<0) {
        cout<<"Error! Unable to fork."<<endl;
        return 1;
    }
    
    if (pid==0){    
       
        cout<<"Child Process"<<endl;
       execl("MyCompress",NULL);
            
    }

    else {

        cout<<"Parent Process"<<endl;

        int status = 0;
		wait(&status);
        
        cout<<"compress complete";

        
        return status;
        
    }

    return 0 ;

}
 
