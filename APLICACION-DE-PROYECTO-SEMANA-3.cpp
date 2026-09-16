#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int prioridad(char operador)
{
    if (operador == '+' || operador == '-')
        return 1;
    if (operador == '*' || operador == '/')
        return 2;
    if (operador == '^')
        return 3;
    return 0;
}

bool esOperador(char caracter)
{
    return caracter == '+' || caracter == '-' ||
           caracter == '*' || caracter == '/' ||
           caracter == '^';
}

int main()
{
    string infija, postfija;
    stack<char> operadores;

    cout << "Porfavor Ingrese la expresion infija que desea Convertir a postfija: ";
    getline(cin, infija);

    for (char caracter : infija)
    {
        // Ignorar espacios
        if (isspace(caracter))
        {
            continue;
        }

        // Si es operando: letras o numeros
        if (isalnum(caracter))
        {
            postfija += caracter;
            postfija += ' ';
        }
        // Abrir parentesis
        else if (caracter == '(')
        {
            operadores.push(caracter);
        }
        // Cerrar parentesis
        else if (caracter == ')')
        {
            while (!operadores.empty() && operadores.top() != '(')
            {
                postfija += operadores.top();
                postfija += ' ';
                operadores.pop();
            }

            if (!operadores.empty())
            {
                operadores.pop(); // Elimina '('
            }
        }
        // Operadores
        else if (esOperador(caracter))
        {
            while (!operadores.empty() &&
                   operadores.top() != '(' &&
                   prioridad(operadores.top()) >= prioridad(caracter))
            {
                postfija += operadores.top();
                postfija += ' ';
                operadores.pop();
            }

            operadores.push(caracter);
        }
    }

    // Vaciar los operadores pendientes
    while (!operadores.empty())
    {
        if (operadores.top() != '(')
        {
            postfija += operadores.top();
            postfija += ' ';
        }
        operadores.pop();
    }

    cout << "\nEl Resultado de la Expresion postfija es: " << postfija << endl;

    return 0;
}