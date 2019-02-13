#include <iostream>
#include <fstream>
#include <string>

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
string buffer;
//reading the data from txt file
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
cout<<"\nThe file has been compressed."<<endl;

return 0 ;

    
}

