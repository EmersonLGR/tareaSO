//Emerson Garcia Rios

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

//intento de funcion que hace ping a las ip  dando como resultado toda la fila 4 en donde se encuentran los datos importantes exportandolos a un txt 
void d_ping(string ips){
    
    string ping = "ping -q -c2 " + ips + " awk 'NR==4 {print $n}' > resultado_ping.txt";
    system (ping.c_str());
}


//intento de funcion que lee el archivo, luego almacena la cadena en una variable 
void r_archivo(string arch){
    string line;
    vector<string> ips;

   int i = 1;

    ifstream myfile(arch);
    if (myfile.is_open()){
        while (getline(myfile,line)){
            ips.push_back(line);
 
            i++;
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }

  //aqui se implementan las hebras mediante la lectura del archivo 
     thread threads[ips.size()];

    for (i=0; i < ips.size(); i++) {
        threads[i] = thread(d_ping, ips[i]);
    }

    
    for (i=0; i< ips.size(); i++) {
        threads[i].join();
    }
  
}

int main(int argc, char** args) {
    
    string arch_ip = args[0];
    r_archivo(arch_ip);
    
}
