#!/bbin/sh

cd ../qmk_firmware/keyboards/ergodox_ez/keymaps && \
    ( rm -f hre; ln -s ../../../../ergodox-ez-hre/ hre )

sudo apt install -y avr-libc
