from random import randint

flag = 0

with open("teste.svg", "w") as arquivo:
    arquivo.write('<svg width="200" height="200" xmlns="http://www.w3.org/2000/svg">')
    arquivo.write('<circle cx="100" cy="100" r="100" fill="red"/>')
    for i in range(1000000):
        x = randint(0, 200)
        y= randint(0, 200)
        if ((100 - x)** 2) + ((100 - y) ** 2) < 100 ** 2:
            flag += 1
        arquivo.write(f'<circle cx="{x}" cy="{y}" r="5" fill="blue"/>')
    arquivo.write('<\svg>')

print((flag/1000000) * 4)
    