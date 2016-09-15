/**
 * \file bsp10077.c
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING 81

main(int argc,char *argv[]) {
	FILE *stream;
	char puffer[MAX_STRING];
	int ch;
	/* Ist kein Kommandozeilenparameter vorhanden? */
	if(argc < 2) {
		printf("\nAufruf: bspl0077 <dateiname>\n");
		exit(1);
	}
	/* Ist die Datei nicht vorhanden ? */
	if((stream = fopen(argv[1],"r")) == NULL) {
		printf("\n'%s': Oeffnungsfehler!\n",argv[1]);
		exit(1);
	}
	while(fgets(puffer,MAX_STRING,stream)!=NULL) {
		printf("%s",puffer);
		ch=fgetc(stdin);    /* Warte auf Tastendruck */
		switch(ch) {
			/* zurück zum Anfang */
			case 'a':
			case 'A':
				fseek(stream,0L,SEEK_SET);
				break;
			/* Abbruch */
			case 27:
				goto ende;
		}
		fseek(stdin,0L,SEEK_END);
	}
	ende:
	fclose(stream);
}

