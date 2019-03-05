OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: program.o Parell_cromosoma.o Individu.o Cjt_individus.o Dades.o
	g++ -o program.exe program.o Parell_cromosoma.o Individu.o Cjt_individus.o Dades.o
	rm *.o

program.o:
	g++ -c program.cc $(OPTIONS)

Dades.o:
	g++ -c Dades.cc $(OPTIONS)

Cjt_individus.o:
	g++ -c Cjt_individus.cc $(OPTIONS)

Individu.o:
	g++ -c Individu.cc $(OPTIONS)

Parell_cromosoma.o:
	g++ -c Parell_cromosoma.cc $(OPTIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
