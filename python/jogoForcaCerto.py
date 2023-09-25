from random import randint

#Abre e le o arquivo
with open("br-sem-acentos.txt", 'r') as file:
    conteudo = file.read()
    palavras = conteudo.split()
    
    
#Lista com palavras de ate 6 letras
listaMenor = []
for palavra in palavras:
    if len(palavra) <= 6:
        listaMenor.append(palavra)
        
        
#Sorteia palavra aleatoria
index = randint(0, len(listaMenor))
chave = listaMenor[index]


#Declarando variaveis
arrayChave = []
arrayUser = []
arrayResposta = []

#Forma arrayResposta
for i in range(len(chave)):
    arrayResposta.append('_')
print(arrayResposta)
print()

#Transforma chave em array
for letra in chave:
    arrayChave.append(letra)
    
print("\n--- JOGO TERMO ---\n")

while arrayChave != arrayResposta:
    
    print(chave)
    #Trata palavras que nao existem
    try:
        userTry = input("Insira sua tentativa: ")
        if userTry not in palavras:
            print("Essa palavra não está no dicionário!\n")
            continue
    except Exception as e:
        print("Ocorreu um erro:", e)
        continue  
    

    #Transforma userTry em array
    for letra in userTry:
        arrayUser.append(letra)
        
        
    #Deixa os dois arrays do mesmo tamanho
    if len(arrayUser) > len(arrayChave):
        maior = arrayUser
        menor = arrayChave
        posicoesQFaltam = len(maior) - len(menor)
        for i in range(posicoesQFaltam):
            arrayChave.append('_')
            
    elif len(arrayUser) < len(arrayChave):
        maior = arrayChave
        menor = arrayUser
        posicoesQFaltam = len(maior) - len(menor)
        for i in range(posicoesQFaltam):
            arrayUser.append('_')
    
    
    #Verifica se a letra esta na palavra chave
    for i in range(len(arrayChave)-1):
        if arrayChave[i] == arrayUser[i]:
            arrayResposta[i] = arrayUser[i]
        elif arrayUser[i] in arrayChave:
            print(f"A letra {arrayUser[i]} está na palavra\n")
        

    print(arrayResposta)
    arrayUser = []


print("Parabéns, você ganhou!")

