/*****************************************************************************************************************
 * PROGRAM NAME	:	ParFork.c

 * DESCRIPTION	:	Using Pipe to Compress.
 
 * EXECUTION	:	./ParFork <Input File> <Output File>
 ******************************************************************************************************************/


#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char *argv[]){

    if (argc != 3) {
   cout<<"ERROR: Need to have three arguments . Usage: ./PipeCompress <inputfilename> <outputfilename>\n"<<endl;
   return 1 ;
    }

    int pipe (int Pipefd[2]);

    pid_t pid;
    pid=fork();
    
     string buffer_1;


    if (pid<0) {
        cout<<"\nERROR, Fork Failed"<<endl;
    }
    char buff;
    //Child Processs
    if (pid==0){    
            close(pipefd[1]);
            int pidC=getppid();
            cout<<"\nChildren Process";
            cout<<"\nPid = "<< pidC<<endl;
            
            while (read(Pipefd[0],&buffer_1)>0){

            };




        
        
    }
    //Parent Process
    else {
        int pidP = getppid() ;
        cout<<"Parent Process"<<endl;
         cout<<"Pid = "<< pidP<<endl;


         close(pipefd[0]);

    //begining Compress
        void MyCompress(char *argv[]);

    write(Pipefd[0], buffer_1,512);

        wait(NULL);


            
    }
    return 0 ;

}









void MyCompress(int argc, char *argv[]){

    ifstream input;
   // ofstream output;

    string buffer;
   

    input.open(argv[1]);

    while(input.is_open()){

    getline(input,buffer);
    
 
    input.close();
}

    //starting Compress
int counter;
for(int i=0;i<buffer.length();i++){
    if (buffer[i]==buffer[i+1]) {
        counter++;       
    }
    else
    {
        if (counter<16) {
         for(int j = 0 ; j < counter; j++)
            {
                 cout<<buffer[i];
                 buffer_1.append("buffer[i]");
            }
           counter=1;
            
        }
        else
        {   
            if (buffer[i]=='0') {
                cout<<"-"<<counter<<"-";
                buffer_1.append("-","counter");
            }
            else
            {
                cout<<"+"<<counter<<"+";
                buffer_1.append("counter");
            }
         counter=1;
        }       
    }   
 }
cout<<"\nThe file has been compressed."<<endl;


    

}
