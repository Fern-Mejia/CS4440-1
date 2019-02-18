#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream input; // file input
ofstream output; // file output

int main(int argc, char *argv[]){

    //Open source file
    input.open("source.txt");
    
    //Check to see if input file can't be opened
    if(input.fail()){
        cerr << "Can't open tabledata\n";
        return 1;
    }

    //Open desitination file
    output.open("destination.txt");
    // Read data from input file
    string buffer; //Stores data temporarily
    while(input.is_open()){ // Checking if file is open - returns boolean
        //Reads file line by line and store inside buffer. 
        getline(input, buffer);
        //Close file 
        input.close();
    }

    //Compress file 
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
                    output<<buffer[i];
                }
            counter=1;
                
            }
            else
            {   
                if (buffer[i]=='0') {
                    cout<<"-"<<counter<<"-";
                    output<<"-"<<counter<<"-";
                }
                else
                {
                    cout<<"+"<<counter<<"+";
                    output<<"+"<<counter<<"+";
                }
            counter=1;
            }       
        }   
    }

    cout << " File has been compressed.";
    
}