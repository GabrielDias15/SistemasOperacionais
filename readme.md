Gabriel de Oliveira Dias - 32271263
# Cálculo de PI utilizando Threads em C
Este repositório contém duas implementações para o cálculo do valor de PI em C

## Implementações
- `mainPi.c`: Implementação sem o uso de mutex, onde as threads podem sofrer de condição de corrida ao atualizar a variável global `sum`.
- `mainSemMutex.c`: Implementação com o uso de mutex, garantindo que apenas uma thread por vez atualize a variável global `sum`.

## Resultados:

As divergências nos valores de PI entre as duas implementações ocorrem devido às condições de corrida na implementação sem mutex, quando implementamos com mutex, o problema se resolve, pois a memória não será acessada fora de ordem.

Podemos observar essas divergências nos prints fornecidos da execução.
