#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){

    //Showing the files in this path
   // execl("/bin/ls", "ls", "-l",0);

    pid_t pid;

    //Forking a process
    pid = fork();

    // Check fork failed
    if(pid < 0){
        cout << "Fork failed";
        return 1;
    }
    //Child Process
    else if (pid == 0){
        //Passing souce.txt and destination.txt
        execl("../problem1/MyCompress" , argv[0], "source.txt", "destination.txt", NULL);
    }
    //Parent Process
    else{
        wait(NULL);
        cout << "Complete.";
    }

    return 0;

    

}