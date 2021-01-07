
typedef struct
{
    char jour[30];
    char mois[30];
    char annee[30];
}date;

typedef struct
{ 
	char typ[20];    //type de plante
	char mature[20]; //dureé de maturation
	char esp[20]; //escpacement entre les plantes
	char id[20];//identifant de la plante 
	date plantation;
	
}plante;


void afficher_plante();
void ajout_plante(plante p);
void supprimer_plante(char id[20]);
void modifer_plante(char id[] ,plante p2);
void afficher(GtkWidget* treeview1 ,char *l);
void rechercher_ouv(char Id[30],GtkWidget *liste);
int deffectueux (int iden [], char *fichier, float minv , float maxv );



