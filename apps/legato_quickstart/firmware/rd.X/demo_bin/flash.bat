@echo off
sam-ba -p usb -d sam9x60 -t 5 -a qspiflash:0:1:66 -c erase:0x0:0x105000
sam-ba -p usb -d sam9x60 -t 5 -a qspiflash:0:1:66 -c writeboot:at91bootstrap.bin
sam-ba -p usb -d sam9x60 -t 5 -a qspiflash:0:1:66 -c write:harmony.bin:0x4000
sam-ba -p usb -d sam9x60 -a bootconfig -c writecfg:bscr:EMULATION_ENABLED
sam-ba -p usb -d sam9x60 -a bootconfig -c resetemul
sam-ba -p usb -d sam9x60 -a bootconfig -c refreshcfg:emul
sam-ba -p usb -d sam9x60 -a bootconfig -c refreshcfg:emul
sam-ba -p usb -d sam9x60 -a bootconfig -c writecfg:bcp-emul:FLEXCOM3_USART_IOSET5,QSPI0_IOSET1_AT25
echo "finish"