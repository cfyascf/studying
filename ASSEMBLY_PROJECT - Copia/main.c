#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "mips.h"

typedef struct {
    int registers[32];
    int memory[100];
    int pc;
} MIPSProcessor;

int aux = 0;
int hi = 31;
int lo = 30;
int ra = 29;
int endereco_label = 16;

void mainMenu(int *resp) {
    printf("\n");
    printf(" ________________________________\n");
    printf("|              MENU              |\n");
    printf("|________________________________|\n");
    printf("|          1. LEITURA            |\n");
    printf("|          2. ESCRITA            |\n");
    printf("|          3. MOVIMENTACAO       |\n");
    printf("|          4. ARITMETICA         |\n");
    printf("|          5. LOGICA             |\n");
    printf("|          6. DESVIO             |\n");
    printf("|          7. PROCESSES          |\n");
    printf("|          0. EXIT               |\n");
    printf("|________________________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp);
    system("cls");
}

void leitura_menu(int *resp2) {
    printf("\n");
    printf(" _____________________\n");
    printf("|        LEITURA      |\n");
    printf("|_____________________|\n");
    printf("|        1. LW        |\n");
    printf("|        2. LB        |\n");
    printf("|        3. LI        |\n");
    printf("|        3. LA        |\n");
    printf("|        0. EXIT      |\n");
    printf("|_____________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp2);
    system("cls");
}

void escrita_menu(int *resp3) {
    printf("\n");
    printf(" _____________________\n");
    printf("|        ESCRITA      |\n");
    printf("|_____________________|\n");
    printf("|        1. SW        |\n");
    printf("|        2. SB        |\n");
    printf("|        0. EXIT      |\n");
    printf("|_____________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp3);
    system("cls");
}

void mov_menu(int *resp4) {
    printf("\n");
    printf(" ______________________\n");
    printf("|     MOVIMENTACAO     |\n");
    printf("|______________________|\n");
    printf("|        1. MOVE       |\n");
    printf("|        2. MHFI       |\n");
    printf("|        3. MFLO       |\n");
    printf("|        0. EXIT      |\n");
    printf("|_____________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp4);
    system("cls");
}

void arit_menu(int *resp4) {
    printf("\n");
    printf(" _______________________\n");
    printf("|      ARITMETICA       |\n");
    printf("|_______________________|\n");
    printf("|        1. ADD         |\n");
    printf("|        2. ADDI        |\n");
    printf("|        3. ADDU        |\n");
    printf("|        4. SUB         |\n");
    printf("|        5. SUBU        |\n");
    printf("|        6. MUL         |\n");
    printf("|        7. MULO        |\n");
    printf("|        8. MULOU       |\n");
    printf("|        9. MULT        |\n");
    printf("|       10. MULTU       |\n");
    printf("|       11. DIV         |\n");
    printf("|       12. DIVU        |\n");
    printf("|       13. REM         |\n");
    printf("|       14. REMU        |\n");
    printf("|        0. EXIT        |\n");
    printf("|_______________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp4);
    system("cls");
}

void logica_menu(int *resp4) {
    printf("\n");
    printf(" _______________________\n");
    printf("|         LOGICA        |\n");
    printf("|_______________________|\n");
    printf("|        1. AND         |\n");
    printf("|        2. ANDI        |\n");
    printf("|        3. NEG         |\n");
    printf("|        4. NEGU        |\n");
    printf("|        5. NOR         |\n");
    printf("|        6. NOT         |\n");
    printf("|        7. OR          |\n");
    printf("|        8. ORI         |\n");
    printf("|        9. ROL         |\n");
    printf("|       10. ROR         |\n");
    printf("|       11. SSL         |\n");
    printf("|       12. SLA         |\n");
    printf("|       13. SRL         |\n");
    printf("|       14. SRA         |\n");
    printf("|       15. XOR         |\n");
    printf("|       16. XORI        |\n");
    printf("|        0. EXIT        |\n");
    printf("|_______________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp4);
    system("cls");
}

void logica_menu(int *resp4) {
    printf("\n");
    printf(" ______________________\n");
    printf("|         DESVIO       |\n");
    printf("|______________________|\n");
    printf("|        1. B          |\n");
    printf("|        2. J          |\n");
    printf("|        3. JR         |\n");
    printf("|        4. BEQ        |\n");
    printf("|        5. BLT        |\n");
    printf("|        6. BLE        |\n");
    printf("|        7. BGT        |\n");
    printf("|        8. BGE        |\n");
    printf("|        9. BNE        |\n");
    printf("|       10. JAL        |\n");
    printf("|       11. JR RA      |\n");
    printf("|        0. EXIT       |\n");
    printf("|______________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp4);
    system("cls");
}

void proc_menu(int *resp3) {
    printf("\n");
    printf(" ____________________________\n");
    printf("|       MENU PROCESSOS       |\n");
    printf("|____________________________|\n");
    printf("|        1. RESGISTERS       |\n");
    printf("|        2. PC VALUE         |\n");
    printf("|        3. PROCESSOR        |\n");
    printf("|        0. EXIT             |\n");
    printf("|____________________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp3);
    system("cls");
}

void initProcessor(MIPSProcessor *cpu) {
    for (int i = 0; i < 32; i++)
        cpu->registers[i] = 0;
    cpu->pc = 0;
}

void execute(int opcode, MIPSProcessor *cpu, int reg1, int reg2, int offset) {
    if (opcode == 0x20)
        add(cpu);
    else if (opcode == 0x22)
        sub(cpu);
    else if(opcode == 0x23)
        lw(cpu, reg1, reg2, offset);
}

void sc_proc(MIPSProcessor *cpu, int *resp2) {

    proc_menu(resp2);
    int j = 16;

    switch (*resp2) {
    case 1:
        for(int i = 0; i < 16; i++){
            printf("$S%d = %d                     $S%d = %d\n", i, cpu->registers[i], j, cpu->registers[j]);
            j++;
            }
        printf("\nPrecione enter para sair\n");
        getch();
        system("cls");
        break;
    case 2:
        printf("PC: %d", cpu->pc);
        printf("\nPrecione enter para sair\n");
        getch();
        system("cls");
        break;
    case 3:
        exit(0);
        // nao temos (AINDA)
        break;
    case 0:
        printf("Saindo... ");
        Sleep(1000);
        return;
    }
}

void sc_leitura(MIPSProcessor *cpu, int *resp2, int reg1, int reg2, int offset) {

    switch (*resp2) {
    case 1:
        lw(cpu, reg1, reg2, offset);
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 0:
        printf("Saindo... ");
        Sleep(1000);
        return;
    }
}

void sc_escrita(MIPSProcessor *cpu, int *resp2) {

    switch (*resp2) {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 0:
        printf("Saindo... ");
        Sleep(1000);
        return;
    }
}

void sc_movimentacao(MIPSProcessor *cpu, int *resp2) {

    switch (*resp2) {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 0:
        printf("Saindo... ");
        Sleep(1000);
        return;
    }
}

void sc_aritmetica(MIPSProcessor *cpu, int *resp2) {

    switch (*resp2) {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 0:
        printf("Saindo... ");
        Sleep(1000);
        return;
    }
}

void sc_logica(MIPSProcessor *cpu, int *resp2) {

    switch (*resp2) {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 0:
        printf("Saindo... ");
        Sleep(1000);
        return;
    }
}

void sc_desvio(MIPSProcessor *cpu, int *resp2) {

    switch (*resp2) {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 0:
        printf("Saindo... ");
        Sleep(1000);
        return;
    }
}

int main() {
    int resp = 0, resp2 = 0, opcode = 0;
    int reg1 = 0, reg2 = 0;
    int offset = 0;

    MIPSProcessor cpu;
    initProcessor(&cpu);

    do {
        mainMenu(&resp);

        switch (resp) {
        case 1:
            opcode = 0x20;
            aux += 3;

            printf("--------ADD--------\n");
            printf("Digite o valor de $S%d: ", aux - 3);
            scanf("%d", &cpu.registers[aux - 3]);

            printf("Digite o valor de $S%d: ", aux - 2);
            scanf("%d", &cpu.registers[aux - 2]);

            printf("Digite o valor de $S%d: ", aux - 1);
            scanf("%d", &cpu.registers[aux - 1]);

            execute(opcode, &cpu, reg1, reg2, offset);

            Sleep(3000);
            system("cls");
            break;

        case 2:
            opcode = 0x22;
            aux += 3;

            printf("--------SUB--------\n");
            printf("Digite o valor de $S%d: ", aux - 3);
            scanf("%d", &cpu.registers[aux - 3]);

            printf("Digite o valor de $S%d: ", aux - 2);
            scanf("%d", &cpu.registers[aux - 2]);

            printf("Digite o valor de $S%d: ", aux - 1);
            scanf("%d", &cpu.registers[aux - 1]);

            execute(opcode, &cpu, reg1, reg2, offset);

            Sleep(3000);
            system("cls");
            break;

        case 3:
            opcode = 0x23;
            aux += 3;

            printf("--------LOAD WORD--------\n");
            printf("Digite o registrador de destino: ");
            scanf("%d", &reg1);

            printf("Digite o valor de offset: ");
            scanf("%d", &offset);

            printf("Digite o registrador base: ");
            scanf("%d", &reg2);

            execute(opcode, &cpu, reg1, reg2, offset);

            Sleep(3000);
            system("cls");
            break;

        case 4:
            opcode = 0x2B;
            aux += 3;

            printf("--------STORE WORD--------\n");
            printf("Digite o valor da memoria $s: ");
            scanf("%d", &reg1);

            printf("Digite o valor de offset: ");
            scanf("%d", &offset);

            printf("Digite o valor do registrador $s: ");
            scanf("%d", &reg2);

            execute(opcode, &cpu, reg1, reg2, offset);

            Sleep(3000);
            system("cls");
            break;
        case 5:
            sc_proc(&cpu, &resp2);
        case 0:
            printf("Saindo... ");
            Sleep(1000);
            system("cls");
            break;
        default:
            break;
        }
    } while (resp != 6);


    return 0;
}