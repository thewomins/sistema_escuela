prog.exe: main.o listas.o alumnos_regulares.o alumnos_egresados.o alumnos_titulados.o ramos_regular_egresados.o ramos_titular.o notas.o tesis.o
	g++ -o prog.exe build/main.o build/listas.o build/alumnos_regulares.o build/alumnos_egresados.o build/alumnos_titulados.o build/ramos_regular_egresados.o build/ramos_titular.o build/notas.o build/tesis.o

main.o: main.cc listas.o alumnos_regulares.o alumnos_egresados.o alumnos_titulados.o ramos_regular_egresados.o ramos_titular.o notas.o tesis.o
	g++ main.cc -c -o build/main.o

listas.o: listas.h listas.cc alumnos_regulares.o alumnos_egresados.o alumnos_titulados.o ramos_regular_egresados.o ramos_titular.o
	g++ listas.cc -c -o build/listas.o

alumnos_regulares.o: alumnos/alumnos_regulares.h alumnos/alumnos_regulares.cc ramos_regular_egresados.o
	g++ alumnos/alumnos_regulares.cc -c -o build/alumnos_regulares.o

alumnos_egresados.o: alumnos/alumnos_egresados.h alumnos/alumnos_egresados.cc alumnos_regulares.o ramos_regular_egresados.o
	g++ alumnos/alumnos_egresados.cc -c -o build/alumnos_egresados.o

alumnos_titulados.o: alumnos/alumnos_titulados.h alumnos/alumnos_titulados.cc ramos_titular.o alumnos_egresados.o tesis.o
	g++ alumnos/alumnos_titulados.cc -c -o build/alumnos_titulados.o

ramos_regular_egresados.o: ramos/ramos_regular_egresados.h ramos/ramos_regular_egresados.cc notas.o
	g++ ramos/ramos_regular_egresados.cc -c -o build/ramos_regular_egresados.o

ramos_titular.o: ramos/ramos_titular.h ramos/ramos_titular.cc ramos_regular_egresados.o notas.o
	g++ ramos/ramos_titular.cc -c -o build/ramos_titular.o

notas.o: notas/notas.h notas/notas.cc
	g++ notas/notas.cc -c -o build/notas.o

tesis.o: tesis/tesis.h tesis/tesis.cc
	g++ tesis/tesis.cc -c -o build/tesis.o

all:
	rm build/*
	make