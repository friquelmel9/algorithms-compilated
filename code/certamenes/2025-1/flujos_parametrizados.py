def main():
    " @source: https://codeforces.com/gym/615921/problem/A" 
    " @autor: https://codeforces.com/profile/b4stiardo "
    
    nodos = int(input()) # Cantidad de nodos y lineas que vienen a continuacion.
    lineas = []
    for _ in range(nodos):
        id,Lambda = input().split()
        id = int(id)
        Lambda = float(Lambda)
        lineas.append([id,Lambda])
    diccionario_lambda = {} # Diccionario para guardar los pares Lambda : [identificadores]
    for id, Lambda in lineas:
        if Lambda not in diccionario_lambda:
            diccionario_lambda[Lambda] = [id]
            continue
        # Si es que se encuentra el valor de Lambda, entonces debemos apendar al valor el id.
        diccionario_lambda[Lambda].append(id)
    for Lambda in sorted(diccionario_lambda):
        ids = sorted(diccionario_lambda[Lambda])
        ids = " ".join(map(str,diccionario_lambda[Lambda]))
        print(str(Lambda) +": "+ ids)
if True:
    main()