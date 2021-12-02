programa.exe : main.o alumnos_regulares.o alumnos_egresados.o alumnos_titulados.o ramos_regular_egresados.o ramos_titular.o notas.o tesis.o
	g++ -o programa.exe main.o alumnos_regulares.o alumnos_egresados.o alumnos_titulados.o ramos_regular_egresados.o ramos_titular.o notas.o tesis.o
main.o: main.cc alumnos_regulares.o alumnos_egresados.o alumnos_titulados.o ramos_regular_egresados.o ramos_titular.o notas.o tesis.o
	g++ main.cc -c -o main.o
alumnos_regulares.o: alumnos_regulares.h alumnos_regulares.cc
	g++ alumnos_regulares.cc -c -o alumnos_regulares.o
alumnos_egresados.o: alumnos_egresados.h alumnos_egresados.cc
	g++ alumnos_egresados.cc -c -o alumnos_egresados.o
alumnos_titulados.o: alumnos_titulados.h alumnos_titulados.cc
	g++ alumnos_titulados.cc -c -o alumnos_titulados.o
ramos_regular_egresados.o: ramos_regular_egresados.h ramos_regular_egresados.cc
	g++ ramos_regular_egresados.cc -c -o ramos_regular_egresados.o
ramos_titular.o: ramos_titular.h ramos_titular.cc
	g++ ramos_titular.cc -c -o ramos_titular.o
notas.o: notas.h notas.cc
	g++ notas.cc -c -o notas.o
tesis.o: tesis.h tesis.cc
	g++ tesis.cc -c -o tesis.o
all:	
	make