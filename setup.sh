#!/bin/sh

if   [ -x /usr/bin/apt ]; then
    sudo apt install -y avr-libc
elif [ -x /usr/bin/pacman ]; then
    sudo pacman -S avr-libc
fi

if [ ! -d ../qmk_firmware ]; then
    (cd ../; git clone --recursive https://github.com/qmk/qmk_firmware.git)
fi

cd ../qmk_firmware/keyboards/ergodox_ez/keymaps && \
    ( rm -f hre; ln -s ../../../../ergodox-ez-hre/ hre )
