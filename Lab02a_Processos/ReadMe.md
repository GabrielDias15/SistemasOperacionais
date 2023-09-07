## Gabriel de Olivira Dias - 32271263
## Rodrigo Rodrigues dos Santos Rios - 41783174

### Rode o programa anterior para valores grandes de n. As mensagens sempre estar˜ao ordenadas pelo valor de i?

Não, a ordem de execução dos processos não é sempre a mesma. Isso ocorre porque a execução do código pode ser influenciada por outros processos que estão sendo executados simultaneamente na máquina. Portanto, mesmo que nos testes a ordem tenha seguido o valor de I, em uma situação real, onde a máquina está executando várias tarefas, a ordem das mensagens pode não ser a mesma.


### O que acontece se o programa anterior escreve-se as mensagens para sys.stdout, usando print, ao inv´es de para sys.stderr?

As mensagens ainda seriam exibidas na saída padrão se o programa usasse print para escrever em sys.stdout ao invés de sys.stderr, a ordem das mensagens pode acabar sendo diferente, pois sys.stdout e sys.stderr são buffers diferentes, um costuma ser usado para a saída normal e outro para erros.