#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]){

    if (argc<3) {
   cout<<"ERROR: Too few arguments. Usage: ./ForkCompress source destination\n"<<endl;
   return 1 ;
}
    pid_t pid;
    pid=fork();
    
    if (pid<0) {
        cout<<"Error! Unable to fork."<<endl;
        return 1;
    }
    
    if (pid==0){    
       
        cout<<"Child Process"<<endl;
        execl("../Problem 1/MyCompress",argv[0], argv[1], argv[2], NULL);
            
    }

    else {

        cout<<"Parent Process"<<endl;

        
        wait(NULL);
        
        
        cout<<"compress complete"<<endl;
       
        
    }

    return 0 ;

}
 
