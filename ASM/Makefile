RED="\e[91m"
GREEN="\e[92m"
RESET="\e[0m"

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

test:	Colleen Grace Sully
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
		@echo "SULLY"
		@./Sully
		@for i in 4 3 2 1 0 ; do \
			echo -n "Sully_"$$i".s... "; \
			if [ ! -f "Sully_$${i}.s" ]; then \
				echo $(RED)"[NOT FOUND]"$(RESET); \
			else \
				diff Sully.s "Sully_$$i".s | wc -l > nb_diff.txt; \
				diff Sully.s "Sully_$$i".s | tail -n -1 | sed -n 's/.*mov r12, \([0-4]\).*/\1/p' > tmp.txt; \
				result_diff=$$(cat tmp.txt); \
				nb_diff=$$(cat nb_diff.txt); \
				if [ "$$result_diff" -eq "$$i" -a "$$nb_diff" -eq 4 ]; then \
					echo $(GREEN)"[OK]"$(RESET); \
				else \
					echo $(RED)"[KO]"$(RESET); \
					diff Sully.s "Sully_$$i".s; \
				fi; \
			fi; \
			rm -f tmp.txt nb_diff.txt; \
		done

Colleen: $(C_OBJS)
		@$(CC) $(C_OBJS) -o Colleen
		@echo "Compil Colleen -> "$(GREEN)"[OK]"$(RESET); \

Grace: $(G_OBJS)
		@$(CC) $(G_OBJS) -o Grace
		@echo "Compil Grace -> "$(GREEN)"[OK]"$(RESET); \

Sully: $(S_OBJS)
		@$(CC) $(S_OBJS) -o Sully
		@echo "Compil Sully -> "$(GREEN)"[OK]"$(RESET); \

clean:
			@echo "Cleaning all generated files"
			@rm -f Sully_* Grace_kid.s Colleen.log *.o Colleen Grace Sully

re		:	clean all

.PHONY:		all test colleen grace sully clean re