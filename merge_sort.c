void merge(int vetor[], int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio+1, comAux = 0;
    int vetAux[fim-comeco+1];

    while(com1<=meio && com2<=fim)
    {
        if(vetor[com1] <= vetor[com2])
        {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio)   //Caso ainda haja elementos na primeira metade
    {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2<=fim)    //Caso ainda haja elementos na segunda metade
    {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux=comeco; comAux<=fim; comAux++)   //Move os elementos de volta para o vetor original
    {
        vetor[comAux] = vetAux[comAux-comeco];
    }
}

void mergeSort(int vetor[], int comeco, int fim)
{
    if (comeco < fim)
    {
        int meio = (comeco+fim)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}
