
int main() {
    int opcao,v;

    No* a = arv_cria(8,
                arv_cria(4,
                    arv_cria(2,
                             arv_cria(1,arv_criavazia(),arv_criavazia()),
                             arv_cria(3,arv_criavazia(),arv_criavazia())),
                    arv_cria(6,
                             arv_cria(5,arv_criavazia(),arv_criavazia()),
                             arv_cria(7,arv_criavazia(),arv_criavazia()))
                ),
                arv_cria(10,
                    arv_cria(9, arv_criavazia(), arv_criavazia()),
                    arv_cria(11, arv_criavazia(), arv_criavazia())
                )
          );
       system("cls");
        wprintf(L"\n\n\t\t");
        wprintf(L"ÁRVORE BINÁRIA - ADICIONAR NÓ\n\n");
        imprime(a,0);
        wprintf(L"\n\tDigite um elemento para Adicionar: ");
        scanf("%i",&v);
        abb_insere(a,v);
        wprintf(L"\n");
        imprime(a,0);
        getch();
    return 0;
}