#!/bin/sh
set -e

clear
echo "
                                                                            
 _____     _       _             _   _        __            _   _           
|   __|___| |_ ___| |___ ___ ___| |_|_|___   |  |   ___ ___| |_|_|_____ ___ 
|__   |  _|   | . | | .'|  _|_ -|   | | . |  |  |__| . | . |  _| |     | -_|
|_____|___|_|_|___|_|__,|_| |___|_|_|_|  _|  |_____|___|_  |_| |_|_|_|_|___|
                                      |_|              |___|                

"
make
ruby connect_api.rb << EOF
$1
EOF
gcc parse_stats.c scholarship_logtime.a
./a.out
gcc scholarship_logtime.a
./a.out
make fclean
rm a.out