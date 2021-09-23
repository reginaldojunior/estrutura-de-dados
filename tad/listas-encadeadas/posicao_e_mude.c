

int encontre_posicao_e_mude(TipoLista *L, TipoChave C)
{
    TipoApontador p;

    p = L->primeiro;

    while(P != NULL) {
        if (p->Item.Chave == C)  {
            return p;
        } else {
            p = p->prox;
        }
    }

    return NAO_ENCONTROU;
}