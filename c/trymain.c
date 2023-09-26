#include <stdio.h>
#include <stdlib.h>

typedef struct empregado {
    int qtdDependentes;
    float salarioBruto;
    float gratificacao;
    char valeTransporte;
    char planoSaude;    
} empregado_t;

void recebeDados(empregado_t *pessoa){

    printf("\n--- SUA FOLHA DE PAGAMENTO ---\n");
    printf("Insira seus dados!\n");

    printf("\nQuantidade de dependentes: ");
    scanf("%d", &pessoa->qtdDependentes);

    printf("Salario bruto: ");
    scanf("%f", &pessoa->salarioBruto);

    printf("Gratificacao: ");
    scanf("%f", &pessoa->gratificacao);

    printf("Utiliza vale transporte? [s, n]: ");
    scanf(" %c", &pessoa->valeTransporte);

    printf("Utiliza plano de saude? [s, n]: ");
    scanf(" %c", &pessoa->planoSaude);
}

void menu(int *opcao){
    printf("\n--- CALCULO DA FOLHA ---\n");
    printf("\nInsira a opcao do qual deseja calcular o desconto na folha!\n");
    printf("\n[1] Vale transporte\n");
    printf("[2] Plano de saude\n");
    printf("[3] FGTS\n");
    printf("[4] INSS\n");
    printf("[5] Salario familia\n");
    printf("[6] Imposto de renda\n");
    printf("[7] Salario liquido\n");
    printf("[0] Sair\n");
    scanf("%d", opcao);

}

void valeTransporte(empregado_t pessoa){
    char option;
    float valorPassagem = 6;
    int qtdPassagens = 0, qtdDiasUteis = 0;

    if(pessoa.valeTransporte == 'n'){
        printf("Voce selecionou a nao utilizacao do vale transporte\n");
        printf("Deseja calcular mesmo assim? [s, n]: ");
        scanf(" %c", &option);

        if(option == 'n'){
            printf("Voce retornara para o menu\n");
            return 0;
        }
    }

    printf("Insira a quantidade de passagens utilizadas por dia: ");
    scanf("%d", &qtdPassagens);
    printf("Insira a quantidade de dias uteis do mes atual: ");
    scanf("%d", &qtdDiasUteis);

    float descontoMaximo = 0.06 * pessoa.salarioBruto;
    float descontoVariavel = valorPassagem * (qtdPassagens * qtdDiasUteis);
    float descontoFinal = 0;

    if(descontoMaximo < descontoVariavel){
        descontoFinal = descontoMaximo;
    }
    else if(descontoVariavel < descontoMaximo){
        descontoFinal = descontoVariavel;
    }

    printf("Desconto correspondente ao vale transporte nesse mes: R$%.2f\n", descontoFinal);
}

void planoSaude(empregado_t pessoa){
    char option; 
    int tipoPlano = 0;
    float desconto = 0;

    if(pessoa.planoSaude == 'n'){
        printf("Voce selecionou a nao utilizacao do plano de saude\n");
        printf("Deseja calcular mesmo assim? [s, n]: ");
        scanf(" %c", &option);

        if(option == 'n'){
            printf("Voce retornara para o menu\n");
            return 0;
        }
    }

    printf("Insira seu tipo de plano\n");
    printf("Para o tipo 'Enfermaria', digite 1, para o tipo 'Quarto', digite 2: ");
    scanf("%d", &tipoPlano);
    
    if(pessoa.qtdDependentes == 0){
        if(tipoPlano == 1){
            desconto = 89.9;
        }
        else if(tipoPlano == 2){
            desconto = 119.9;
        }
    }

    if(pessoa.qtdDependentes > 0){
        if(tipoPlano == 1){
            desconto = 89.9 * (pessoa.qtdDependentes + 1);
        }
        else if(tipoPlano == 2){
            desconto = 119.9 * (pessoa.qtdDependentes + 1);
        }
    }

    printf("Desconto correspondente ao plano de saude nesse mes: R$%.1f\n", desconto);

}

void fgts(empregado_t pessoa){
    float fgts = 0.08 * pessoa.salarioBruto;

    printf("O FGTS nao eh um valor descontado nem acrescido no seu salario,\n"
            "mas sim um valor depositado pela empresa na sua conta reservada da caixa!\n\n"
            "Valor de FGTS deste mes: R$%.2f\n", fgts);
}

void inss(empregado_t pessoa){
    float aliquota;

    if(pessoa.salarioBruto <= 1100){
        aliquota = 7,5;
    }
    else if(pessoa.salarioBruto > 1100 && pessoa.salarioBruto <= 2203.48){
        aliquota = 9;
    }
    else if(pessoa.salarioBruto > 2203.48 && pessoa.salarioBruto <= 3305.22){
        aliquota = 12;
    }
    else if(pessoa.salarioBruto > 3305.22 && pessoa.salarioBruto <= 6433.57){
        aliquota = 14;
    }
    else{
        aliquota = 14;
    }

    float desconto = (pessoa.salarioBruto + pessoa.gratificacao) * (aliquota / 100);

    printf("Desconto correspondente ao INSS nesse mes: R$%.2f\n", desconto);
}

void salarioFamilia(empregado_t pessoa){

}


int main(){

    int opcao = 0;

    empregado_t pessoa;

    recebeDados(&pessoa);

    while(1){
        menu(&opcao);
        switch(opcao){
            case 1:
                valeTransporte(pessoa);
                break;
            case 2:
                planoSaude(pessoa);
                break;
            case 3:
                fgts(pessoa);
                break;
            case 4:
                inss(pessoa);
                break;
            case 5:
                salarioFamilia();
                break;
            // case 6:
            //     impostoRenda();
            //     break;
            // case 7:
            //     salarioLiquido();
            //     break;
            // case 0:
            //     break;
        }

        if(opcao == 0){
            break;
        }
    }


    return 0;
}
