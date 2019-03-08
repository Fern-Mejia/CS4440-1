#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

	int main(int argc, char *argv[])
	{
         if (argc != 3)
         {
         cout<<"ERROR: Need to have three arguments . Usage: ./PipeCompress <inputfilename> <outputfilename>\n"<<endl;
         return 1 ;
         }
        
		int pid, pip[2];
		char instring[100];        
        ifstream input;
        ofstream output;
        string buffer;

		pipe(pip); 

		pid = fork();
        if (pid<0) {
            cout<<"fork error!"<<endl;
            return 1;
        }
        
		if (pid == 0)           
		{
	
    input.open(argv[1]);
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
                 //cout<<contents[i];
                 buffer += contents[i];
            }
           counter=1;
            
        }
        else
        {   
            if (contents[i]=='0') {
                //cout<<"-"<<counter<<"-";
                buffer.append("-");
                buffer.append(to_string(counter));
                buffer.append("-") ;
                
            }
            else
            {
               // cout<<"+"<<counter<<"+";
                buffer.append("+");
                buffer.append(to_string(counter));
                buffer.append("+") ;
            }
         counter=1;
        }       
    }   
     }      
        //write-end for the pipe
        int buffer_length = buffer.length(); //this is how length of your data.
        close(pip[0]);
		write(pip[1], buffer.c_str(), buffer_length);  //write through the pipe 
        close(pip[1]);
	}
		
        
        
        else			/* parent : receives message from child */
		{
             output.open(argv[2]);
			/* read from the pipe */
            close(pip[1]);
			
           int n;
           while( (n = read(pip[0], instring, 1))>0){//Iterator all numbers in pipe 
               for(int i = 0; i < n; i++)
               {
                  
                   output<<instring[i];//write the result to the output file
               }
               
           }

            close(pip[0]);      
            wait(NULL);
            
             
             
		}    
        return EXIT_SUCCESS ; 
    }