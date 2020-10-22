all: galaxian 

galaxian:
	gcc galaxian.c -lSOIL -lglut -lGL -lGLEW -lGLU -o galaxian
	./galaxian
	rm -rf galaxian

clean:
	rm -rf galaxian