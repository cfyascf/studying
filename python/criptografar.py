from random import randint

with open('alfabeto.txt', 'r') as file:
    conteudo = file.read()
    palavras = conteudo.split()

def converter_binario(num, numBinario):
    for i in range(4):
        if num % 2 == 0:
            numBinario.append(0)
        elif num % 2 == 1:
            numBinario.append(1)
        num = num // 2
        
        numBinario.reverse()
    return numBinario

def recebe_senha_array(senha, arraySenha):
    senha = input("Insira sua senha para ser criptografada: ")
    for caracter in senha:
        arraySenha.append(caracter)
        
    print(arraySenha)
 
senha = 0
arraySenha = []       
recebe_senha_array(senha, arraySenha)

