#include <stdio.h>
#include <iostream>
using namespace std;

struct Car{
    float gas;
    float gasMax;
    float km;
    int pass;
    int passMax;

    Car(int eGasMax, int ePassMax){
        gas = 0;
        gasMax = eGasMax;
        pass = 0;
        passMax = ePassMax;
        km = 0;
    }

    void show(){
        cout << "pass: " << pass << "   gas: " << gas << "  km: " << km << "\n";
    }

    void fuel(int abastecer){
        if(gas + abastecer <= gasMax)
            gas += abastecer;
        else
            gas = gasMax;

        cout << "done\n";
    }

    bool in(){
        if(pass + 1 <= passMax){
            pass += 1;
            cout << "done\n";
            return true;
        }else{
            cout << "fail: limite de pessoas atingido\n";
            return false;
        }
    }

     bool out(){
        if(pass != 0){
            pass -= 1;
            cout << "done\n";
            return true;
        }else{
            cout << "fail: nao ha ninguem no carro\n";
            return false;
        }
    }   

    bool drive(float distancia){
        if(pass != 0){
            if(gas-(distancia/10) > 0){
                km += distancia;
                gas -= distancia/10;
            }else{
                cout << "fail: gasolina insuficiente\n";
                return false;
            }
            cout << "done\n";
            return true;
        }else{
            cout << "fail: nao ha ninguem no carro\n";
            return false;
        }
    }
};

int main()
{
    Car carro(10, 2);
    string op;
    while(true){
        cin >> op;
        if(op == "help"){
            puts("show; fuel _a; in; out; drive _a; fim");
        }else if(op == "show"){
            carro.show();
        }else if(op == "fuel"){
            int a;
            puts("Quanto voce quer de combustivel? ");
            scanf("%d", &a);
            carro.fuel(a);
        }else if(op == "in"){
            carro.in();
        }else if(op == "out"){
            carro.out();
        }else if(op == "drive"){
            float a;
            puts("Quantos KM voce quer andar? ");
            scanf("%f", &a);
            carro.drive(a);
        }else if(op == "fim"){
            break;
        }
    }
    return 0;
}
