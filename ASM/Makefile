RED="\e[91m"
GREEN="\e[92m"
RESET="\e[0m"

CC = gcc -Wall -Wextra -Werror -no-pie -g

COLLEEN = Colleen.s
GRACE = Grace.s
# SULLY = Sully.s


C_OBJS = $(COLLEEN:.s=.o)
G_OBJS = $(GRACE:.s=.o)
# S_OBJS = $(SULLY:.s=.o)

%.o: %.s
	@nasm -f elf64 -o $*.o $*.s

all: Colleen Grace #sully

test:	Colleen Grace
		@echo "--- TESTING ---\n"
		@echo "COLLEEN"
		@./Colleen > Colleen.log
		@if (diff Colleen.log Colleen.s); then \
			echo $(GREEN)"[OK]"$(RESET); \
		else \
			echo $(RED)"[KO]"$(RESET); \
		fi
		@echo "GRACE"
		@./Grace
		@if (diff Grace.s Grace_kid.s); then \
			echo $(GREEN)"[OK]"$(RESET); \
		else \
			echo $(RED)"[KO]"$(RESET); \
		fi

Colleen: $(C_OBJS)
		@$(CC) $(C_OBJS) -o Colleen
		@echo "Compil Colleen -> "$(GREEN)"[OK]"$(RESET); \

Grace: $(G_OBJS)
		@$(CC) $(G_OBJS) -o Grace
		@echo "Compil Grace -> "$(GREEN)"[OK]"$(RESET); \

# Sully: $(S_OBJS)
# 		@$(CC) $(S_OBJS) -o Sully
# @echo "Compil Sully -> "$(GREEN)"[OK]"$(RESET); \

clean:
			@echo "Cleaning all generated files"
			@rm -f Sully_* Grace_kid.s Colleen.log *.o Colleen Grace

re		:	clean all

.PHONY:		all test colleen grace sully clean re