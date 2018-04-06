#include <stdio.h>

void uart_init();
void uart_send(char letter);
char uart_read();
void led_lights();
ssize_t _write(int fd, const void *buf, size_t count);