#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;

struct Pass{
    string nome;
    int idade;
    string tipo;
    bool existe;

    Pass(string nome = "fulano", int idade = 0){
        this->nome = nome;
        this->idade = idade;
        this->existe = false;
        this->tipo = "#";
    }
    
    void setTipo(string tipo){
        this->tipo = tipo;
    }

    string toString(){
        stringstream ss;
        ss << this->tipo << this-> nome << ":" << this-> idade;
        return ss.str();
    }
};


struct Topic{
    int qtd;
    int qtdIdoso;
     vector<Pass*> passageiros;

    Topic(int qtd = 0, int qtdIdoso = 0){
        this-> qtd = qtd;
        this-> qtdIdoso = qtdIdoso;
        for(int i = 0; i < qtd; i++){
            Pass * passageiro = new Pass("",0);
            passageiros.push_back(passageiro);
        }
        for(int i = 0; i < qtdIdoso; i++){
            passageiros[i]->setTipo("@");
        }
    }

    string toString(){
        stringstream ss;
        ss << "[";
        for(Pass * passageiro : passageiros){
            if(passageiro->existe){
                ss << " " << passageiro->toString() << " ";
            }else{
                ss << " " << passageiro->tipo << " ";
            }
        }
        ss << "]";
        return ss.str();
    }

    bool novo(Pass * passageiro){
       for(Pass * pass : passageiros){
           if(pass == nullptr){
               passageiros.push_back(passageiro);
               return true;
           }
       }
    }

    bool in(string nome, int idade){
        Pass * passageiro = new Pass(nome, idade);
        if(this->qtd == 0 && this->qtdIdoso == 0){
            puts("fail: topic nao inicializada!");
            return false;
        }
        if(idade > 60){
            for(int i = 0; i < qtdIdoso; i++){
                if(!passageiros[i]->existe){
                    passageiros[i] = passageiro;
                    passageiro->setTipo("@");
                    passageiro->existe = true;
                    cout << "done" << endl;
                    return true;
                }else{
                    if(passageiros[i]->nome == passageiro->nome){
                        cout << "fail: " << passageiro->nome << " ja esta na topic" << endl;
                        return false;
                    }
                }
            }
            for(int i = qtdIdoso; i < qtd; i++){
                if(!passageiros[i]->existe){
                    passageiros[i] = passageiro;
                    passageiro->existe = true;
                    cout << "done" << endl;
                    return true;
                }else{
                    if(passageiros[i]->nome == passageiro->nome){
                        cout << "fail: " << passageiro->nome << " ja esta na topic" << endl;
                        return false;
                    }
                }
            }
            cout << "fail: topic lotada" << endl;
            return false;
        }else{
            for(int i = qtdIdoso; i < qtd; i++){
                if(!passageiros[i]->existe){
                    passageiros[i] = passageiro;
                    passageiro->existe = true;
                    cout << "done" << endl;
                    return true;
                }else{
                    if(passageiros[i]->nome == passageiro->nome){
                        cout << "fail: " << passageiro->nome << " ja esta na topic" << endl;
                        return false;
                    }
                }
            }
            for(int i = 0; i < qtdIdoso; i++){
                if(!passageiros[i]->existe){
                    passageiros[i] = passageiro;
                    passageiro->setTipo("@");
                    passageiro->existe = true;
                    cout << "done" << endl;
                    return true;
                }else{
                    if(passageiros[i]->nome == passageiro->nome){
                        cout << "fail: " << passageiro->nome << " ja esta na topic" << endl;
                        return false;
                    }
                }
            }
            cout << "fail: topic lotada" << endl;
            return false;
        }
    }

    bool out(string nome){
        for(int i = 0; i < qtd; i++){
            if(passageiros[i]->existe && passageiros[i]->nome == nome){
                delete passageiros[i];
                passageiros[i] = nullptr;
                cout << "done" << endl;
                return true;
            }
        }
        cout << "fail: " << nome << " nao esta na topic" << endl;
        return false;
    }
};

int main()
{
    Topic topic;
    string op;
    while(true){
        cin >> op;
        if(op == "new"){
            int total, idoso;
            cin >> total >> idoso;
            topic = Topic(total, idoso);
            cout << "done" << endl;
        }else if(op == "show"){
            cout << topic.toString() << endl;
        }else if(op == "in"){
            string nome;
            int idade;
            cin >> nome >> idade;
            topic.in(nome, idade);
        }else if(op == "out"){
            string nome;
            cin >> nome;
            topic.out(nome);
        }else if(op == "end"){
            break;
        }
    }
    return 0;
}
