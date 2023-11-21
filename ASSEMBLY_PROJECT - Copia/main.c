#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "mips.h"
#include "menus.h"

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


void initProcessor(MIPSProcessor *cpu) {
    for (int i = 0; i < 32; i++)
        cpu->registers[i] = 0;
    cpu->pc = 0;
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
            sc_process(&cpu, &resp2);
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
