#include<stdlib.h>
#include<stdio.h>


string command = "ping -q -c2 192.168.10.100 | awk 'NR==4 {print $1, $4}' > ping_result.txt";
    system (command.c_str());

    string line;
    ifstream myfile("ping_result.txt");
    if (myfile.is_open()){
        getline(myfile,line);
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }

int main ()
{


return 0;
}
