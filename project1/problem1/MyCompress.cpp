#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>


using namespace std;

int main(int argc, char *argv[]){

    ifstream input; // file input
    ofstream output; // file output

   
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
    stringstream buff; //Stores data temporarily
    buff << input.rdbuf();
    string contents(buff.str());

    //Compress file 
    int counter = 1;
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
                    output<<contents[i];
                }
            counter=1;
                
            }
            else
            {   
                if (contents[i]=='0') {
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
    return 0;
}