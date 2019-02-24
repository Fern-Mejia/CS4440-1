#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
//for the time part
#include <chrono>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]){

    if (argc<3) {
   cout<<"ERROR: Too few arguments. Usage: ./ForkCompress <inputfilename> <outputfilename>\n"<<endl;
   return 1 ;
}
    auto start = chrono::system_clock::now();//get the start time 
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


auto end = chrono::system_clock::now();//get the time when complete
chrono::duration<double> run_time_in_sec = end-start;//calculate run time
time_t end_time = chrono::system_clock::to_time_t(end);//get the end time
cout << "\nFinish at " << ctime(&end_time)<<endl;//print end time
cout << "Run  time: " << run_time_in_sec.count() << "s\n"<<endl;//print run time


return 0 ;

}
 
