#!/bin/bash

while IFS= read -r line
do
    printf '%08x\n' "$((2#$line))"
done
