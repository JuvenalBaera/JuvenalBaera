#include <stdio.h>

// Definindo códigos de escape ANSI para cores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() {
    // Exemplo de uso das cores
    printf(RED "Texto em vermelho\n" RESET);
    printf(GREEN "Texto em verde\n" RESET);
    printf(YELLOW "Texto em amarelo\n" RESET);
    printf(BLUE "Texto em azul\n" RESET);
    printf(MAGENTA "Texto em magenta\n" RESET);
    printf(CYAN "Texto em ciano\n" RESET);

    return 0;
}
