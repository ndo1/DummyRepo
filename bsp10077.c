/**
 * \file bsp10077.c
 *
 * \brief Short description
 *
 * Detailed description
 *
 * \version $Revision: $ (SVN)
 * \date June 7, 2016
 * \author dog, Automatek GmbH
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * \brief main
 * 
 * Usage:
 *    add usage manual here
 * Arguments:
 *    arg1 - ...
 *    arg2 - ...
 *    argN - ...
 * 
 * \return Exit codes:
 * \return 0 - Successful termination.
 * \return ...
 * \return ...
 * \author dog, Automatek GmbH
 */
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

