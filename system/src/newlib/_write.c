#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>
#include "UartConfig.h"

int _write(int file, char *ptr, int len)
{
    switch (file) {
    case STDOUT_FILENO: /*stdout*/
    	HAL_UART_Transmit(&UART2, ptr, len, 2000);
        break;
    case STDERR_FILENO: /* stderr */
    	HAL_UART_Transmit(&UART2, ptr, len, 2000);
        break;
    default:
        errno = EBADF;
        return -1;
    }
    return len;
}
