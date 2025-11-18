/*
Los estudiantes de Algoritmos y Complejidad se enfrentan a un reto tras un desafiante primer certamen. 
Con el objetivo de mejorar sus puntajes, exploran estrategias oscuras. Sebastián, uno de los ayudantes, 
les propone un desafío interesante: cada estudiante comienza con 1000 puntos y debe subir una escalera 
numerada en la que cada peldaño tiene una penalización en puntos. Al pisar un peldaño, el puntaje 
indicado en él se descuenta de su total. Los estudiantes pueden avanzar 1, 2 o 3 peldaños a la vez, 
permitiéndoles saltar algunos peldaños para evitar penalizaciones mayores.

El objetivo es encontrar la estrategia óptima para llegar al último peldaño, partiendo desde el primero, 
con el mayor puntaje posible.

Input
La entrada comienza con un entero n que indica el número de peldaños en la escalera (1 ≤ n ≤ 105).

En la siguiente línea, se encuentran n enteros separados por espacio que representan las 
penalizaciones en puntos de cada peldaño (0 ≤ pi ≤ 500).

Output
Imprime un único entero que indica el máximo puntaje posible al llegar al último escalón.

Examples
InputCopy
1
100
OutputCopy
900
InputCopy
3
0 0 0
OutputCopy
1000
InputCopy
4
5 10 15 20
OutputCopy
975
Note
Caso 1: Solo existe un peldaño, por lo que el estudiante no tiene más opcion que pisarlo.
Caso 2: En este caso no importa que peldaño pisar, nunca se resta puntaje
Caso 3: En este caso el optimo es pisar simplemente el primero y el ultimo.

@source: https://codeforces.com/group/wA0CSxKsVV/contest/568840/problem/B
*/


#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

ll solve(const vector<ll>& p, ll n) {
    vector<ll> dp(n);
    dp[0] = p[0];
    if (n >= 2) dp[1] = p[1] + dp[0];
    if (n >= 3) dp[2] = p[2] + min(dp[1], dp[0]);

    for (ll i = 3; i < n; i++) {
        dp[i] = p[i] + min({dp[i - 1], dp[i - 2], dp[i - 3]});
    }

    return dp[n - 1];  
}




int main() {
    ll n;
    cin >> n;
    vector<ll> p;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        p.push_back(x);
    }
    ll res = solve(p, n);
    res = 1000 - res;
    cout << res << endl;
    return 0;
}