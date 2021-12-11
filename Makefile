prog.exe: main.o lista_alum_regular.o lista_alum_egresado.o alumnos_regulares.o alumnos_egresados.o alumnos_titulados.o ramos_regular_egresados.o lista_ramos_regular_egresados.o ramos_titular.o lista_ramos_titular.o lista_alum_titulado.o
	g++ -o prog.exe build/main.o build/lista_alum_regular.o build/lista_alum_egresado.o build/alumnos_regulares.o build/alumnos_egresados.o build/alumnos_titulados.o build/ramos_regular_egresados.o build/lista_ramos_regular_egresados.o build/ramos_titular.o  build/lista_ramos_titular.o build/lista_alum_titulado.o

main.o: main.cc lista_alum_regular.o alumnos_regulares.o ramos_regular_egresados.o lista_ramos_regular_egresados.o ramos_titular.o lista_ramos_titular.o alumnos_egresados.o alumnos_titulados.o lista_alum_titulado.o
	g++ main.cc -c -o build/main.o

alumnos_regulares.o: alumnos/alumnos_regulares.h alumnos/alumnos_regulares.cc
	g++ alumnos/alumnos_regulares.cc -c -o build/alumnos_regulares.o

alumnos_egresados.o: alumnos/alumnos_egresados.h alumnos/alumnos_egresados.cc alumnos_regulares.o
	g++ alumnos/alumnos_egresados.cc -c -o build/alumnos_egresados.o

alumnos_titulados.o: alumnos/alumnos_titulados.h alumnos/alumnos_titulados.cc alumnos_egresados.o
	g++ alumnos/alumnos_titulados.cc -c -o build/alumnos_titulados.o

lista_alum_regular.o: listas/lista_alum_regular.h listas/lista_alum_regular.cc alumnos_regulares.o
	g++ listas/lista_alum_regular.cc -c -o build/lista_alum_regular.o

lista_alum_egresado.o: listas/lista_alum_egresado.h listas/lista_alum_egresado.cc alumnos_egresados.o
	g++ listas/lista_alum_egresado.cc -c -o build/lista_alum_egresado.o

lista_alum_titulado.o: listas/lista_alum_titulados.h listas/lista_alum_titulados.cc alumnos_titulados.o
	g++ listas/lista_alum_titulados.cc -c -o build/lista_alum_titulado.o

ramos_regular_egresados.o: ramos/ramos_regular_egresados.h ramos/ramos_regular_egresados.cc
	g++ ramos/ramos_regular_egresados.cc -c -o build/ramos_regular_egresados.o

lista_ramos_regular_egresados.o: listas/lista_ramos_regular_egresados.h listas/lista_ramos_regular_egresados.cc ramos_regular_egresados.o
	g++ listas/lista_ramos_regular_egresados.cc -c -o build/lista_ramos_regular_egresados.o

ramos_titular.o: ramos/ramos_titular.h ramos/ramos_titular.cc ramos_regular_egresados.o
	g++ ramos/ramos_titular.cc -c -o build/ramos_titular.o

lista_ramos_titular.o: listas/lista_ramos_titular.h listas/lista_ramos_titular.cc ramos_titular.o
	g++ listas/lista_ramos_titular.cc -c -o build/lista_ramos_titular.o

all:
	rm build/*
	make