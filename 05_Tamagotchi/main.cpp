#include <iostream>
#include <sstream>
#include "pet.hpp"
using namespace std;

struct Controller{
    Pet p;
    string shell(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "init"){
            string nome;
            int eMax;
            int hMax;
            int cMax;
            in >> nome >> eMax >> hMax >> cMax;
            p = Pet(nome, eMax, hMax, cMax);
        }else if(op == "play"){
            p.play();
        }else if(op == "eat"){
            p.eat();
        }else if(op == "clean"){
            p.shower();
        }else if(op == "show"){
            out << p.toString() << endl;
        }else if(op == "sleep"){
            p.sleep();
        }
        return out.str();
    }

    void io(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end")
                return;
            cout << "   " << shell(line) << endl;
        }
    }
};

int main(){
    puts("Atribua um nome ao seu pet - passe também quantidade máxima de ENERGY, HUNGRY e CLEAN.");
    Controller c;
    c.io();
    return 0;
}