PA3: main.o LinkedStack.o LinkedQueue.o Tokenizer.o
	g++ -o PA3 main.o LinkedStack.o LinkedQueue.o Tokenizer.o

main.o: main.cpp LinkedStack.h LinkedQueue.h Node.h Token.h Tokenizer.h
	g++ -c main.cpp

LinkedStack.o: LinkedStack.cpp LinkedStack.h Node.h
	g++ -c LinkedStack.cpp

LinkedQueue.o: LinkedQueue.cpp LinkedQueue.h Node.h
	g++ -c LinkedQueue.cpp

Tokenizer.o: Tokenizer.cpp Tokenizer.h Token.h LinkedStack.h LinkedQueue.h Node.h
	g++ -c Tokenizer.cpp

clean: 
	rm *.o PA3