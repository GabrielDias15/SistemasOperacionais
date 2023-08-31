#include <iostream>
#include <string>

int main() {
    std::string nome1, nome2;

    std::cout << "Digite o primeiro nome: ";
    std::cin >> nome1;

    std::cout << "Digite o segundo nome: ";
    std::cin >> nome2;

    if (nome1 < nome2) {
        std::cout << "Nomes em ordem alfabética: " << nome1 << ", " << nome2 << std::endl;
    } else {
        std::cout << "Nomes em ordem alfabética: " << nome2 << ", " << nome1 << std::endl;
    }

    return 0;
}
