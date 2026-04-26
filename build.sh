#!/bin/bash

echo "Mengkompilasi Lognuts-S2 untuk Linux/macOS..."

g++ -std=c++11 -Wall -I include 056_t1ar_prak4.cpp src/menu/menu.cpp src/data/service.cpp src/io/fileHandler.cpp src/data/globals.cpp -o lognuts

if [ $? -ne 0 ]; then
    echo ""
    echo "Kompilasi gagal! Periksa pesan error di atas."
else
    echo "Kompilasi berhasil! Jalankan ./lognuts untuk memulai aplikasi."
fi