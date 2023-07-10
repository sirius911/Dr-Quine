RED="\033[1;31m"
GREEN="\033[92m"
RESET="\033[0m"

SHELL := /bin/bash

CC = gcc -Wall -Wextra -Werror -no-pie

COLLEEN = Colleen.s
GRACE = Grace.s
SULLY = Sully.s


C_OBJS = $(COLLEEN:.s=.o)
G_OBJS = $(GRACE:.s=.o)
S_OBJS = $(SULLY:.s=.o)

%.o: %.s
	@nasm -f elf64 -o $*.o $*.s

all: Colleen Grace Sully

test_all:		test_colleen test_grace test_sully

test_colleen:	Colleen
				@echo "COLLEEN"
				@./Colleen > colleen.log
				@if (diff colleen.log Colleen.s); then \
					echo -e $(GREEN)"[OK]"$(RESET); \
				else \
					echo -e $(RED)"[KO]"$(RESET); \
				fi
				@rm -f Colleen colleen.log Colleen.o

test_grace:		Grace
				@echo "GRACE"
				@./Grace
				@if (diff Grace.s Grace_kid.s); then \
					echo -e $(GREEN)"[OK]"$(RESET); \
				else \
					echo -e $(RED)"[KO]"$(RESET); \
				fi
				@rm -f Grace Grace.o Grace_kid.s

test_sully:		Sully
				@echo "SULLY"
				@./Sully
				@for i in 5 4 3 2 1 0 ; do \
					echo -n "Sully_"$$i".s... "; \
					if [ ! -f "Sully_$${i}.s" ]; then \
						echo $(RED)"[NOT FOUND]"$(RESET); \
					else \
						diff Sully.s "Sully_$$i".s | wc -l > nb_diff.txt; \
						diff Sully.s "Sully_$$i".s | tail -n -1 | sed -n -E 's/.*mov r12, (-?[0-5]).*/\1/p' > tmp.txt; \
						result_diff=$$(cat tmp.txt); \
						result=$$(expr $$result_diff + 1); \
						nb_diff=$$(cat nb_diff.txt); \
						if [ "$$result" -eq "$$i" -a "$$nb_diff" -eq 4 ]; then \
							echo -e $(GREEN)"[OK]"$(RESET); \
						else \
							echo -e $(RED)"[KO]"$(RESET); \
							diff Sully.s "Sully_$$i".s; \
						fi; \
					fi; \
					rm -f tmp.txt nb_diff.txt; \
				done
				@rm -f  Sully Sully_* Sully.o

Colleen: $(C_OBJS)
		@$(CC) $(C_OBJS) -o Colleen
		@echo -e "Compil Colleen -> "$(GREEN)"[OK]"$(RESET); \

Grace: $(G_OBJS)
		@$(CC) $(G_OBJS) -o Grace
		@echo -e "Compil Grace -> "$(GREEN)"[OK]"$(RESET); \

Sully: $(S_OBJS)
		@$(CC) $(S_OBJS) -o Sully
		@rm -f Sully.o
		@echo -e "Compil Sully -> "$(GREEN)"[OK]"$(RESET); \

clean:
			@echo "Cleaning all generated files"
			@rm -f Sully_* Grace_kid.s colleen.log *.o *.tmp

fclean:		clean
			@rm -f Colleen Grace Sully

re		:	clean all

.PHONY:		all Colleen Grace Sully clean fclean re test_all test_colleen test_grace test_sully