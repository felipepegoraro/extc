#!/bin/awk -f

# a program made while reading the book "Sed & Awk"
# ./cmd.awk listcmd

func display(){
	system("clear");
	printf " > %s \n\n", filename
	for (i=1; i<=sizeofArray; ++i){
		printf "\t%d. %s\n", i, menu[i]
	}
	printf "\t%d. Sair\n", i
	printf "\n > Escolha um: "
}

BEGIN {
	if (ARGC < 2){
		print(" > Faltando: arquivo como argumento")
		exit 1
	}

	FS=":"
	filename=ARGV[1]

	if (system("test -r " filename)){
		print(" > Arquivo não encontrado")
		exit 2
	} else
		while ((getline < filename) > 0){
			++sizeofArray	
			menu[sizeofArray] = $1
			command[sizeofArray] = $1
	}
}

{
	while(var < sizeofArray+1){
		display();
		getline var< "-"

		if (var > 0 && var <= sizeofArray){
			printf " > Executando: %s\n", command[var];

			printf " > Argumentos: "
			getline arg< "-"
			system(command[var]" "arg)

			print("\n + Pressione qualquer tecla")
			getline < "-"

			system("clear")
		}
	}
	exit 1
}
