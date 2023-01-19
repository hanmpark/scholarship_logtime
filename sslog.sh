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
gcc scholarship_logtime.a 2> /dev/null
if [ $? -eq 0 ]
then
  printf ""
else
  echo "\033[1;31mYou need to compile first !\033[0m"
  exit 1
fi
./a.out $2 $3
rm a.out