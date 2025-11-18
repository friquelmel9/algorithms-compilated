/*
Sebastián y Carlos son ayudantes del curso de Algoritmos y Complejidad en la UTFSM. Un día, 
mientras preparaban problemas para una ayudantía, Sebastián escribió la palabra "número". Sin 
embargo, a Carlos no le gustó esta elección, pues argumentó que había una palabra léxicográficamente 
menor (*): "cifra". Sebastián, molesto con el comentario, retó a Carlos a un duelo de palabras.

El duelo consiste en que cada uno escriba una palabra del largo que desee. Luego, ambos mostrarán 
sus palabras y las compararán. Ganará quien tenga la palabra léxicográficamente menor.

Sin embargo, Sebastián está tan enojado que, justo antes de revelar su palabra, intenta reordenar 
sus letras para asegurarse de ganar. Matías, otro ayudante del curso, observa el duelo y, 
en lugar de delatar a Sebastián por hacer trampa, se plantea una pregunta interesante: 
dado que conoce la palabra de Carlos, ¿es posible reordenar la palabra de Sebastián de 
manera que sea lexicográficamente menor?

(*) Dado un string a de longitud n y un string b de longitud m, se dice que a es 
lexicográficamente menor que b si:

a es un prefijo de b y n < m.
Existe un índice i tal que a[i] < b[i] y, para todo j < i, se cumple a[j] = b[j].

Ejemplos de comparación lexicográfica:
"hola" es lexicográficamente menor que "holaxd" porque "hola" es un prefijo de "holaxd" y tiene solo 4 caracteres, mientras que "holaxd" tiene 6.
"calabaza" es lexicográficamente menor que "calazaza" porque coinciden en los primeros 4 caracteres ("cala"), pero en la posición 5, "b" es menor que "z".
"hola" es lexicográficamente menor que "ahlo".
Input
La primera línea del input contiene un string que representa la palabra de Carlos.

La segunda línea del input contiene un string que representa la palabra de Sebastián.

Ambos strings estarán formados únicamente por letras minúsculas del alfabeto inglés, y la longitud de cada palabra será entre 1 y 105 caracteres. Es posible que las palabras no tengan la misma longitud.

Output
El output debe contener la palabra "Si", si es que Sebastián al cambiar el orden de las letras puede ganar. En caso contrario, debe contener la palabra "No".

Examples
InputCopy
numero
cifra
OutputCopy
Si
InputCopy
abcde
decab
OutputCopy
No
InputCopy
hola
hola
OutputCopy
Si
Note
En el primer caso, la palabra no necesita ser ordenada, la palabra "cifra" ya es lexicográficamente menor a "numero".

En el segundo caso, no existe ninguna forma de cambiar el orden de las letras del forma que Sebastián pueda ganar.

En el tercer caso, Sebastián puede haber ordenado de las letras de tal forma que la palabra sea "ahlo". Y "ahlo" es lexicográficamente menor a "hola".


@source: https://codeforces.com/group/wA0CSxKsVV/contest/568840/problem/C

*/




#include <bits/stdc++.h>
#include <string>
using ll = long long;
using ld = long double;
using namespace std;

bool compare(string a,string b) {
    int n = a.size();
    int m = b.size();
    if (n < m) {
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                return true;
            } else if (a[i] > b[i]) {
                return false;
            }
        }
        return true;
    } else {
        for (int i = 0; i < m; i++) {
            if (a[i] < b[i]) {
                return true;
            } else if (a[i] > b[i]) {
                return false;
            }
        }
        return false;
    }
}

int main() {
    string carlos;
    string sebastian;
    cin >> carlos >> sebastian;
    sort(sebastian.begin(), sebastian.end());
    if (compare(sebastian,carlos)) {
        cout << "Si" << endl;
    } else {
        cout << "No" << endl;
    }
}