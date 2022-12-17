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
ruby connect_api.rb
python3 parse_stats_to_file.py
gcc main.c sources/get_next_line.c sources/get_next_line_utils.c sources/utils.c sources/calculate_log.c
./a.out
rm a.out
truncate -s 0 texts/text_file.txt