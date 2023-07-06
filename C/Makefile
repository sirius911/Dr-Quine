RED="\033[1;31m"
GREEN="\033[92m"
RESET="\033[0m"

CC = gcc -Wextra -Werror -Wall

COLLEEN = Colleen.c
GRACE = Grace.c
SULLY = Sully.c

SHELL := /bin/bash

C_OBJS		= $(COLLEEN:.c=.o)
G_OBJS		= $(GRACE:.c=.o)
S_OBJS		= $(SULLY:.c=.o)

all: Colleen Grace Sully

test_all:		test_colleen test_grace test_sully

test_colleen:	Colleen
				@echo "COLLEEN"
				@./Colleen > colleen.log
				@if (diff colleen.log Colleen.c); then \
					echo -e $(GREEN)"[OK]"$(RESET); \
				else \
					echo -e $(RED)"[KO]"$(RESET); \
				fi
				@rm -f Colleen colleen.log Colleen.o

test_grace:		Grace
				@echo "GRACE"
				@./Grace
				@if (diff Grace.c Grace_kid.c); then \
					echo -e $(GREEN)"[OK]"$(RESET); \
				else \
					echo -e $(RED)"[KO]"$(RESET); \
				fi
				@rm -f Grace Grace.o Grace_kid.c

diff_check:
			@for i in $$(seq 0 4); do \
				echo -n "       Checking Sully.c vs Sully_$$i.c ... "; \
				diff_output=$$(diff Sully.c Sully_$$i.c | grep -vE '^>|^---|^<'); \
				line_count=$$(echo "$$diff_output" | wc -l); \
				if [ "$$line_count" -eq 1 ]; then \
					if [ "$$diff_output" = "5c5" ]; then \
						echo -e $(GREEN)"[OK]"$(RESET); \
					else \
						echo -e $(RED)"[KO]"$(RESET); \
					fi \
        		else \
           			echo -e $(RED)"[KO]"$(RESET); \
        		fi \
			done

test_sully:		Sully
				@echo "SULLY"
				@./Sully
				@echo -n " --> Duplicate files ... "; \
				if test -f "Sully_0.c" && test -f "Sully_1.c" && test -f "Sully_2.c" && test -f "Sully_3.c" && test -f "Sully_4.c"; then \
					echo -e $(GREEN)"[OK]"$(RESET); \
					$(MAKE) -s diff_check; \
				else \
					echo -e $(RED)"[KO]"$(RESET); \
				fi
				@rm -f Sully Sully_*

Colleen: 	$(C_OBJS)
			@$(CC) -o Colleen $(C_OBJS)

Grace: 		$(G_OBJS)
			@$(CC) -o Grace $(G_OBJS)

Sully: 		$(S_OBJS)
			@$(CC) -o Sully $(S_OBJS)

clean:
			@echo "Cleaning all generated files"
			@rm -f *.o Sully_* Grace_kid.c colleen.log

fclean:		clean
			@rm -f Colleen Grace Sully

re		:	fclean all

.PHONY:		all test Colleen Grace Sully clean fclean re test_all test_colleen test_grace test_sully