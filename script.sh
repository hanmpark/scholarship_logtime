#!/bin/sh
ruby test.rb
python3 parsing.py
gcc main.c sources/get_next_line.c sources/get_next_line_utils.c sources/utils.c calculate_log.c
./a.out
rm a.out