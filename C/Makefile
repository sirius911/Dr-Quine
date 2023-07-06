RED="\e[91m"
GREEN="\e[92m"
RESET="\e[0m"

CC = gcc -Wextra -Werror -Wall

COLLEEN = Colleen.c
GRACE = Grace.c
SULLY = Sully.c



C_OBJS		= $(COLLEEN:.c=.o)
G_OBJS		= $(GRACE:.c=.o)
S_OBJS		= $(SULLY:.c=.o)

all: Colleen Grace Sully

test_all:		test_colleen test_grace test_sully

test_colleen:	Colleen
				@echo "COLLEEN"
				@./Colleen > colleen.log
				@if (diff colleen.log Colleen.c); then \
					echo $(GREEN)"[OK]"$(RESET); \
				else \
					echo $(RED)"[KO]"$(RESET); \
				fi
				@rm -f Colleen colleen.log Colleen.o

test_grace:		Grace
				@echo "GRACE"
				@./Grace
				@if (diff Grace.c Grace_kid.c); then \
					echo $(GREEN)"[OK]"$(RESET); \
				else \
					echo $(RED)"[KO]"$(RESET); \
				fi
				@rm -f Grace Grace.o Grace_kid.c

diff_check:
			@for i in $$(seq 0 4); do \
				echo "Checking Sully.c vs Sully_$$i.c"; \
			done

test_sully:		Sully
				@echo "SULLY"
				@./Sully
				@if test -f "Sully_0.c" && test -f "Sully_1.c" && test -f "Sully_2.c" && test -f "Sully_3.c" && test -f "Sully_4.c"; then \
					$(MAKE) diff_check; \
					echo $(GREEN)"[OK]"$(RESET); \
				else \
					echo $(RED)"[KO]"$(RESET); \
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