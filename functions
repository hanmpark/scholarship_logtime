#!/bin/bash

function show_help() {
	printf "Usage: ./script.sh [options] arg1 arg2\n\n"
	printf "Options:\n"
	printf "  -l, --login   : user's login\n"
	printf "  -m, --month   : month\n"
	printf "  -s            : show dates option\n\n"
}

function format_date() {
	local number=$1
	if [ $number -lt 10 ]; then
		number="0$number"
	fi
	echo "$number"
}

function write_month() {
	local digit=$1
	case "$digit" in
		1|01)
			echo "January"
			;;
		2|02)
			echo "February"
			;;
		3|03)
			echo "March"
			;;
		4|04)
			echo "April"
			;;
		5|05)
			echo "May"
			;;
		6|06)
			echo "June"
			;;
		7|07)
			echo "July"
			;;
		8|08)
			echo "August"
			;;
		9|09)
			echo "September"
			;;
		10)
			echo "October"
			;;
		11)
			echo "November"
			;;
		12)
			echo "December"
			;;
		*)
		;;
	esac
}
