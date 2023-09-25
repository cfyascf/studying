from datetime import date
from random import randint

class Jogador:
    def __init__(self, id: int, nome: str, apelido: str, dataNascimento: date, numero: int, posicao: str, qualidade: int, cartoes: int, suspenso: bool):
        self.id = id
        self.nome = nome
        self.apelido = apelido
        self.dataNascimento = dataNascimento
        self.numero = numero
        self.posicao = posicao
        self.qualidade = qualidade
        self.cartoes = cartoes
        self.suspenso = suspenso

class Plantel():
    def __init__(self, lista):
        self.lista = lista
    
    def cadastraJogador(self, jogador):
        self.lista.append(jogador)

    def mostraDados(self):
        for jogador in self.lista:
            print(f"{jogador.posicao}: {jogador.numero} - {jogador.nome} ({jogador.apelido}) - {jogador.dataNascimento} / CONDICAO: {'SUSPENSO' if jogador.suspenso else 'APTO'}")

def mostrarMenu(choice):
    print("\n ----- PLANTEL -----\n")
    print("VOCE PODERA REGISTRAR ATE 11 JOGADORES")



choice = 'x'
listaJogadores = []
p1 = Plantel(Jogador, listaJogadores)

mostrarMenu(choice)

while choice != 'n':
    choice = input("Deseja registrar jogador? [y,n]\n")

    if choice == 'y':
        id = randint(1, 10000)
        nome = input("Nome: ")
        apelido = input("Apelido: ")
        ano = int(input("Ano de nascimento: "))
        mes = int(input("Mes de nascimento: "))
        dia = int(input("Dia do nascimento: "))
        numero = int(input("Numero: "))
        posicao = input("Posicao: ")
        qualidade = int(input("Qualidade (1 a 1000): "))
        cartoes = int(input("Cartoes (equivalentes a amarelos): "))
        suspenso = input("Jogador esta suspenso? [y,n]\n")
        suspenso = True if suspenso == 'y' else False

        j = Jogador(id, nome, apelido, date(ano, mes, dia), numero, posicao, qualidade, cartoes, suspenso)
        listaJogadores.append(j)

for jogador in listaJogadores:
    p1.mostraDados(jogador)
    

