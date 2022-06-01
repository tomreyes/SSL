tablaDeConversion.exe: tablaDeConversion.o conversion.o
	gcc tablaDeConversion.o conversion.o -o tablaDeConversion.exe

conversionTest.exe: conversionTest.o conversion.o
	gcc conversionTest.o conversion.o -o conversionTest.exe

conversionTest.o: conversion.c conversion.h
	gcc -c conversionTest.c -o conversionTest.o

conversion.o: conversion.c conversion.h
	gcc -c conversion.c -o conversion.o

tablaDeConversion.o: tablaDeConversion.c conversion.h
	gcc -c tablaDeConversion.c -o tablaDeConversion.o

clean:
	rm -f conversionTest.o
	rm -f conversion.o
	rm -f tablaDeConversion.o
	rm -f conversionTest.exe
	rm -f tablaDeConversion.exe