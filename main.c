#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMAX 255

int main()
{
	/* EXERCICE 1
	FILE *fichier = NULL;
	char AffichePhrase[TMAX];
	int i = 1;

	fichier = fopen("test.txt", "r");

	if(fichier != NULL)
	{
		while(!feof(fichier))
		{
			fgets(AffichePhrase, 80, fichier);
			if(!feof(fichier))
			{
				printf("%d %s", i, AffichePhrase);
			}
			i++;
		}
	}
	else
	{
		// On affiche un message d'erreur si on y arrive pas
		perror("L'erreur suivante s'est produite");
	}


	if(fichier != NULL)
	{
		fclose(fichier); // On ferme le fichier qui a été ouvert
	}*/

	char r;
	printf("Voulez vous entrer une nouvelle personne ? O / N\n");
	scanf("%c", &r);
	fflush(stdin);

	if(r == 'O' || r == 'o')
	{
		//EXERCICE 2
		FILE *pFile = NULL;
		char nom[20], prenom[15], numTel[11];
		int age;

		pFile = fopen("repertoire.txt", "a+");

		if(pFile != NULL)
		{
			printf("Veuillez entrer votre nom :\n");

	    	fgets(nom, 20, stdin);
			fputs(nom, pFile);
			fflush(stdin);

			printf("Veuillez entrer votre prenom :\n");

			fgets(prenom, 15, stdin);
			fputs(prenom, pFile);
			fflush(stdin);

			printf("Veuillez entrer votre age :\n");

			scanf("%d", &age);
			fprintf(pFile, "%d ans\n", age);
			fflush(stdin);

			printf("Veuillez entrer votre numero de telephone :\n");
			fgets(numTel, 11, stdin);
			fputs(numTel, pFile);
			fflush(stdin);

			fprintf(pFile, "\n\n");

			fclose(pFile);
		}else{
			perror("L'erreur suivante s'est produite");
		}
	}else if(r == 'N' || r == 'n'){
		//Exercice 3
		printf("-----------------------------------------------\n\n");

		FILE *xFile = NULL;
		char pPhrase[TMAX];
		char nomChercher[TMAX];
		int trouve = 0, comp;

		xFile = fopen("repertoire.txt", "r");

		printf("Veuillez entrer un nom à rechercher dans le répertoire\n");
		fgets(nomChercher, 20, stdin);

		if(xFile != NULL)
		{
			while(!feof(xFile) || trouve < 0)
			{
				fgets(pPhrase, 20, xFile);

				comp = strcmp(nomChercher, pPhrase);

				if(comp == 0)
				{
					printf("Personne trouve :\n");
					printf("Nom : %s", pPhrase);
					
					fgets(pPhrase, 15, xFile);
					printf("Prenom : %s", pPhrase);

					fgets(pPhrase, 10, xFile);
					printf("Age : %s", pPhrase);

					fgets(pPhrase, 11, xFile);
					printf("Numero de telephone : %s", pPhrase);

					trouve = 1;
				}
			}

			fclose(xFile);
		}else{
			perror("L'erreur suivante s'est produite");
		}
	}else{
		printf("Une erreur s'est produite\n");
	}

	return 0;
}
