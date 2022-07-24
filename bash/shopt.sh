#!/bin/bash 
# Felipe Pegoraro, 22/07/2022

setterm -cursor off

printf "%s\n" "shopt: shopt [-pqsu] [-o] [NOME-OPÇÃO ...]"
printf "\t%s  |  %s\n" "-p" "exibe todas opçoes/status"
printf "\t%s  |  %s\n" "-s" "habilita   opçao   (set)"
printf "\t%s  |  %s\n" "-u" "desabilita opçao (unset)"
printf "\t%s  |  %s\n" "-q" 'retorna status `echo $?`'

read -re f
if [[ ! -z $f ]]; then 
	shopt -u globstar       # reprime o `echo **`
	shopt -s histappend     # concatena cmd para `~/.bash_history` (apos `exit`)
	shopt -s cdspell        # corrige `cd /path/diir` -> `cd /path/dir`
	# shopt -s checkwinsize # update the values of LINES and COLUMNS. (after cmd)
	# shopt -s checkhash    # 
	# shopt -s nullglob     # 
fi

setterm -cursor on &&
exit 0
