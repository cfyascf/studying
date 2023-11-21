#ifndef MIPS_H
#define MIPS_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void lw(MIPSProcessor *cpu, int reg1, int reg2, int offset) {
    int memoryAddress = offset + reg2;
    cpu->registers[reg1] = cpu->memory[memoryAddress];

    printf("Word resgatada da memoria para o registrador!\n");
    cpu->pc += 4; 
}

void lb(MIPSProcessor *cpu, int reg1, int reg2, int offset) {
    int memoryAddress = offset + reg2;
    cpu->registers[reg1] = cpu->memory[memoryAddress];

    printf("Byte resgatado da memoria para a parte baixa do registrador!\n");
    cpu->pc += 4; 
}

void li(MIPSProcessor *cpu, int reg1, int value) {
    cpu->registers[reg1] = value;

    printf("Valor movido para registrador!\n");
    cpu->pc += 4; 
}

void la(MIPSProcessor *cpu, int reg1, char label) {
    int endereco_label = 1111;
    cpu->registers[reg1] = endereco_label;

    printf("Endereco da label movido para o registrador!\n");
    cpu->pc += 4; 
}

void sw(MIPSProcessor *cpu, int reg1, int reg2, int offset) {
    int registerAddress = offset + reg2;
    cpu->memory[reg1] = cpu->registers[registerAddress];

    printf("Word resgatada do registrador para a memoria!\n");
    cpu->pc += 4; 
}

void sb(MIPSProcessor *cpu, int reg1, int reg2, int offset) {
    int registerAddress = offset + reg2;
    cpu->memory[reg1] = cpu->registers[registerAddress];

    printf("Byte resgatado da parte baixa do registrador para a memoria!\n");
    cpu->pc += 4; 
}

void move(MIPSProcessor *cpu, int reg1, int reg2) {
    cpu->registers[reg1] = cpu->registers[reg2];

    printf("Copia do valor no registrador 2 movido para o registrador 1!\n");
    cpu->pc += 4; 
}

void mfhi(MIPSProcessor *cpu, int reg1) {
    cpu->registers[reg1] = cpu->registers[hi];

    printf("Copia do valor no registrador Hi movido para o registrador 1!\n");
    cpu->pc += 4; 
}

void mflo(MIPSProcessor *cpu, int reg1) {
    cpu->registers[reg1] = cpu->registers[hi];

    printf("Copia do valor no registrador Lo movido para o registrador 1!\n");
    cpu->pc += 4; 
}

void add(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] + cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void addi(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] + value;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void addu(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] + value;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void sub(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] - cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void subu(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] - cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void mul(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] * cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void mulo(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] * cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void mulou(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] * cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void mult(MIPSProcessor *cpu) {
    cpu->registers[lo] = cpu->registers[aux - 2] * cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void multu(MIPSProcessor *cpu) {
    cpu->registers[lo] = cpu->registers[aux - 2] * cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void div(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] / cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void divu(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] / cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void rem(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] % cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void remu(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] % cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void andf(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] & cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void andi(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] & value;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void neg(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = 0 - cpu->registers[aux - 2];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void negu(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = 0 - cpu->registers[aux - 2];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void nor(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = ~(cpu->registers[aux - 2] | cpu->registers[aux - 1]);

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void notf(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = ~cpu->registers[aux - 2];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void orf(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] | cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void ori(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] | value;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void rol(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] << value | cpu->registers[aux - 2] >> (32 - value);

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void ror(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] >> value | cpu->registers[aux - 2] << (32 - value);

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void sll(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] << value ;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void sla(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] << value ;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void srl(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] >> value ;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void sra(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] >> value ;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void xorf(MIPSProcessor *cpu) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] ^ cpu->registers[aux - 1];

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}

void xori(MIPSProcessor *cpu, int value) {
    cpu->registers[aux - 3] = cpu->registers[aux - 2] ^ value;

    printf("Resultado da operacao: %d\n", cpu->registers[aux - 3]);
    cpu->pc += 4;
}
 
void b(MIPSProcessor *cpu, char label) {
    cpu->pc = endereco_label;
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void j(MIPSProcessor *cpu, char label) {
    cpu->pc = endereco_label;
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void jr(MIPSProcessor *cpu, int reg1) {
    int endereco_reg1 = 3;

    cpu->pc = endereco_reg1;
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void beq(MIPSProcessor *cpu, char label, int reg1, int reg2) {
    if(reg1 == reg2){
        cpu->pc = label;
    }

    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void blt(MIPSProcessor *cpu, char label, int reg1, int reg2) {
    if(reg1 < reg2){
        cpu->pc = label;
    }
    
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void ble(MIPSProcessor *cpu, char label, int reg1, int reg2) {
    if(reg1 <= reg2){
        cpu->pc = label;
    }
    
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void bgt(MIPSProcessor *cpu, char label, int reg1, int reg2) {
    if(reg1 > reg2){
        cpu->pc = label;
    }
    
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void bge(MIPSProcessor *cpu, char label, int reg1, int reg2) {
    if(reg1 >= reg2){
        cpu->pc = label;
    }
    
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void bne(MIPSProcessor *cpu, char label, int reg1, int reg2) {
    if(reg1 != reg2){
        cpu->pc = label;
    }
    
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void jal(MIPSProcessor *cpu, char label) {
    cpu->pc = label;
    cpu->registers[ra] = cpu->pc;
    
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void jr_ra(MIPSProcessor *cpu, char label) {
    cpu->pc = cpu->registers[ra];
    
    printf("Valor de pc atualizado: %d\n", cpu->pc);
}

void execute(int opcode, MIPSProcessor *cpu, int reg1, int reg2, int offset) {
    if (opcode == 0x20)
        add(cpu);
    else if (opcode == 0x22)
        sub(cpu);
    else if(opcode == 0x23)
        lw(cpu, reg1, reg2, offset);
}

#endif
