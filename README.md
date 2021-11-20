# soft_uart

Software-based serial port module for Khadas SBC.

This module creates a software-based serial port using a configurable pair of GPIO pins. The serial port will appear as `/dev/ttySOFT0`.


## Features

* Works exactly as a hardware-based serial port.
* Works with any application, e.g. cat, echo, minicom.
* Configurable baud rate.
* TX buffer of 256 bytes.
* RX buffer managed by the kernel.


## Compiling

Fetch the source:
```
git clone https://github.com/yan-wyb/soft_uart.git
```


Run `make` and `make install`, as usual.
```
cd soft_uart
make
```

## Loading

Module parameters:

* gpio_tx: int [default = 474]
* gpio_rx: int [default = 475]

Loading the module with default parameters:
```
sudo insmod soft_uart.ko
```

Loading module with custom parameters:
```
sudo insmod soft_uart.ko gpio_tx=474 gpio_rx=475
```


## Usage

The device will appear as `/dev/ttySOFT0`. Use it as any usual TTY device.

You must be included in the group `dialout`. You can verify in what groups you are included by typing `groups`. To add an user to the group `dialout`, type:
```
sudo usermod -aG dialout <username>
```

Usage examples:
```
minicom -b 9600 -D /dev/ttySOFT0
cat /dev/ttySOFT0
echo "Hello Khadas!" > /dev/ttySOFT0
```
