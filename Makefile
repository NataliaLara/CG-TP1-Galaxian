all: galaxian run

galaxian:	
	gcc galaxian.c -lSOIL -lglut -lGL -lGLEW -lGLU -o galaxian

run: 
	./galaxian

clean:
	rm -rf galaxian