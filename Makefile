SOURCE = ./src/main.c ./src/table.c
OBJECT = ./.object/main.o ./.object/table.o
OUTPUT = ./bin/table


mkobj: 
	clang -Wall -c $(SOURCE)

link: 
	clang -o $(OUTPUT) $(OBJECT)

clean:
	rm *.o