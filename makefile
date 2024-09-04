OBJ = main.o entrada.o saida.o processamento.o tratamento.o


main: $(OBJ)
	cc -O2 -funroll-loops -Ofast -flto -finline-functions -Wall $(OBJ) -o main $(LIBS)

main.o:

leitura.o: leitura.h

saida.o: saida.h

processamento.o: processamento.h

tratamento.o: tratamento.h

.PHONY: clean

clean:
	rm main $(OBJ)