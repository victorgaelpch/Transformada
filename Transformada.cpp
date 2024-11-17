#include <iostream>
#include <vector>
using namespace std;
class transformacion {

};

class punto {
    int x;
    int y;
    int b;
    int rango;
public:
 
    punto(int equiz,int ye) {
        this->x = equiz;
        this->y = ye;
        this->b = 0;
    }
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }

    int** calculoEcuacioneee(int** matriz,int rango) {
        for (int a = -rango; a <= rango; a++) {
            this->b = (-x * a) + y;
            cout << -x << " * " << a << " + " << y<<" = " <<b<< endl;
            if (this->b >= -rango && this->b <= rango) {
                //cout << this->b << ",";
                matriz[this->b+rango][a +  rango] += 1;
            }              
        }
        cout << endl;
        return matriz;    
    }

};

int main()
{
    vector<punto> puntos;
    int rango = 0;
    int imagen[5][5] = {
        {0,0,0,0,0},
        {1,1,0,0,0},
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0},
    };
    int imagenFinal[5][5] = { 0 };
    

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cout << " " << imagen[y][x];
            if (imagen[y][x] == 1) {
                puntos.emplace_back(x, y);
            }
        }
        cout << endl;
    }
    rango = 6;
    /*if (puntos.size() % 2 == 0) {
       rango = (puntos.size()/2)-1;
       cout << "rango: -" << rango<<" a "<<rango << endl;
    }
    else {
       rango = (puntos.size() / 2);
       cout << "rango: -" << rango << " a " << rango << endl;
    }*/
    int tamAcumuladora = rango + rango + 1;

    int** matrizAcumuladora = new int* [tamAcumuladora];
    for (int i = 0; i < tamAcumuladora; i++) {
        matrizAcumuladora[i] = new int[tamAcumuladora];
    }
    for (int i = 0; i < tamAcumuladora; i++) {
        for (int j = 0; j < tamAcumuladora; j++) {
            matrizAcumuladora[i][j] = 0;
        }
    }
    
    for (int i = 0; i < puntos.size(); i++){   
        cout << "x: " << puntos[i].getX() << " Y: " << puntos[i].getY() << endl;
    }
    for (int i = 0; i < puntos.size(); i++) {
        cout << "\n" << rango << "," << endl;
        matrizAcumuladora = puntos[i].calculoEcuacioneee(matrizAcumuladora,rango);
    }


    for (int i = -rango; i <= rango; i++) {
        for (int j = -rango; j <= rango; j++) {
            cout <<" " << matrizAcumuladora[i + rango][j + rango];
        }
        cout << endl;
    }

    int mayor = -1;
    int A = 0;
    int B = 0;
    for (int b = -rango; b <= rango; b++) {
        for (int a = -rango; a <= rango; a++) {
            if (matrizAcumuladora[b + rango][a + rango] > mayor) {
                mayor = matrizAcumuladora[b + rango][a + rango];
                A = a;
                B = b;
            }
        }
    }

    cout << "\nLa ecuacion final es: y=(" << A << ")x+(" << B << ")\n" << endl;

    for (int x = 0; x < 5;x++) {
        int y = A * x + B;
        imagenFinal[y][x] = 1;
    }

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cout <<" " << imagenFinal[y][x];
        }
        cout << endl;
    }
   
           

}

