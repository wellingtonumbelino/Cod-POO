#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
static int proxIndice;
class Fone{
public:
    int indice;
    string id;
    string fone;
    Fone(string id = "", string fone = ""):
        id(id), fone(fone), indice(proxIndice)
    {
    }

    string toString(){
        stringstream ss;
        ss << "[" << indice << ":" << id << ":" << fone << "]";
        return ss.str();
    }
};

class Contato{
private:
    string id;
    vector<Fone> fones;
public:
    Contato(string id = "Vazio"):
        id(id)
    {
    }

    bool validate(string s){
        string valida = "0123456789().";
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < valida.size(); j++){
                if(s[i] == valida[j] ){
                    return true;
                }
            }
        }
        cout << "failure: caracteres invalidos" << endl;
        return false;
    }

    bool add(Fone fone){
        if(validate(fone.fone) == true){
            for(auto telefone : fones)
                if(telefone.fone == fone.fone){
                    cout << "failure: numero duplicado";
                    return false;
                }
            fones.push_back(fone);
            proxIndice ++;
            return true;
        }
        return false;
    }

    bool rm(int foneId){
        for(int i = 0; i < (int) fones.size(); i++){
            if(fones[i].indice == foneId){
                fones.erase(fones.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool update(string entrada){
        string fones[] = entrada.split(" ");
        for(auto fone : fones){
            cout << fone << endl;
        }
    }

    string toString(){
        stringstream ss;
        ss << id << "=>";
        for(auto fone : fones)
            ss << fone.toString();
        return ss.str();
    }
};

struct Controller{
    Contato cont;

    string shell(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "help")
            out << "show; init _nome; add _id _fone; end";
        else if(op == "init"){
            string nome;
            in >> nome;
            cont = Contato(nome);
            out << "success";
        }else if(op == "show"){
            out << cont.toString();
        }else if(op == "add"){
            string id, fone;
            in >> id >> fone;
            cont.add(Fone(id, fone));
        }else if(op == "rm"){
            int id;
            in >> id;
            cont.rm(id);
        }
        return out.str();
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end")
                break;
            cout << "  " << shell(line) << endl;
        }
    }
};

int main(){
    Controller controller;
    controller.exec();
    return 0;
}