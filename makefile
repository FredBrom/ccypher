all:
	cc -c -I ./include -o ./obj/cesarCypher.o ./src/cesarCypher.c
	cc -I ./include -o ./bin/ccypher ./obj/cesarCypher.o ./app/main.c
	cp ./bin/ccypher .

clean:
	rm -rf ./obj/* ./bin/*


run:
	./bin/main
