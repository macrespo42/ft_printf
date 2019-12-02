# ft_printf

Its a partial reproduction of printf from C stdio library (man 3 printf).

ft_printf supports these conversions :

* d/i (int)
* u (unsigned int)
* s (string)
* c (char)
* x/X (hexadecimal)
* p (adress)

and following flags :

* width
* precision
* 0
* -

## How to use

use `make` for compile the project and get libftprintf.a
after you can use it like this : `clang yourfile.c -L. libftprintf.a`
for example
