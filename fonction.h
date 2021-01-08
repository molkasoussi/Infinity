
typedef struct 
{ 	char jour [30];
 	char  mois[30];
	char annee[30];
	char  id [30];
	char  val [30];
}abscence ;
typedef struct
{
    char jour[30];
    char mois[30];
    char annee[30];
}date;

typedef struct 
{
char identifiant[30];
char Nom[30];
char Prenom[30];
char Cin[30];
char Sexe[30];

date naissance;
} ouvrier;

void ajouter (ouvrier t );
int exister (char*identifiant);
void supprimer (char identifiant[]);
void modifer(char ch[] ,ouvrier t2);
void afficher(GtkWidget* treeview1 ,char *l);
void rechercher_ouv(char identifiant[],GtkWidget *liste);



void afficher_abs(GtkWidget* treeview2,char *l);
void remplir(abscence a);
float taux_absc(char annee[]);
//float taux_absc(char ouvrier[] , char abs[] , int annee);
