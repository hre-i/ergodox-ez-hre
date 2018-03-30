#!/bbin/sh

cd ../qmk_firmware/keyboards/ergodox_ez/keymaps && \
    ( rm -f hre; ln -s ../../../../ergodox-ez-hre/ hre )

if   [ -x /usr/bin/apt ]; then
    sudo apt install -y avr-libc
elif [ -x /usr/bin/pacman ]; then
    sudo pacman -S avr-libc
fi
