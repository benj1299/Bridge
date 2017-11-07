#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *InitList();
void InsertInList(Liste *liste, int nvNombre);
void DeleteInList(Liste *liste);
void ShowList(Liste *liste);

#endif
