#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

int main (int argc, char *argv[ ]){


if (argc<3) {
   cout<<"ERROR: Too few arguments. Usage: ./MyDecompress <inputfilename> <outputfilename>\n"<<endl;
   return 1 ;
}
ifstream input;
ofstream output;
input.open(argv[1]);
output.open(argv[2]);


cout<<"Starting Decompress"<<endl;

//Creating Buffer
stringstream buff;
buff<< input.rdbuf();
string buffer(buff.str());


//starting Decompress
int counter=0;
int element;
int n;
int k ;
string numbers;


for(int i=0;i<buffer.length();i++){
  if (buffer[i] == '-') {    
    do
     {
        numbers += buffer[i+1];
        i++;
     } while ( buffer[i]!='-');
      
     
     element=stoi(numbers);
     for(n=0;n<element;n++)
     {
       cout<<"0";
       output<<"0";
     }
     i++;
     numbers.clear();
     element=0;   
  }
   
    if (buffer[i] == '+') {      
     do
     {
        numbers += buffer[i+1];
        i++;
     } while (buffer[i]!='+');
     
     element=stoi(numbers);
     for( k=0;k<element;k++)
     {
       cout<<"1";
       output<<"1";
       
     }
      i++;
     numbers.clear();
     element = 0;

     }
   cout<<buffer[i];
   output<<buffer[i];


}

return 0 ;

output.close();

}