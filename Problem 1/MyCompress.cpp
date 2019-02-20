#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main (int argc, char *argv[]){


if (argc<3) {
   cout<<"ERROR: Too few arguments. Usage: ./MyCompress source destination\n"<<endl;
   return 1 ;
}

ifstream input;
ofstream output;
input.open(argv[1]);
if(input == NULL) {
		cout<<"Unable to find file "<<argv[1]<<endl;
		return 1;
	}

output.open(argv[2]);

//Create buffer for input data.
//reading the data from txt file

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



cout<<"\nThe file has been compressed."<<endl;

return 0 ;

    
}
