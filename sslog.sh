#!/bin/bash

# DISPLAYING
RED="\033[1;31m"
DEF="\033[0m"
BOLD="\033[1m"
PURPLE="\033[1;35m"
GRAY="\033[2;37m"
BACK="\033[0K\r"

SRC_FOLDER="src"

clear
printf "
$PURPLE
█▀ █▀▀ █ █ █▀█ █   ▄▀█ █▀█ █▀ █ █ █ █▀█  █   █▀█ █▀▀ ▀█▀ █ █▀▄▀█ █▀▀
▄█ █▄▄ █▀█ █▄█ █▄▄ █▀█ █▀▄ ▄█ █▀█ █ █▀▀  █▄▄ █▄█ █▄█  █  █ █ ▀ █ ██▄
____________________________________________________________________
$DEF

"

# Fonction d'aide pour afficher l'aide du script
function show_help() {
	printf "Usage: ./script.sh [options] arg1 arg2\n\n"
	printf "Options:\n"
	printf "  -l, --login   : user's login\n"
	printf "  -m, --month   : month\n"
	printf "  -s            : show dates option\n\n"
}

# Variables par défaut pour stocker les valeurs des options
login=""
month=""
option_s=""

# Boucle pour parcourir les arguments en ligne de commande
while [[ $# -gt 0 ]]; do
	case "$1" in
		# Option -l ou --login avec l'argument suivant
		-l|--login)
			if [[ -z "$2" ]]; then
				printf "$RED - [ERROR] Login is missing\n$DEF"
				exit 1
			fi
			login="$2"
			shift 2
			;;

		# Option -m ou --month avec l'argument suivant
		-m|--month)
			if [[ -z "$2" ]]; then
				printf "$RED - [ERROR] Month is missing\n$DEF"
				exit 1
			fi
			month="$2"
			shift 2
			;;

		# Option -s sans argument, il suffit de marquer que l'option est présente
		-s)
			option_s="-s"
			shift
			;;

		# Aide
		-h|--help)
			show_help
			exit 0
			;;

		# Cas des autres arguments (valeurs non liées à une option)
		*)
			# Faites ce que vous souhaitez avec les arguments sans option ici.
			# Dans l'exemple ci-dessus, nous les ignorons simplement.
			shift
			;;
	esac
done

# API
if [ $# \> 3 ]
then
	printf "$RED - [ERROR] Wrong number of arguments\n$DEF"
	exit 1
fi

# Check if .env files to retrieve UID_42 and SECRET_42
if [ -f .env ]; then
	source .env
else
	printf "$RED - [ERROR] .env file not found\n$DEF"
	exit 1
fi

GET_TOKEN=$(curl -s -X POST --data "grant_type=client_credentials&client_id=$UID_42&client_secret=$SECRET_42" https://api.intra.42.fr/oauth/token | cut -b 18-)
curl -s -k "https://calendrier.api.gouv.fr/jours-feries/metropole.json" > holidays.txt
if [[ "$GET_TOKEN" == *error* ]]
then
	printf "$RED\rPlease set correct UID_42 SECRET_42\n$DEF"
	exit 1
fi

TOKEN_42="${GET_TOKEN%%\"*}"

if [ -z "$login" ]; then # Check if a login is in argument
	if [ -z "$LOGIN" ]; then # if not, check if a login is in .env
		printf "$RED - [ERROR] Please set a login\n$DEF"
		exit 1
	else
		LOGIN=$LOGIN
	fi
else
	LOGIN=$login
fi

DATES=$(curl -s -H "Authorization: Bearer $TOKEN_42" "https://api.intra.42.fr/v2/users/$LOGIN/locations_stats")
if [[ "$DATES" == "{}" ]]
then
	printf "$BACK$RED- [ERROR] Please set an existing login\n\n$DEF"
	exit 1
else
	echo "$DATES" > dates.txt
	printf "$BACK$GRAY- [INFO] Login:$DEF $LOGIN      \n"
fi


# RUNNING PROGRAM
make > /dev/null 2>&1
mv calculator "$SRC_FOLDER"/calculator > /dev/null 2>&1

if [ $? != 0 ]
then
	printf "$BACK$RED- [ERROR] You need to compile first\n\n$DEF"
	exit 1
fi

"./$SRC_FOLDER/calculator" $month $option_s
make fclean > /dev/null 2>&1
rm "./$SRC_FOLDER/calculator" > /dev/null 2>&1
