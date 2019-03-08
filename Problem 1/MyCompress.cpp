#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

//for the time part
#include <chrono>
#include <ctime>


using namespace std;

int main (int argc, char *argv[]){


if (argc<3) {
   cout<<"ERROR: Too few arguments. Usage: ./MyCompress source destination\n"<<endl;
   return 1 ;
}
auto start = chrono::system_clock::now();//get the start time 

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
                
                 output<<contents[i];
            }
           counter=1;
            
        }
        else
        {   
            if (contents[i]=='0') {
                
                output<<"-"<<counter<<"-";
            }
            else
            {
                
                output<<"+"<<counter<<"+";
            }
         counter=1;
        }       
    }   
 }

input.close();
output.close();

cout<<"\nThe file has been compressed."<<"\n"<<endl;

auto end = chrono::system_clock::now();//get the time when complete
chrono::duration<double> run_time_in_sec = end-start;//calculate run time
time_t end_time = chrono::system_clock::to_time_t(end);//get the end time
//cout << "Finish at " << ctime(&end_time)<<endl;//print end time
cout << "Run  time: " << run_time_in_sec.count() << "s\n"<<endl;//print run time

return 0 ;

    
}
