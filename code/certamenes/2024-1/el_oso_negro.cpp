/** Problem Statement
Carlos, Nangel, Amanda, Bryan y Matías se fueron de campamento cerca de un lago. 
Felices y despreocupados, descuidaron todos los avisos que advertían sobre la repentina aparición de osos negros en el camping, 
y no guardaron sus alimentos en el almacén anti-osos (una caja de metal con candado) que se encuentra en cada puesto. 

Así, después de haber ido al lago cercano a pasear en kayak, al volver encontraron que todos los demás campistas estaban alborotados, 
produciendo mucho ruido, haciendo sonar las alarmas de los autos y gritando cosas como: "¡Fuera de aquí!", "¡Largo!", etc. 
Era un oso negro que, atraído por los víveres que los campistas siempre dejan fuera, se fue a ver qué conseguía.

Primero asustados, y luego maravillados, nuestros cinco campistas divisaron al oso. 
Era un oso adolescente, que no parecía particularmente agresivo. 
Amanda quiso acariciarlo, pero el resto del grupo la detuvo y, siguiendo las indicaciones que los guardaparques les habían provisto al llegar, 
se pusieron uno al lado del otro y abrieron los brazos para asustar al simpático individuo. 

El oso los miraba y no parecía particularmente asustado. En una actitud entre indiferente y curiosa, se quedó allí, 
observando a ver qué hacían sus víctimas, por supuesto, manteniendo su mirada en los víveres desprotegidos.

Los cinco campistas pronto comprendieron que deberían ceder ante las pretensiones del oso 
o, en caso contrario, serían ellos los que se convertirían en comida. 
Bryan sugirió que habría que darle como ofrenda algunos de los víveres 
y Matías asintió ante la condición de que se le ofreciera una dotación adecuadamente balanceada y equilibrada. 

Al fin y al cabo, no hay que hacerle daño a la pobre criatura. Todos los demás estaban de acuerdo.

Carlos, entonces, confeccionó una lista de alimentos disponibles, incluyendo, por cada uno, su valor calórico 
y un curioso "Índice de Sabrosidad para Osos" (o ISO), que, sospechosamente, encontró en algún blog de campistas en Internet. 

A Nangel le tocó la tarea de seleccionar los alimentos que entrarían a la ofrenda del oso que, a estas alturas,
 ya se había sentado en la mesa, mientras le preparaban la cena.

Por supuesto, Nangel escogerá una colección de alimentos que no sobrepase la recomendación de "ingesta de calorías diarias"
 recomendada para osos y que, a la vez, deje más contenta a la visita. 
 
 Como se encuentra un poco asustado, se pregunta si puedes ayudarlo con la preparación del banquete.
 
Input

La entrada consiste de los siguientes datos:

    Primera línea: 1 ≤ n ≤ 1000, 1 ≤ C ≤ 10000, correspondientes al número de alimentos disponibles 
    y al máximo valor de ingesta de calorías diarias recomendada para osos, respectivamente.
    
    Siguientes n líneas: nombrei, 0 ≤ VCi ≤ 10000, 0 ≤ ISOi ≤ 10000, correspondientes al nombre del alimento, 
    su valor calórico y su índice de sabrosidad para osos. 

Output

Un número entero correspondiente a la sabrosidad total de la ofrenda preparada al oso.

Input 1:

5 50
brocoli 10 1
hamburguesa vegana 10 3
hamburguesa de carne 25 15
ravioles de acelgas 35 10
marraqueta 10 5

Output 1:

23

 * @source: https://codeforces.com/group/wA0CSxKsVV/contest/568840/problem/A
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

struct Alimento{
    
    int valor_calorico;
    int indice_sabrosidad;
    
};

ll maximizeSabrosidad(std::vector<Alimento>&alimentos, int n_alimentos, int C_calorias){
    
    // El problema es un knaspack 0/1. 
    // Esta resolución lo hace mediante arreglo unidimensional, debido a las caracteristicas del problema
    // Basicamente, no requiere reconstrucción
    
    std::vector<ll> dp_knapsack(C_calorias+1,0); // Guarda el valor de sabrosidad
    
    // Caso base: La cantidad de sabrosidad sera 0 con 0 calorias.
    
    // Iteraciones
    
    for(int curr_al_idx = 0; curr_al_idx < n_alimentos; curr_al_idx++){
        
        int alimento_calorias = alimentos[curr_al_idx].valor_calorico;
        int alimento_sabrosidad = alimentos[curr_al_idx].indice_sabrosidad;
        
        for(int curr_calorias = C_calorias; curr_calorias >= 0; curr_calorias--){
            
            if(curr_calorias - alimento_calorias >= 0){
                
                dp_knapsack[curr_calorias] = std::max(
                    dp_knapsack[curr_calorias], 
                    dp_knapsack[curr_calorias-alimento_calorias] + alimento_sabrosidad
                );
                
            }
            
        }
        
    }
    
    return *std::max_element(dp_knapsack.begin(), dp_knapsack.end());
    
}

void solve(){
    
    int n_alimentos, C_calorias;
    // std::cin >> n_alimentos >> C_calorias; Se bugeaba con std::getline
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss_line(line);
    
    std::vector<std::string> input_vector;
    
    while(ss_line >> line){
            input_vector.push_back(line);
    }
    
    n_alimentos = std::stoi(input_vector[0]);
    C_calorias = std::stoi(input_vector[1]);
    
    std::vector<Alimento> alimentos(n_alimentos);
    
    for(int curr_idx = 0; curr_idx < n_alimentos; curr_idx++){
        
        std::getline(std::cin, line);
        std::stringstream ss_line(line);
        
        std::vector<std::string> input_vector;
        std::string input;
        
        while(ss_line >> input){
            input_vector.push_back(input);
        }
        
        // Los dos ultimos elemntos son los valores necesitados.
        alimentos[curr_idx].indice_sabrosidad = std::stoi(input_vector[input_vector.size()-1]);
        alimentos[curr_idx].valor_calorico = std::stoi(input_vector[input_vector.size()-2]);
        
    }
    
    std::cout << maximizeSabrosidad(alimentos,n_alimentos,C_calorias) << std::endl;
    
}

int main(){
    optimize();
    solve();
    return 0;
}