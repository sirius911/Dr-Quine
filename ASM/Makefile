RED="\e[91m"
GREEN="\e[92m"
RESET="\e[0m"

CC = gcc -Wall -Wextra -Werror -no-pie

COLLEEN = Colleen.s
# SULLY = Sully.s
# GRACE = Grace.s

C_OBJS = $(COLLEEN:.s=.o)
# G_OBJS = $(GRACE:.s=.o)
# S_OBJS = $(SULLY:.s=.o)

%.o: %.s
	@nasm -f elf64 -o $*.o $*.s

all: colleen #grace sully

test:	Colleen
		@./Colleen > Colleen.log
		@if (diff Colleen.log Colleen.s); then \
			echo $(GREEN)"[OK]"$(RESET); \
		else \
			echo $(RED)"[KO]"$(RESET); \
		fi

colleen: $(C_OBJS)
		@$(CC) $(C_OBJS) -o Colleen
		@echo "Compil Colleen -> "$(GREEN)"[OK]"$(RESET); \

# grace: $(G_OBJS)
# 		@$(CC) $(G_OBJS) -o grace

# sully: $(S_OBJS)
# 		@$(CC) $(S_OBJS) -o sully

clean:
			@echo "Cleaning all generated files"
			@rm -f Sully_* Grace_kid.s Colleen.log *.o Colleen colleen

re		:	clean all

.PHONY:		all test colleen grace sully clean re