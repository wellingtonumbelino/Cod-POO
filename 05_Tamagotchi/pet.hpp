#ifndef PET_H
#define PET_H

#include <iostream>
#include <sstream>
using namespace std;

class Pet{
private:
    string nome;
    int energyMax, hungryMax, cleanMax; 
    int energy, hungry, clean;   
    int age; // {0};
    int diamond; // {0};
    bool alive {true};


public:
    Pet(string nome = "pet", int energyMax = 0, int hungryMax = 0, int cleanMax = 0);
    
    string getNome();  //declaracao
    void setNome(string nome){
        this->nome = nome;
    }
    int getEnergyMax(){
        return energyMax;
    }
    int getHungryMax(){
        return hungryMax;
    }
    int getCleanMax(){
        return cleanMax;
    }
    int getAge();

    string toString(){
        stringstream ss;
        ss << "N:" << nome << ", " 
           << "E:" << energy << "/" << energyMax << ", "
           << "H:" << hungry << "/" << hungryMax << ", "
           << "C:" << clean  << "/" << cleanMax  << ", "
           << "D:" << diamond << ", A:" << age;
        return ss.str();
    }

    void setEnergy(int value){
        if(value <= 0){
            this->alive = false;
            energy = 0;
        }else if(value > energyMax){
            energyMax = energyMax;
        }else
            energy = value;
    }

    void setHungry(int value){
        if(value <= 0){
            this->alive = false;
            hungry = 0;
        }else if(value >= hungryMax){
            hungry = hungryMax;
        }else
            hungry = value;
    }

    void setClean(int value){
        if(value <= 0){
            this->alive = false;
            clean = 0;
        }else if(value >= cleanMax){
            clean = cleanMax;
        }else
            clean = value;
    }

    void setAge(int value){
        if(value <= 0){
            this->alive = false;
            age = 0;
        }else
            age = value;
    }

    void setDiamond(int value){
        if(value <= 0){
            this->alive = false;
            value = 0;
        }else
            diamond = value;
    }

    bool testAlive(){
        if(energy <= 0){
            cout << "fail: pet esta morto!" << endl;
            return false;
        }else if(hungry <= 0){
            cout << "fail: pet morreu de fome!" << endl;
            return false;
        }else if(clean <= 0){
            cout << "fail: pet morreu!" << endl;
            return false;
        }
        return true;
    }

    void play(){
        if(!testAlive())
            return;
        setEnergy(energy - 2);
        setHungry(hungry - 1);
        setClean(clean - 3);
        setAge(age + 1);
        setDiamond(diamond + 1);
    }

    void eat(){
        if(!testAlive())
            return;
        setEnergy(energy - 1);
        setHungry(hungry + 4);
        setClean(clean - 2);
        setAge(age + 1);
    }


    void sleep(){
        int dif = energyMax - energy;
        setEnergy(energy + (int) dif);
        setHungry(hungry - 1);
        setAge(age + (int) dif);
    }

    void shower(){
        int dif;
        dif = cleanMax - clean;
        setEnergy(energy - 3);
        setHungry(hungry - 1);
        setClean(clean + (int) dif);
        (age + 2);
    }

};
#endif