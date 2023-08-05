#!/bin/bash

source .env
source functions.sh

# *************************************************************************** #
#                                RETRIEVE DATA                                #
# *************************************************************************** #
SRC_FOLDER="src"

clear
printf "
$PURPLE
█▀ █▀▀ █ █ █▀█ █   ▄▀█ █▀█ █▀ █ █ █ █▀█  █   █▀█ █▀▀ ▀█▀ █ █▀▄▀█ █▀▀
▄█ █▄▄ █▀█ █▄█ █▄▄ █▀█ █▀▄ ▄█ █▀█ █ █▀▀  █▄▄ █▄█ █▄█  █  █ █ ▀ █ ██▄
____________________________________________________________________
$DEF

"

if ! command -v jq &>/dev/null; then
	echo "$JQ_NOT_INSTALLED" 1>&2
	exit 1
fi

login=""
month=""
option_s=""

# Handles options and parameters
while [[ $# -gt 0 ]]; do
	case "$1" in
		-l|--login)
			if [[ -z "$2" ]]; then # Checks if the following argument exist or not
				printf "$MISSING_LOGIN" 1>&2
				exit 1
			fi
			if [[ -z "$login" ]]; then
				login="$2"
			else
				printf "$ALREADY_SET_LOGIN" 1>&2
				exit 1
			fi
			shift 2 # Shifts the command line arguments to the left by 2 positions
			;;
		-m|--month)
			if [[ -z "$2" ]]; then
				printf "$MISSING_MONTH" 1>&2
				exit 1
			fi
			if [[ -z "$month" ]]; then
				month="$2"
			else
				printf "$ALREADY_SET_MONTH" 1>&2
				exit 1
			fi
			shift 2
			;;
		-s)
			option_s="-s"
			shift
			;;
		-h|--help)
			show_help
			exit 0
			;;
		*)
			printf "$UNRECOGNIZED_ARG" 1>&2
			show_help
			exit 1
			;;
	esac
done

if [[ -z "$month" ]]; then
	month=$(date +%m)
	printf "$CURRENT_MONTH$(write_month $month)\n"
else
	month=$(format_date $month)
	if [ "$(expr "$month" \< 1)" -eq 1 ] || [ "$(expr "$month" \> 12)" -eq 1 ]; then
		printf "$NO_EXIST_MONTH" 1>&2
		exit 1
	else
		printf "$CHOSEN_MONTH$(write_month $month)\n"
	fi
fi

year=$(date +%Y)
last_year=$(date +%Y)
last_month=$(expr $month - 2)
if [ "$(expr "$month" \> $(date +%m))" -eq 1 ]; then
	year=$(expr $year - 1)
fi
if [ "$(expr $last_month \<= 0)" -eq 1 ]; then
	last_month=$(expr 12 + $last_month)
fi
if [ "$(expr "$month" \> $(date +%m))" -eq 1 ] || [ "$(expr $last_month \> $month)" -eq 1 ]; then
	last_year=$(expr $last_year - 1)
fi

last_month=$(format_date $last_month)

# *************************************************************************** #
#                                   API CALL                                  #
# *************************************************************************** #

curl -s -k "$HOLIDAYS_API" | jq -r 'to_entries[] | "\(.key) : \(.value)"' | sort -r | grep -E "(^$last_year-)|(^$year-)" > holidays.txt
GET_TOKEN=$(curl -s -X POST --data "grant_type=client_credentials&client_id=$UID_42&client_secret=$SECRET_42" https://api.intra.42.fr/oauth/token | cut -b 18-)
if [[ "$GET_TOKEN" == *error* ]]; then
	printf "$US_42_MISSING" 1>&2
	exit 1
fi
TOKEN_42="${GET_TOKEN%%\"*}"

if [ -z "$login" ]; then # Check if a login is in argument
	if [ -z "$LOGIN" ]; then # if not, check if a login is in .env
		printf "$SET_LOGIN" 1>&2
		exit 1
	else
		LOGIN=$LOGIN
	fi
else
	LOGIN=$login
fi

DATES=$(curl -s -H "Authorization: Bearer $TOKEN_42" "https://api.intra.42.fr/v2/users/$LOGIN/locations_stats?begin_at=$last_year-$last_month-27&end_at=$year-$month-26" | jq -r 'to_entries[] | "\(.key) : \(.value)"' | cut -c 1-21)
if [[ -z "$DATES" ]]; then
	printf "$EXIST_LOGIN" 1>&2
	exit 1
else
	echo "$DATES" > dates.txt
	printf "$LOGIN_IS$LOGIN\n"
fi

# *************************************************************************** #
#                               RUNNING PROGRAM                               #
# *************************************************************************** #
make > /dev/null 2>&1
mv calculator "$SRC_FOLDER"/calculator > /dev/null 2>&1

if [ $? != 0 ]; then
	printf "$ERR_COMPILE" 1>&2
	exit 1
fi

"./$SRC_FOLDER/calculator" $month $year $option_s
make fclean > /dev/null 2>&1
rm "./$SRC_FOLDER/calculator" > /dev/null 2>&1
