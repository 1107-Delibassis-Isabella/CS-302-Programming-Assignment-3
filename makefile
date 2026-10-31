PA3: main.o LinkedQueue.o LinkedStack.o Tokenizer.o
	g++ main.o Tokenizer.o -o PA3

main.o: main.cpp Tokenizer.h
	g++ -c main.cpp

Tokenizer.o: Token.h Tokenizer.h Tokenizer.cpp
	g++ -c Tokenizer.cpp

LinkedQueue.o: Node.h LinkedQueue.h LinkedQueue.cpp
	g++ -c LinkedQueue.cpp

LinkedStack.o: Node.h LinkedStack.h LinkedStack.cpp
	g++ -c LinkedStack.cpp

clean: 
	rm *.o PA3