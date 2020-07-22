objects = rpn.o hash_table.o parser.o rpn_calculator.o  stack.o
COMPILER = clang
OUTPUT = rpn

all: rpn run

rpn: $(objects)
	$(COMPILER) -lm -o $(OUTPUT) $(objects)
rpn.o: rpn.c
	$(COMPILER) -c rpn.c
parser.o: src/parser.c includes/parser.h
	$(COMPILER) -c -g src/parser.c
rpn_calculator.o: src/rpn_calculator.c includes/rpn_calculator.h
	$(COMPILER) -c -g src/rpn_calculator.c
stack.o: src/stack.c includes/stack.h
	$(COMPILER) -c -g src/stack.c
hash_table.o: src/hash_table.c includes/hash_table.h
	$(COMPILER) -c -g src/hash_table.c
run:
	./$(OUTPUT) "1 SIN"
clean: object_clean
	rm $(OUTPUT)
object_clean:
	rm $(objects)
debug: rpn
	gdb $(OUTPUT)
