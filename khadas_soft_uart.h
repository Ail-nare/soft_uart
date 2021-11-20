#ifndef KHADAS_SOFT_UART_H
#define KHADAS_SOFT_UART_H

#include <linux/tty.h>

int khadas_soft_uart_init(const int gpio_tx, const int gpio_rx);
int khadas_soft_uart_finalize(void);
int khadas_soft_uart_open(struct tty_struct* tty);
int khadas_soft_uart_close(void);
int khadas_soft_uart_set_baudrate(const int baudrate);
int khadas_soft_uart_send_string(const unsigned char* string, int string_size);
int khadas_soft_uart_get_tx_queue_room(void);
int khadas_soft_uart_get_tx_queue_size(void);

#endif
