#include <iostream>
#include <string>
#include <stack>

using namespace std;

class ConversorPostfix {
public:
    int prioridad(char operador) {
        if (operador == '+' || operador == '-')
            return 1;

        if (operador == '*' || operador == '/')
            return 2;

        return 0;
    }

    bool esOperador(char caracter) {
        return caracter == '+' || caracter == '-' ||
               caracter == '*' || caracter == '/';
    }
}; int main() {
    ConversorPostfix conversor;

    cout << "Prioridad de +: " << conversor.prioridad('+') << endl;
    cout << "Prioridad de *: " << conversor.prioridad('*') << endl;

    return 0;
}