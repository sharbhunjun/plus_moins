#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int plus_moins(int choix_joueur, int valeur_a_trouver){

	if(choix_joueur<valeur_a_trouver)
	{
		printf("C'est plus !\n");
		return 0;
	}
	else if (choix_joueur>valeur_a_trouver)
	{
		printf("C'est moins !\n");
		return 0;
	}
	else
		printf("bingo\n");
		return 1;
}

int generate_guess(){
	srand(time(NULL));
	return rand()%101;
}

int main()
{

	int win=0;
	//int guess=generate_guess();
	printf("%d\n",guess);
	int nombre_de_tour;
	int difficulte;
	printf("choisissez un mode de difficulte:\n");
	printf("1-facile\n");
	printf("2-moyen\n");
	printf("3-difficile\n");
	scanf("%d",&difficulte);
	switch(difficulte){
	case 1:
		nombre_de_tour=25;
		break;
	case 2:
		nombre_de_tour=10;
		break;
	case 3:
		nombre_de_tour=5;
		break;
	default:
		printf("Vous devez choisir entre 1 2 ou 3\n");
		exit(0);
	}

	int choix_joueur;
	int tours=0;
	printf("Devinez un nombre entre 0 et 100:\n");
	while(tours<nombre_de_tour && !win){
		scanf("%d",&choix_joueur);
		win=plus_moins(choix_joueur, guess);
		tours++;
	}
	if(!win && tours>nombre_de_tour)
		printf("perdu il fallait trouver %d\n",guess);
}
