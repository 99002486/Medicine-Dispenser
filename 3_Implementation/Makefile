SRC = main.c \
	src/peripheralinitializer.c \
	src/medstime.c

INC = -Iinc

TARGETNAME = medicinedispenser


all:
	gcc ${SRC} ${INC} -o ${TARGETNAME}.out -static

clean:
	rm *.out
