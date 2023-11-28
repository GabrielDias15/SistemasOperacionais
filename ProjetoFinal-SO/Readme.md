### Gabriel de Oliveira Dias - 32271263
### Linus Leonan Kiche Madera - 32234961
### Luana Miho Yasuda - 42148677

## Processo de criação:
Para criarmos o projeto, passamos por várias fases. Primeiro, tentamos formar uma maneira de fazer os cálculos passo a passo na mão, com a lógica no lugar (criar uma lista para cada direção e fazer verificações para adicionar pessoas ou mudar de lista, e somar o valor de entrada de cada pessoa a 10 e definir o tempo total).

Após algumas tentativas, chegamos à conclusão de como lidar com casos de borda onde uma pessoa possui tempo de entrada menor e direção diferente. Chegamos à conclusão de criar uma função separada para a verificação de toda a lista antes de realizar a operação, assim conseguimos um resultado funcional em 100% dos casos.

Em seguida, adicionamos funções para que o programa possa ler todos os arquivos de uma vez, um único arquivo e também a função inicial de ler apenas o input da pessoa direto no console. Abaixo segue um tutorial de uso do código.

#### Tutorial de execução para o projeto final, código principal (Opção 1 de input lido pelo terminal):
Para apenas testar o projeto, execute o `CodigoFinal.c`, selecione a opção 1 do menu e coloque o input manualmente.

O input deve seguir o formato:


```
3
5 0
8 0
13 0
```
O código irá te fornecer a resposta do input. Para verificar automaticamente o output com os arquivos, executando todos os arquivos de uma vez ou um arquivo por vez, verifique o extra abaixo também.

## Extra:
#### Tutorial de execução Extras do menu (Ler com todos os arquivos ou ler apenas um arquivo):
- Coloque os arquivos de entrada com qualquer nome (sem extensão) e coloque o input no seguinte formato:


```
3
5 0
8 0
13 0
```
e um arquivo de nome igual na pasta output contendo a solução na primeira linha:
```
23
```


- Se quiser utilizar apenas um arquivo, digite 2 no menu e, em seguida:
  - Coloque os arquivos de input e output na mesma pasta do código, crie os arquivos seguindo o formato do passo anterior, e em seguida, execute e selecione a opção 2, digite o nome de ambos os arquivos e o programa vai ler o input e resultado e dizer se está condizente e qual foi o resultado obtido.

- Para todos os arquivos, digite 3 no menu e, em seguida:
  - Coloque as pastas input e output ao lado do código, contendo arquivos com o mesmo nome e respectivamente, input e output no formato indicado no primeiro passo. Em seguida, o programa irá executar e mostrar se o output está correto ou não, assim como o valor calculado e o valor presente no arquivo.

