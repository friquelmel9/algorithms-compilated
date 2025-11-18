/*
Un profesor está trabajando con un lenguaje de bajo nivel, similar a assembly. 
Ha asignado a cada una de las n instrucciones un número binario de longitud n. 
Un día, un alumno le avisa que olvidó agregar una instrucción, por lo que el 
profesor necesita generar un nuevo número binario para asignarle a esta instrucción faltante.

Como el profesor no tiene tiempo para ocuparse de este problema, te pide que lo
 ayudes a encontrar una solución rápida.

Input
La primera línea del input contiene un entero n (1 ≤ n ≤ 103), correspondiente al 
número de números binarios que tenía el profesor.

Luego, le siguen n líneas cada una con un único string correspondiente a un número 
binario. Cada string es de largo n y se asegura que no se repiten los números binarios.

Output
El output debe contener un único string de largo n correspondiente a un número 
binario que sea diferente con respecto a los n strings entregados en el input.

Examples
InputCopy
4
1010
1011
1111
0001
OutputCopy
1110
InputCopy
10
1001111000
1000000000
1001001110
1000110001
1011100001
1001110000
1000000001
1000000011
1000001111
1000011111
OutputCopy
1111111111

@source: https://codeforces.com/group/wA0CSxKsVV/contest/568840/problem/G
*/


#include <bits/stdc++.h>
#include <string>
using ll = long long;
using ld = long double;
using namespace std;

void Backtrack(const int& n,const set<string>& numbers, string &s, string& res, int index) {
    if (res != "")
        return;

    if (s.size() == n && numbers.count(s) != 1) {
        res = s;
        return;
    }

    for (int i = index; i < n; i++) {
        s += "0";
        Backtrack(n, numbers, s, res, index+1);
        s = s.substr(0,s.size()-1);

        s += "1";
        Backtrack(n, numbers, s, res, index+1);
        s = s.substr(0, s.size()-1);
    }

}



int main() {
    int n;
    set<string> numbers;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        numbers.insert(x);
    }
    string res = "";
    string s = "";
    Backtrack(n, numbers, s, res, 0);
    cout << res << endl;
    return 0;
}