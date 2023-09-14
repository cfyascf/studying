class Pessoa:
    def __init__(self, nome: str, idade: int, genero: str):
        self.__nome = nome
        self.__idade = idade
        self.__genero = genero

    def getNome(self):
        return self.__nome
    def setNome(self, newNome):
        self.__nome = newNome

    def getIdade(self):
        return self.__idade
    def setIdade(self, newIdade):
        self.__idade = newIdade

    def getGenero(self):
        return self.__genero
    def setGenero(self, newGenero):
        self.__genero = newGenero

class Funcionario(Pessoa):
    def __init__(self, nome: str, idade: int, genero: str, cargo: str, salario: float):
        super().__init__(nome, idade, genero)
        self.__cargo = cargo
        self.__salario = salario

    def getCargo(self):
        return self.__cargo
    def setCargo(self, newCargo):
        self.__cargo = newCargo

    def getSalario(self):
        return self.__salario
    def setSalario(self, newSalario):
        self.__salario = newSalario

    def getNFuncionarios(self):
        return self.__nFuncionarios
    def setNFuncionarios(self, newNFuncionarios):
        self.__nFuncionarios = newNFuncionarios

    def calculaBonificacao(self):
        return self.__salario * 0.1
    
class Gerente(Funcionario):
    def __init__(self, nome: str, idade: int, genero: str, cargo: str, salario: float, nFuncionarios: int, setor: str):
        super().__init__(nome, idade, genero, cargo, salario)
        self.__setor = setor
        self.__nFuncionarios = nFuncionarios

    def getSetor(self):
        return self.__setor
    def setSetor(self, newSetor):
        self.__setor = newSetor

    def calculaBonificacao(self):
        salario = self.getSalario()
        return salario * 0.15
    
class Departamento:
    def __init__(self, nomeDepartamento: str):
        self.nomeDepartamento = nomeDepartamento
        self.listaFuncionarios = []

    def adicionarFuncionario(self, funcionario):
        self.listaFuncionarios.append(funcionario)

    def removerFuncionario(self, funcionario):
        self.listaFuncionarios.remove(funcionario)

    def listarFuncionarios(self):
        for funcionario in self.listaFuncionarios:
            nome = funcionario.getNome()
            idade = funcionario.getIdade()
            genero = funcionario.getGenero()
            cargo = funcionario.getCargo()
            salario = funcionario.getSalario()
            print(f"Funcionario {nome}:")
            print(f"Idade: {idade}")
            print(f"Genero: {genero}")
            print(f"Cargo: {cargo}")
            print(f"Salario: {salario}")
            print()


def mostrarMenu():
    print("|| SISTEMA DE GERENCIAMENTO DE FUNCIONARIOS ||")
    opcao = int(input('''
        MENU:

        [1] - Adicionar funcionario
        [2] - Remover funcionario
        [3] - Listar funcionarios
        [4] - Consultar bonificacao
        [5] - Sair
    \n'''))
    return opcao


if __name__ == '__main__':

    nomeDepartamento = input("Em qual departamento deseja realizar alterações?")
    nomeDepartamento = Departamento(nomeDepartamento)

    while True:
        opcao = mostrarMenu()

        if opcao == 1:
            nome = input("Digite o nome do funcionario que deseja adicionar: ")
            idade = int(input("Idade: "))
            genero = input("Genero: ")
            cargo = input("Cargo: ")
            salario = float(input("Salario: "))
            var = input("Este funcionario atua como gerente? [y,n]\n")
            
            if var == 'y':
                nFuncionarios = int(input("Insira o numero de funcionarios cooperados: "))
                setor = input("Setor em que atua: ")
                nome = Gerente(nome, idade, genero, cargo, salario, nFuncionarios, setor)
                nomeDepartamento.adicionarFuncionario(nome)
                

            else:
                nome = Funcionario(nome, idade, genero, cargo, salario)
                nomeDepartamento.adicionarFuncionario(nome)

        elif opcao == 2:
            nome = input("Insira o nome do funcionario que deseja remover: ")
            for funcionario in nomeDepartamento.listaFuncionarios:
                if nome == funcionario.getNome():
                    nomeDepartamento.removerFuncionario(funcionario)

        elif opcao == 3:
            nomeDepartamento.listarFuncionarios()

        elif opcao == 4:
            nome = input("Digite o nome do funcionario do qual deseja consultar a bonificacao: ")
            for funcionario in nomeDepartamento.listaFuncionarios:
                if nome == funcionario.getNome():
                    bonificacao = funcionario.calculaBonificacao()
                    print(f"Este usuario recebe de bonificacao R${bonificacao}")

        else:
            break
