all:
	cc -Wall -c -I ./include -o ./obj/cesarCypher.o ./src/cesarCypher.c
	cc -Wall -I ./include -o ./bin/ccypher ./obj/cesarCypher.o ./app/main.c
	cp ./bin/ccypher .

clean:
	rm -rf ./obj/* ./bin/*
	rm ccypher

run:
	./bin/main
