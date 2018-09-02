#ifndef __UART0_H__
#define __UART0_H__

void uart0_init(void);
int putchar(int c);
int getchar(void);
int puts(char *s);
void printHex(int value);

#endif 

