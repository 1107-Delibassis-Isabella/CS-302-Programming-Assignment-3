PA3: main.o 
	g++ -o PA3 main.o

main.o: main.cpp LinkedStack.h LinkedQueue.h Node.h Token.h Tokenizer.h
	g++ -c main.cpp

clean: 
	rm *.o PA3