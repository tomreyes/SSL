tablaDeConversion.exe: tablaDeConversion.o 
	gcc tablaDeConversion.o conversion.o -o tablaDeConversion.exe

#conversion.o: conversion.c conversion.h
conversion.o: conversion.c
	gcc -c conversion.c -o conversion.o

tablaDeConversion.o: tablaDeConversion.c conversion.h
	gcc -c tablaDeConversion.c -o tablaDeConversion.o

