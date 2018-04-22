#!/bin/bash

for ((i=0; i<1000; i++)); do
  zip flag.zip flag.txt
  rm flag.txt
  mv flag.zip flag.txt
  echo $i
done
