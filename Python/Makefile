RED="\e[91m"
GREEN="\e[92m"
RESET="\e[0m"

CC = python3
COLLEEN = Colleen.py
GRACE = Grace.py
SULLY = Sully.py



all: Colleen Grace Sully

test:
			@echo "--- TESTING ---\n"
			@echo "COLLEEN"
			@$(CC) $(COLLEEN) > colleen.log
			@if (diff colleen.log Colleen.py); then \
        		echo $(GREEN)"[OK]"$(RESET); \
    		else \
        		echo $(RED)"[KO]"$(RESET); \
    		fi
			@echo "GRACE"
			@$(CC) $(GRACE)
			@if (diff Grace.py Grace_kid.py); then \
				echo $(GREEN)"[OK]"$(RESET); \
			else \
				echo $(RED)"[KO]"$(RESET); \
			fi
			@echo "SULLY"
			@$(CC) $(SULLY)
			@if test -f "Sully_0.py" && test -f "Sully_1.py" && test -f "Sully_2.py" && test -f "Sully_3.py" && test -f "Sully_4.py"; then \
				echo $(GREEN)"[OK]"$(RESET); \
			else \
				echo $(RED)"[KO]"$(RESET); \
			fi

Colleen:
			@$(CC) $(COLLEEN)

Grace:
			@$(CC) $(GRACE)

Sully:
			@$(CC) $(SULLY)

clean:
			@echo "Cleaning generated files"
			@rm -f Sully_* Grace_kid.py colleen.log

re		:	clean all

.PHONY:		all test colleen grace sully clean re