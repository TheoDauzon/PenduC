#include <stdio.h>
#include <stdbool.h>

// prototypes des fonctions
int indice_lettre(char lettre); //fonction
void initialisation_mot_a_trouver(char Tmot[8]); //procédure
void initialisation_mot_a_completer(char Tmot[8]); //procédure

int main()
{
    // LEXIQUE
    char motT[8];
    char motC[8];
    char alpha[26];
    bool trouver;
    int i;
    int nbErreur;
    int nbCoups;
    char lettre;
    int placeLettre;
    int nbLettreBon;

    // DEBUT
    nbErreur=0;
    nbCoups=0;
    nbLettreBon=0;
    initialisation_mot_a_trouver(motT);
    initialisation_mot_a_completer(motC);

    for(i=0 ; i< 26 ; i++)
    {
        alpha[i]='N';
    }

    do
    {
        printf("Mot : \n");
        for(i=0 ; i< 8 ; i++)
        {
            printf("%c",motC[i]);
        }
        printf(("\nErreur : %d \n"),nbErreur);
        do
        {
            printf("Donnez une lettre : \n");
            scanf ("%c", &lettre);
            getchar();
        } while (lettre <='A' && lettre >='Z');

        placeLettre=indice_lettre(lettre);

        if (alpha[placeLettre]=='N')
        {
            alpha[placeLettre]='U';
            trouver=false;
            nbCoups=nbCoups+1;
            for(i=0 ; i< 8 ; i++)
            {
                if(lettre==motT[i])
                {
                    motC[i]=lettre;
                    nbLettreBon=nbLettreBon+1;
                    trouver=true;
                }

            }
            if (!trouver)
            {
                nbErreur=nbErreur+1;
            }
        }else
        {
            printf("Lettre déjà donnée !\n");
        }
    } while (nbErreur != 6 && nbLettreBon !=8);

    if(nbErreur==6)
    {
        printf("Perdu !\n");
    }else{
        printf("Bravo vous avez trouvé le mot !\n");
        for(i=0 ; i< 8 ; i++)
        {
            printf("%c",motT[i]);
        }
        printf(("en %d coups\n"), nbCoups);
    }

    return 0;
}

// définitions des fonctions

int indice_lettre(char lettre)
{
    int i,indice ;
    indice = 0 ; i = (int)lettre ; i=i-65;
    indice = indice+i;
    return indice;
}

void initialisation_mot_a_trouver(char Tmot[8])
{
    Tmot[0]='A';
    Tmot[1]='C';
    Tmot[2]='C';
    Tmot[3]='R';
    Tmot[4]='O';
    Tmot[5]='C';
    Tmot[6]='H';
    Tmot[7]='E';
}

void initialisation_mot_a_completer(char Tmot[8])
{
    int i;
    for(i=0 ; i< 8 ; i++)
    {
        Tmot[i]='*';
    }
}
