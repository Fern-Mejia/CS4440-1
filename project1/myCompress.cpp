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

    // Read data from txt file
    string buffer;
    while(input.is_open()){ // Checking if file is open - returns boolean

        cout << "test";

        //Close file 
        input.close();
    }
}