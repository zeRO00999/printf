#include "main.h"
/**
 * replica of printf function
 */
int _printf(const char *format, ...)
{
	int chap = 0;

	va_list the_list;

	if(format == NULL)
		return -1;

	va_start(the_list, format);

	while(*format){
		if (*format != "%"){
		write(1, format, 1)
		chap++;	
		}
		else {
		format++;
		
		if (format == '\0'){
		break;
		}
		if (format == '%'){
		write(1, format, 1);
		chap++;
		}
		else if (*format == 'c'){
		char c = va_arg(the_list, int);
		write(1, &c,1);
		chap++;
		}

		else if (format == 's'){
			char *str = va_arg(the_list, char*);
			int str_len = 0;
			while(str(str_len) != '\0')
			write(1, str, str_len);
			chap += str_len;
		}


	
	}
		format++;
	}
		

		va_end(the_list);
	return chap;

}
