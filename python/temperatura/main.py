import requests
import json
import os
from datetime import datetime


def linha():
    print("-"*50)


def cabecalho():
    linha()
    dataAtual = datetime.now()
    data = f"{dataAtual.day:02}/{dataAtual.month:02}/{dataAtual.year:04}"
    hora = f"{dataAtual.hour:02}:{dataAtual.minute:02}:{dataAtual.second:02}"
    strData = data + " " + hora

    print(f"|\t{'Autor.....: Juvenal Baera':41}|")
    print(f"|\t{'Data......: 17 de janeiro de 2024':41}|")
    print(f"|\t{'Data atual: ' + strData :41}|")
    linha()


def kelvinParaCelcius(temp:float):
    return temp - 273.15


def tempFormatada(temp):
    return f"{round(kelvinParaCelcius(temp),2)}ºC"


def mostrarDados(dados):
    
    nome_cidade = dados["name"]
    dados_principais = dados["main"]
    sensacao_termica = dados_principais["feels_like"]
    temperatura_kelvin = dados_principais["temp"]

    
    linha()
    print("|\tInformações acerca da temperatura\t |")
    linha()
    print(f"|\tPaís............: {dados["sys"]["country"]:>20}   |")
    print(f"|\tCidade..........: {nome_cidade:>20}   |")
    print(f"|\tTemperatura.....: {tempFormatada(temperatura_kelvin):>20}   |")
    print(f"|\tSensação termica: {tempFormatada(sensacao_termica):>20}   |")
    print(f"|\tDescrição.......: {dados["weather"][0]["description"]:>20}   |")
    linha()


def inicio():
    os.system("cls")
    api_chave = "068239be02c627f475be9456d3aa8b6c"
    cabecalho()

    while True:
        print()
        cidade = str(input("Digite nome da cidade [fim - sair]: "))
        if cidade.lower() in ["fim", "sair"]:
            print("Obrigado, Adeus!")
            break

        print()    
        url = f"https://api.openweathermap.org/data/2.5/weather?q={cidade}&appid={api_chave}"

        try:
            pedido = requests.get(url=url)
        except requests.exceptions.ConnectionError:
            print("Erro na conexão: verifique a sua conexão com a internet")
        except Exception as ex:
            print(ex.__class__)
        else:
            if pedido.status_code == 200:
                dados = json.loads(pedido.text)
                mostrarDados(dados)
            elif pedido.status_code == 404:
                print(f"Cidade com nome \"{cidade}\", não existe")
            else:
                print(pedido.status_code)


if __name__ == "__main__":
    inicio()