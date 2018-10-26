#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Aluno{
private:
    int matricula;
    string nome;
    string curso;
public:
    Aluno(int matricula, string nome, string curso){
        this->matricula = matricula;
        this->nome = nome;
        this->curso = curso;
    }

    int getMatricula(){
        return this->matricula;
    }

    void setMatricula(int matricula){
        this->matricula = matricula;
    }

    string getNome(){
        return this->nome;
    }

    void setNome(string nome){
        this->nome = nome;
    }

    string getCurso(){
        return this->curso;
    }

    string toString(){
        return "Matricula: " + to_string(matricula) + " Nome: " + this->nome + " Curso: " + this->curso;
    }
};


class Professor{
private:
    int nivel;
    string nome;
    string siap;
public:
    Professor(int nivel, string nome){
        this->nivel = nivel;
        this->nome = nome;
    }

    int getNivel(){
        return this->nivel;
    }

    string getNome(string nome){
        return this->nome = nome;
    }

    string toString(){
        return "Nivel: " + to_string(nivel) + " Nome: " + this->nome + " Siap: " + this->siap; 
    }
};

class Disciplina{
private:
    string codigo;
    string curso;
    string nome;
public:
    Disciplina(string codigo, string curso, string nome){
        this->codigo = codigo;
        this->curso = curso;
        this->nome = nome;
    }

    string getCodigo(){
        return this->codigo;
    }

    string getCurso(){
        return this->curso;
    }

    string getNome(){
        return this->nome;
    }

    string toString(){
        return "Codigo: " + this->codigo + "Curso: " + this->curso + "Nome: " + this->nome;
    }
};

class Repositorio{
private:
    vector<Aluno> alunos;
    vector<Professor> professores;
    vector<Disciplina> disciplinas;
public:

    bool addAlu(Aluno a){
        for(Aluno aluno : alunos){
            if(aluno.getMatricula() == a.getMatricula()){
                throw "fail: Matricula existente";
            }
        }
        alunos.push_back(a);
        cout << "success" << endl;
        return true;
    }

    bool addPro(Professor p){
        for(Professor professor : professores){
            if(professor.getNivel() == p.getNivel()){
                throw "fail: O nivel do professor ja existe!";
            }
        }
        professores.push_back(p);
        return true;
    }

    bool addDis(Disciplina d){
        for(Disciplina disciplina : disciplinas){
            if(disciplina.getCodigo() == d.getCodigo()){
                throw "fail: O nivel do professor ja existe!";
            }
        }
        disciplinas.push_back(d);
        return true;
    }


    //busca == get
    Aluno buscaAluno(int matricula){
        for(Aluno aluno : alunos){
            if(aluno.getMatricula() == matricula){
                return aluno;
            }
        }
        throw "fail: matricula nao encontrada!";
    }

    Professor buscaProfessor(int nivel){
        for(Professor professor : professores){
            if(professor.getNivel() == nivel){
                return professor;
            }
        }
        throw "fail: O nivel do professor nao foi encontrado!";
    }

    Disciplina buscaDisciplina(string codigo){
        for(Disciplina disciplina : disciplinas){
            if(disciplina.getCodigo() ==  codigo){
                return disciplina;
            }
        }
        throw "fail: o codigo da disciplina nao foi encontrado";
    }

    bool rmAluno(int matricula){
        for(int i = 0; i < (int)alunos.size(); i++){
            if(alunos[i].getMatricula() == matricula){
                alunos.erase(alunos.begin() + i);
                puts("done");
                return true;
            }
        }
        throw "fail: matricula nao encontrada!";
    }

    bool rmProfessor(int nivel){
        for(int i = 0; i < (int)professores.size(); i++){
            if(professores[i].getNivel() == nivel){
                professores.erase(professores.begin() + i);
                puts("done");
                return true;
            }
        }
        throw "fail: nivel nao encontrado!";
    }

    bool rmDisciplina(string codigo){
        for(int i = 0; i < (int)disciplinas.size(); i++){
            if(disciplinas[i].getCodigo() == codigo){
                disciplinas.erase(disciplinas.begin() + i);
                puts("done");
                return true;
            }
        }
        throw "fail: codigo nao encontrado!";
    }

    void showAlunos(){
        for(Aluno aluno : alunos)
            cout << aluno.toString() << endl;
    }

    void showPro(){
        for(Professor professor : professores)
            cout << professor.toString() << endl;
    }

    void showDis(){
        for(Disciplina disciplina : disciplinas)
            cout << disciplina.toString() << endl;
    }
};

int main(){
    Repositorio rep;
    string op;
    while(true){
    cin >> op;
        if(op == "addAlu"){
            int matricula;
            string nome;
            string curso;
            cin >> matricula >> nome >> curso;
            try{
                rep.addAlu(Aluno(matricula,nome,curso));
            }catch(const char * e){
                cout << e << endl;
            }
        }else if(op == "addDis"){
            string codigo, curso, nome;
            cin >> codigo >> curso >> nome;
            try{
                rep.addDis(Disciplina(codigo, curso, nome));
            }catch(const char * e){
                cout << e << endl;
            }
        }else if(op == "addPro"){
            int nivel;
            string nome;
            cin >> nivel >> nome;
            try{
                rep.addPro(Professor(nivel, nome));
            }catch(const char * e){
                cout << e << endl;
            }
        }else if(op == "showAlu"){
            rep.showAlunos();
        }else if(op == "rmAlu"){
            int matricula;
            cin >> matricula;
            try{
                rep.rmAluno(matricula);
            }catch(const char * e){
                cout << e << endl;
            }
        }else if(op == "rmPro"){
            int nivel;
            cin >> nivel;
            try{
                rep.rmProfessor(nivel);
            }catch(const char * e){
                cout << e << endl;
            }
        }else if(op == "rmDis"){
            string codigo;
            cin >> codigo;
            try{
                rep.rmDisciplina(codigo);
            }catch(const char * e){
                cout << e << endl;
            }
        }else if(op == "getAlu"){
            int matricula;
            cin >> matricula;
            try{
                cout << rep.buscaAluno(matricula).toString() << endl;
            }catch(const char * e){
                cout << e << endl;
            } 
        }else if(op == "showPro"){
            rep.showPro();
        }else if(op == "getPro"){
            int nivel;
            cin >> nivel;
            try{
                cout << rep.buscaProfessor(nivel).toString() << endl;
            }catch(const char * e){
                cout << e << endl;
            } 
        }else if(op == "showDis"){
            rep.showDis();
        }else if(op == "getDis"){
            string codigo;
            cin >> codigo;
            try{
                cout << rep.buscaDisciplina(codigo).toString() << endl;
            }catch(const char * e){
                cout << e << endl;
            } 
        }
    }
    return 0;
}