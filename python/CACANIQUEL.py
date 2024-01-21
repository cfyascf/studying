import tkinter as tk
from tkinter import messagebox
import random
import time

def user():
    global saldo
    global easter
    global chance
    janela.update()
    entry_tratado = entry_aposta.get()
    
    try:
        salApostado = float(entry_tratado)
    except ValueError:
        easter +=1
        if easter >= 3:
            messagebox.showinfo("Aviso", "Minha criadora eh linda e seu ajudante eh mais ou menos kkkkk!")
        messagebox.showerror("Aviso","Tente digitar um valor valido." )
        return
    
    if salApostado <= 0:
        messagebox.showerror("Aviso", "A aposta deve ser maior que zero.")
        return

    if salApostado > saldo:
        messagebox.showerror("Aviso", "Saldo insuficiente. Tente novamente.")
        return

    saldo -= salApostado
    saldo_label.config(text=f"SALDO ATUAL >> {saldo}")
    sorteio_label.config(text="Sorteados:")
    sorteio_str = ""

    for i in range(0, chance):
        sorteio_str += 'X' + '  '
        sorteio_label.config(text=sorteio_str)
        janela.update()
        time.sleep(1)

    for i in range(chance, 5):
        sorteio_str += random.choice(badges) + '  '
        sorteio_label.config(text=sorteio_str)
        janela.update()
        time.sleep(1)

    result, mult = algoritmo(sorteio_str)

    if result:
        val_ganho = salApostado * mult
        profit = val_ganho - salApostado
        saldo += val_ganho
        saldo_label.config(text=f"SALDO ATUAL >> {saldo}")
        messagebox.showinfo("Resultado", f"Você ganhou! Lucro: {profit}")
        
    else:
        messagebox.showinfo("Resultado", "Você perdeu!")

def algoritmo(sorteio):
    if sorteio.count("X") == 5:
        messagebox.showinfo("Jackpot", "JACKPOT - JACKPOT - JACKPOT - JACKPOT - JACKPOT - JACKPOT")
        return True, 15
    elif sorteio.count("S") == 5:
        return True, 10
    elif (sorteio.count("X") == 2 and sorteio.count("S") == 3) or (sorteio.count("X") == 3 and sorteio.count("S") == 2):
        return True, 5
    elif sorteio.count("X") >= 3:
        return True, 3
    elif sorteio.count("A") == 5 or sorteio.count("B") == 5 or sorteio.count("C") == 5:
        return True, 3
    elif sorteio.count("S") >= 3:
        return True, 1.5
    elif sorteio.count("A") >= 3 or sorteio.count("B") >= 3 or sorteio.count("C") >= 3:
        return True, 0.75
    else:
        return False, 0
    
def gabarito():
    messagebox.showinfo("Gabarito", "Gabarito de apostas: \n\n X X X X X - 15x\n S S S S S - 10x\n X X S S S - 5x\n X X X S S - 5x\n X X X X A - 3x\n A A A A A - 3x\n S S S A A - 1.5x\n A A A C B - 0.75x")
    
def dev_window():
    janela_dev = tk.Toplevel(janela)
    janela_dev.title("DESENVOLVEDOR")

    title_label = tk.Label(janela_dev, text="JANELA DO DESENVOLVEDOR\nOpções disponíveis:")
    title_label.grid(row=0, column=1, padx=10, pady=10)

    saldo_label = tk.Label(janela_dev, text="Entre com o saldo")
    saldo_label.grid(row=1, column=0, padx=10, pady=10)

    entry_att = tk.Entry(janela_dev)
    entry_att.grid(row=1, column=1, padx=10, pady=10)
    button_att = tk.Button(janela_dev, text="Enter", command=lambda: att_saldo(entry_att))
    button_att.grid(row=1, column=2, padx=10, pady=10)
    
    handle_label = tk.Label(janela_dev, text="Qual o valor de Handle\n 1-Igual / 2-Leve/ 3-Moderado / 4-Mega / 5-Blaster ")
    handle_label.grid(row=2, column=0, padx=10, pady=10)
    handle_entry = tk.Entry(janela_dev)
    handle_entry.grid(row=2, column=1, padx=10, pady=10) 
    button_handle = tk.Button(janela_dev, text="Handle", command=lambda: handle(handle_entry, janela_dev))
    button_handle.grid(row=2, column=2, padx=10, pady=10)

def handle(handle_entry, janela_dev):
    global chance
    chance = int((handle_entry.get()))
    messagebox.showinfo("AVISO", "CHEAT ACTIVATED!")
    janela_dev.destroy()

def att_saldo(entry_att):
    global saldo
    value = float(entry_att.get())
    saldo += value
    saldo_label.config(text=f"SALDO ATUAL >> {saldo}")
    messagebox.showinfo("AVISO", "Saldo atualizado com sucesso!")
    
def dev_login():
    janela_login = tk.Toplevel(janela)
    janela_login.title("LOGIN")

    title_label = tk.Label(janela_login, text="LOGIN")
    title_label.grid(row=0, column=1, padx=10, pady=10)

    user_label = tk.Label(janela_login, text="Usuario:")
    user_label.grid(row=1, column=0, padx=10, pady=10)
    user_entry = tk.Entry(janela_login, show="*")
    user_entry.grid(row=1, column=1, padx=10, pady=10)

    senha_label = tk.Label(janela_login, text="Senha:")
    senha_label.grid(row=2, column=0, padx=10, pady=10)
    senha_entry = tk.Entry(janela_login, show="*")
    senha_entry.grid(row=2, column=1, padx=10, pady=10)

    user_button = tk.Button(janela_login, text="Enter", command=lambda: verify(user_entry, senha_entry, janela_login))
    user_button.grid(row=3, column=1, padx=10, pady=10)

def verify(user_entry, senha_entry, janela_login):
    usuario = "yasgo"
    senha = "yasgo"

    user_input = user_entry.get()
    senha_input = senha_entry.get()

    if(user_input == usuario and senha_input == senha):
        janela_login.destroy()
        dev_window()
        
    else:
       messagebox.showwarning("Acesso Negado", "Usuário ou senha incorretos. Tente novamente.")
       time.sleep(0.5) 
       janela_login.destroy()
    return


# JANELA PRINCIPAL
janela = tk.Tk()
janela.title('CASSINO')

# VARIAVEIS
saldo = 1000
badges = ['S', 'B', 'C', 'A', 'X']
easter = 0
chance = 0

# WIDGETS
saldo_label = tk.Label(janela, text=f'SALDO ATUAL >> {saldo}')
entry_aposta = tk.Entry(janela)
button_apostar = tk.Button(janela, text="Apostar", command=user)
sorteio_label = tk.Label(janela, text="")
message_sorteio = tk.Label(janela, text="Roleta da rodada: ")
qtd_aposta = tk.Label(janela, text= "Digite o valor a ser apostado abaixo\n ↓ ↓ ")
button_gabarito= tk.Button(janela, text="Gabarito", command=gabarito)
button_dev = tk.Button(janela, text="Desenvolvedor", command=dev_login)
# button_dev.pack()

# POSICIONAMENTO
saldo_label.grid(row=0, column=1, padx=0, pady=10)
qtd_aposta.grid(row=1, column=1, padx=0)
entry_aposta.grid(row=2, column=1, padx=0, pady=10)
button_apostar.grid(row=2, column=2, padx=0, pady=0)
button_gabarito.grid(row=3, column=2,padx=0, pady=0)
button_dev.grid(row=4, column=2)
message_sorteio.grid(row=3, column=0, padx=10)
sorteio_label.grid(row=3, column=1, padx=0, pady=10)

# Iniciar o loop principal
janela.mainloop()
