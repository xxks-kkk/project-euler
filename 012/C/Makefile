C_COMPILER=gcc
CFLAGS = -Wall -g

SRC_FILES=\
  $(wildcard ./*.c) \

LIBS=\
  -lm

OUTPUT_FILE=main

.PHONY: clean
.PHONY: test

test:
	$(C_COMPILER) $(CFLAGS) $(LIBS) $(SRC_FILES) -o $(OUTPUT_FILE)
	./$(OUTPUT_FILE) -v

clean:
	rm -rf $(OUTPUT_FILE)
