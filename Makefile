all:coincasino.c bank.c
	gcc coincasino.c -s -o coincasino
	gcc bank.c -s -o bank

coincasino:coincasino.c
	gcc coincasino.c -s -o coincasino

bank:bank.c
	gcc bank.c -s -o bank
