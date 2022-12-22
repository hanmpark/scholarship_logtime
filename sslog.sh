#!/bin/sh

clear
echo "
                                                                            
 _____     _       _             _   _        __            _   _           
|   __|___| |_ ___| |___ ___ ___| |_|_|___   |  |   ___ ___| |_|_|_____ ___ 
|__   |  _|   | . | | .'|  _|_ -|   | | . |  |  |__| . | . |  _| |     | -_|
|_____|___|_|_|___|_|__,|_| |___|_|_|_|  _|  |_____|___|_  |_| |_|_|_|_|___|
                                      |_|              |___|                

"
ruby connect_api.rb 2> /dev/null << EOF
$1
EOF
if [ $? -eq 0 ]
then
  echo "login: $1"
else
  echo "\033[1;31mThe login doesn't exist !\033[0m"
  exit 1
fi
make
gcc parse_stats.c scholarship_logtime.a
./a.out
gcc scholarship_logtime.a
./a.out
make fclean
rm a.out