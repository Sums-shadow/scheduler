#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSUS 100

struct processus {
    int pid;
    int T_traitement;
    int T_attente;
};

typedef struct processus Processus;


double MoyenneAttente;
int total_T_attente;

void Tri_Traitement(Processus p[], int n);
void CalculeT_attente(Processus p[], int n);
void AfficheGantt(Processus p[], int n);

int main()
{
    Processus p[MAX_PROCESSUS];
    int n, i, j;


    printf("Entrer le nombre de processus: ");
    scanf("%d", &n);
    printf("Entrer le nombre de traitement pour chaque processus:\n");
    for(i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &p[i].T_traitement);
        p[i].pid = i+1;
    }

    Tri_Traitement(p, n);
    CalculeT_attente(p, n);

    MoyenneAttente = (double) ( (double)total_T_attente / (double) n );

    puts("");
    printf("Temps Moyen d'attente: %.2lf\n",MoyenneAttente);

    printf("Diagramme de Gantt:\n");
    AfficheGantt(p, n);


    return 0;
}

void Tri_Traitement(Processus p[], int n)
{
    int i, j;
    Processus temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(p[j].T_traitement > p[j+1].T_traitement) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void CalculeT_attente(Processus p[], int n)
{
    int i;
    total_T_attente = 0;
    p[0].T_attente = 0;
    for(i=1; i<n; i++) {
        p[i].T_attente = p[i-1].T_attente + p[i-1].T_traitement;
        total_T_attente += p[i].T_attente;
    }
}

void AfficheGantt(Processus p[], int n)
{
    int i, j;
    int last = p[n-1].T_traitement + ( n== 1 ? 0 : p[n-1].T_attente);
     //Affichage au dessus
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].T_traitement; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    //Affichage du millieu
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].T_traitement-1; j++) printf(" ");
        printf("p%d", p[i].pid);
        for(j=0; j<p[i].T_traitement-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // Affichage en bas
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].T_traitement; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // Affichage temps d'attente
    int minus = 0;
    for(i=0; i<n; i++) {
        if(p[i].T_attente>9) printf(" ");
        printf("%d", p[i].T_attente);
        if(p[i+1].T_attente>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(j=0; j<p[i].T_traitement-minus; j++) printf("  ");

    }
    if(last>9) printf(" ");
    printf("%d\n", last);
}
