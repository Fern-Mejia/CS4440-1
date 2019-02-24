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
#include <cctype>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char *argv[]){

    if (argc != 3) {
   cout<<"ERROR: Need to have three arguments . Usage: ./PipeCompress <inputfilename> <outputfilename>\n"<<endl;
   return 1 ;
    }

   int pipefd[2];  //Create Pipe here.
    
    pid_t pid;  //Create Fork here.
    pid=fork();
    int Rel;

    char readbuffer[80];
    char writebuffer[80];
    string buffer;
    
    ifstream input;
    ofstream output;
    
    input.open(argv[1]);
    output.open(argv[2]);
    

    if (pid<0) {
        cout<<"\nERROR, Fork Failed"<<endl;
    }

    //Child Processs
    else if (pid==0){
        
        
        close(pipefd[0]);
        
        string s;
        char ch;
      read(pipefd[1],&ch,128);
           
        cout<<s;
        output<<s;
        cout<<ch;
        output<<ch;
        
           
    }
    //Parent Process
    else {
    stringstream buff;
    buff<< input.rdbuf();
    string contents(buff.str());
    

//starting Compress
int counter=1;
for(int i=0;i<contents.length();i++){
    
    if (contents[i]==contents[i+1]) {
        counter++;       
    }
    
    
    else
    {
        if (counter<16) {
         for(int j = 0 ; j < counter; j++)
            {
                 cout<<contents[i];
                 buffer += contents[i];
            }
           counter=1;
            
        }
        else
        {   
            if (contents[i]=='0') {
                cout<<"-"<<counter<<"-";
                buffer.append("-");
                buffer.append(to_string(counter));
                buffer.append("-") ;
                
            }
            else
            {
                cout<<"+"<<counter<<"+";
                buffer.append("+");
                buffer.append(to_string(counter));
                buffer.append("+") ;
            }
         counter=1;
        }       
    }   
 }
//compress complete
   

    
    //start pipe
    close(pipefd[1]);
    
    write(pipefd[0],buffer.c_str(),buffer.length()+1);

    wait(NULL);
    //waitpid(pid,NULL,0);
  
       
    }

    
    return 0 ;

}


