import download as d

url = input("Digite url do vídeo do youtube: ")

def ler_opcao() -> str:
    opcao:str = None
    while True:
        print("a \t-\t Para Áudio")
        print("v \t-\t Para vídeo")
        opcao = input("Escolha uma opção: ").lower()
        if opcao not in ("a", "v"):
            print("Escolha opção válida")
        else:
            break
    return opcao

print("----------------------------")
opcao = ler_opcao()
print("----------------------------")
print("BAIXANDO...")
pasta_arquivo = ""
if opcao == "a":
    pasta_arquivo = d.download_audio(url)
else:
    pasta_arquivo = d.download_video(url)

print(f"\033[32mArquivo guardado na pasta download ao lado\033[m: {pasta_arquivo}")

input("<<< CLIQUE QUALQUER TECLA PARA SAIR >>>")
