#!/bin/sh
clear

########## COLORS ###########
RED="\033[1;31m"
DEF="\033[0m"
BOLD="\033[1m"
PURPLE="\033[1;35m"
GRAY="\033[2;37m"
BACK="\033[0K\r"

printf "
$PURPLE
█▀ █▀▀ █ █ █▀█ █   ▄▀█ █▀█ █▀ █ █ █ █▀█  █   █▀█ █▀▀ ▀█▀ █ █▀▄▀█ █▀▀
▄█ █▄▄ █▀█ █▄█ █▄▄ █▀█ █▀▄ ▄█ █▀█ █ █▀▀  █▄▄ █▄█ █▄█  █  █ █ ▀ █ ██▄
____________________________________________________________________
$DEF

"

########## API ##########
GET_TOKEN=$(curl -s -X POST --data "grant_type=client_credentials&client_id=$UID_42&client_secret=$SECRET_42" https://api.intra.42.fr/oauth/token | cut -b 18-)
curl -s -k "https://calendrier.api.gouv.fr/jours-feries/metropole.json" > holidays.txt
if [[ "$GET_TOKEN" == *error* ]]
then
	echo "$RED\rPlease set correct UID_42 SECRET_42\n$DEF"
	exit 1
else
	printf "\033[2;37m- [INFO] Checking API...\033[0m"
	sleep 1
fi

TOKEN_42="${GET_TOKEN%%\"*}"
DATES=$(curl -s -H "Authorization: Bearer $TOKEN_42" "https://api.intra.42.fr/v2/users/$1/locations_stats")
if [[ "$DATES" == "{}" ]]
then
	printf "$BACK$RED- [ERROR] Please set an existing login\n$DEF"
	exit 1
else
	echo "$DATES" > dates.txt
	printf "$BACK$GRAY- [INFO] Login:$DEF $1\n"
fi

gcc scholarship_logtime.a 2> /dev/null
if [ $? != 0 ]
then
	printf "$BACK$RED- [ERROR] You need to compile first$DEF"
	exit 1
fi

./a.out $2 $3
rm a.out