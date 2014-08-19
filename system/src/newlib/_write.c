#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>
#include "UartConfig.h"

int _write(int file, char *ptr, int len)
{
	uint8_t *tmp = (uint8_t*)ptr;
    switch (file) {
    case STDOUT_FILENO: /*stdout*/
    	while(*tmp != '\0') HAL_UART_Transmit(&UART2, tmp++, 1, 5000);
        break;
    case STDERR_FILENO: /* stderr */
    	while(*tmp != '\0') HAL_UART_Transmit(&UART2, tmp++, 1, 5000);
        break;
    default:
        errno = EBADF;
        return -1;
    }
    return len;
}
