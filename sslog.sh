#!/bin/sh

clear
printf "
\033[1;35m
█▀ █▀▀ █ █ █▀█ █   ▄▀█ █▀█ █▀ █ █ █ █▀█  █   █▀█ █▀▀ ▀█▀ █ █▀▄▀█ █▀▀
▄█ █▄▄ █▀█ █▄█ █▄▄ █▀█ █▀▄ ▄█ █▀█ █ █▀▀  █▄▄ █▄█ █▄█  █  █ █ ▀ █ ██▄
____________________________________________________________________
\033[0m

"
ruby connect_api.rb 2> /dev/null << EOF
$1
EOF
if [ $? -eq 0 ]
then
  printf "\033[1mlogin:\033[0m $1\n"
else
  echo "\033[1;31mThe login doesn't exist ! Or you need to set your UID_42 and SECRET_42 environment variables\033[0m"
  exit 1
fi
make
gcc parse_stats.c scholarship_logtime.a
./a.out
gcc -fsanitize=address -g3 scholarship_logtime.a
./a.out $2
make fclean
rm a.out