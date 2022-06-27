all:
	@gcc -Wall -Werror -Wextra -g *.c
	./a.out /bin/ls ../ "|" /bin/cat -e ";" /bin/echo test
db:
	@valgrind ./a.out /bin/ls ../ "|" /bin/cat -e ";" /bin/echo test
