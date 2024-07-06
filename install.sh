#!/bin/bash

# Cek platform yang sedang digunakan
platform='unknown'
unamestr=$(uname)
if [ "$unamestr" = "Linux" ]; then
   platform='linux'
elif [ "$unamestr" = "Darwin" ]; then
   platform='macOS'
elif [ "$unamestr" = "FreeBSD" ]; then
   platform='freebsd'
elif [ "$(expr substr $(uname -s) 1 5)" == "MINGW" ]; then
   platform='windows'
elif [ -n "$(uname -a | grep Android)" ]; then
   platform='android'
fi

# Instalasi libcurl berdasarkan platform
if [ "$platform" = "linux" ]; then
    echo "Menginstal libcurl untuk Linux..."
    sudo apt-get update
    sudo apt-get install -y libcurl4-openssl-dev
elif [ "$platform" = "android" ]; then
    echo "Menginstal libcurl untuk Termux (Android)..."
    pkg update
    pkg install -y curl
elif [ "$platform" = "windows" ]; then
    echo "Platform Windows tidak didukung dalam skrip ini. Instalasikan libcurl secara manual."
    exit 1
else
    echo "Platform ini tidak didukung dalam skrip ini."
    exit 1
fi

# Compile program menggunakan g++
echo "Kompilasi program..."
g++ -o sql_injection_scanner main.cpp -lcurl

echo "Instalasi selesai."
