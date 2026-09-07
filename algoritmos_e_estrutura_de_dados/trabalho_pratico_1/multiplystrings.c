char* multiply(char* num1, char* num2) {
    int len_num1 = strlen(num1);
    int len_num2 = strlen(num2);
    int len_total = len_num1+len_num2;

    // edge case: valor 0
    if (num1[0] == '0' || num2[0] == '0') {
        char* zero = malloc(2);
        zero[0] = '0';
        zero[1] = '\0';
        return zero;
    }

    // a resposta não será, em acordo à matemática, maior que o número de algarismos dos 2 números envolvidos somados.
    char *res = malloc(len_total+1);

    for ( int i = 0; i < len_total; i++ ) {
        res[i] = '0'; // '0' = 48
    }

    res[len_total] = '\0';

    /*
     * há no loop de 'i' a posição de num1, em 'j' a posição de num2;
     * é realizada a operação entre cada dos algarismos dos dois números;
     * o resultado é um número parcial, que é atualizado na mesma iteração.
     */
    for ( int i = len_num1 - 1; i >= 0; i-- ) {
        for ( int j = len_num2 - 1; j >= 0; j-- ) {

            // converte o char para int subtraindo '0'
            int mul = (num1[i] - '0') * (num2[j] - '0');

            // soma com o que já existe naquela posição
            int sum = mul + (res[i + j + 1] - '0');

            // atualiza a posição atual
            res[i + j + 1] = (sum % 10) + '0';

            // soma a dezena do sum na posição anterior
            res[i + j] = ((res[i + j] - '0') + (sum / 10)) + '0';
        }
    }

    // identifica os zeros antes do número resultante em si
    int start = 0;
    while ( start < len_total && res[start] == '0' ) {
        start++;
    }

    // remove os zeros
    int k = 0;
    while ( start < len_total ) {
        res[k++] = res[start++]; // reutiliza as variáveis como acumulador
    }
    res[k] = '\0';

    return res;
}
