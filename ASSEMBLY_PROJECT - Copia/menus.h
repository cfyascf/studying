#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <Windows.h>

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

void leitura_menu(int *resp) {
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
    scanf("%d", resp);
    system("cls");
}

void escrita_menu(int *resp) {
    printf("\n");
    printf(" _____________________\n");
    printf("|        ESCRITA      |\n");
    printf("|_____________________|\n");
    printf("|        1. SW        |\n");
    printf("|        2. SB        |\n");
    printf("|        0. EXIT      |\n");
    printf("|_____________________|\n");
    printf("Escolha uma opcao: ");
    scanf("%d", resp);
    system("cls");
}

void mov_menu(int *resp) {
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
    scanf("%d", resp);
    system("cls");
}

void arit_menu(int *resp) {
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
    scanf("%d", resp);
    system("cls");
}

void logica_menu(int *resp) {
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
    scanf("%d", resp);
    system("cls");
}

void desvio_menu(int *resp) {
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
    scanf("%d", resp);
    system("cls");
}

void process_menu(int *resp) {
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
    scanf("%d", resp);
    system("cls");
}

void sc_process(MIPSProcessor *cpu, int *resp) {
    int j = 16;

    process_menu(resp);
    switch (*resp) {
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

void sc_leitura(MIPSProcessor *cpu, int *resp, int reg1, int reg2, int offset, int value, char label) {
    leitura_menu(resp);
    switch (*resp) {
        case 1:
            lw(cpu, reg1, reg2, offset);
            break;
        case 2:
            lb(cpu, reg1, reg2, offset);
            break;
        case 3:
            li(cpu, reg1, value);
            break;
        case 4:
            la(cpu, reg1, label);
            break;
        case 0:
            printf("Saindo... ");
            Sleep(1000);
            return;
    }
}

void sc_escrita(MIPSProcessor *cpu, int *resp, int reg1, int reg2, int offset) {
    escrita_menu(resp);
    switch (*resp) {
        case 1:
            sw(cpu, reg1, reg2, offset);
            break;
        case 2:
            sb(cpu, reg1, reg2, offset);
            break;
        case 0:
            printf("Saindo... ");
            Sleep(1000);
            return;
    }
}

void sc_movimentacao(MIPSProcessor *cpu, int *resp, int reg1, int reg2) {
    mov_menu(resp);
    switch (*resp) {
        case 1:
            move(cpu, reg1, reg2);
            break;
        case 2:
            mhfi(cpu, reg1);
            break;
        case 3:
            mflo(cpu, reg1);
            break;
        case 0:
            printf("Saindo... ");
            Sleep(1000);
            return;
    }
}

void sc_aritmetica(MIPSProcessor *cpu, int *resp, int value) {
    arit_menu(resp);
    switch (*resp) {
        case 1:
            add(cpu);
            break;
        case 2:
            addi(cpu, value);
            break;
        case 3:
            addu(cpu, value);
            break;
        case 4:
            sub(cpu);
            break;
        case 5:
            subu(cpu);
            break;
        case 6:
            mul(cpu);
            break;
        case 7:
            mulo(cpu);
            break;
        case 8:
            mulou(cpu);
            break;
        case 9:
            mult(cpu);
            break;
        case 10:
            multu(cpu);
            break;
        case 11:
            div(cpu);
            break;
        case 12:
            divu(cpu);
            break;
        case 13:
            rem(cpu);
            break;
        case 14:
            remu(cpu);
            break;
        case 0:
            printf("Saindo... ");
            Sleep(1000);
            return;
    }
}

void sc_logica(MIPSProcessor *cpu, int *resp) {
    logica_menu(resp);
    switch (*resp) {
        case 1:
            andf(cpu);
            break;
        case 2:
            andi(cpu, value);
            break;
        case 3:
            neg(cpu);
            break;
        case 4:
            negu(cpu);
            break;
        case 5:
            nor(cpu);
            break;
        case 6:
            notf(cpu);
            break;
        case 7:
            orf(cpu);
            break;
        case 8:
            ori(cpu, value);
            break;
        case 9:
            rol(cpu, value);
            break;
        case 10:
            ror(cpu, value);
            break;
        case 11:
            sll(cpu, value);
            break;
        case 12:
            sla(cpu, value);
            break;
        case 13:
            srl(cpu, value);
            break;
        case 14:
            sra(cpu, value);
            break;
        case 15:
            xorf(cpu);
            break;
        case 16:
            xori(cpu, value);
            break;
        case 0:
            printf("Saindo... ");
            Sleep(1000);
            return;
    }
}

void sc_desvio(MIPSProcessor *cpu, int *resp, char label, int reg1) {
    desvio_menu(resp);
    switch (*resp) {
        case 1:
            b(cpu, label);
            break;
        case 2:
            j(cpu, label);
            break;
        case 3:
            jr(cpu, reg1);
            break;
        case 4:
            beq(cpu, label, reg1, reg2);
            break;
        case 5:
            blt(cpu, label, reg1, reg2);
            break;
        case 6:
            ble(cpu, label, reg1, reg2);
            break;
        case 7:
            bgt(cpu, label, reg1, reg2);
            break;
        case 8:
            bge(cpu, label, reg1, reg2);
            break;
        case 9:
            bne(cpu, label, reg1, reg2);
            break;
        case 10:
            jal(cpu, label);
            break;
        case 11:
            jr_ra(cpu, label);
            break;
        case 0:
            printf("Saindo... ");
            Sleep(1000);
            return;
    }
}

#endif