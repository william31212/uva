#!/bin/bash

clear
g++ $1.cpp -o $1 -DDBG

echo COMPLING...


if [[ "$?"=="0" ]]; then
	echo FINISHED
	./$1
fi
