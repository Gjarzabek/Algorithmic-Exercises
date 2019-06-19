#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct osoba
{
    int numer;
    bool is_vip;
    struct osoba * next;
    struct osoba * prev;
}osoba;

typedef struct pik
{
    osoba * start;
    osoba * koniec;
} kolejka;

osoba* nowa_osoba (int x, bool is)
{
    osoba* nowa = malloc(sizeof(osoba));
    if(nowa)
    {
        nowa -> numer = x;
        nowa -> is_vip = is;
        nowa -> next = NULL;
        nowa -> prev = NULL;
    }
    else exit(1);
    return nowa;
}

void dodaj_osobe (osoba*os, kolejka * k)
{
    if (k->koniec == NULL && NULL == k->start) {
      k->koniec = k->start = os;
      k->start->prev = k->koniec;
      k->koniec->next = k->start;
    }
    if (!(os->is_vip))
    {
        os -> next = k ->koniec;
        os->prev = NULL;
        k->koniec->prev = os;
        k->koniec = os;
    }
    else {
        osoba* w = k->koniec;
        if (w) {
            while ((w->next)&&!(w->next->is_vip))
            {
                w = w->next;
            }
            os->next = w->next;
            os->prev = w;
            w->next = os;
        }
        else
        {
            k->koniec = os;
            k->start = os;
        }
    }
}

void usun_osobe(kolejka * k)
{
    if(!k||(k->start))
    {
        printf("Kolejka pusta!\n");
    }
    else{
        osoba* usuwana = k -> start;
        k->start = usuwana -> prev;
        k->start->next = NULL;
        free(usuwana);
    }
}

void wyswietl(kolejka *k)
{
  if(!k||!(k->start))
    {
        printf("Kolejka pusta!\n");
    }
    else {
            printf("Kolejka:\n");
            osoba * akt = k->start;
            while (akt)
            {

                akt->is_vip ?  printf("Jest VIPEM: %d", akt->numer) : printf("Nie jest Vipem : %d", akt->numer);
                akt = akt->next;
            }
    }
}

void wypisz_osobe (osoba *akt)
{
    if (!akt)
    {
        printf("brak osoby\n");
    }
    else {
          printf("kolejke opuszcza: ");
          akt->is_vip ?  printf("Jest VIPEM: %d", akt->numer) : printf("Nie jest Vipem : %d", akt->numer);
    }
}

kolejka * nowa_kolejka()
{
    kolejka * wsk = malloc(sizeof(kolejka));
    if (!wsk)
        exit(1);
    wsk->start = NULL;
    wsk->koniec = NULL;
    return wsk;
}
int sprawdz_scanf(char * prompt)
 {
     printf("%s", prompt);
     int k;
     while (0 > scanf("%d", &k)) {
        printf("Bledne dane - sprobuj jeszcze raz\n");
        while(getchar()!='\n');
        printf("%s", prompt);
    }
    return k;
 }

void menu() {
  bool finish = false;
  kolejka * queue = nowa_kolejka();
  while(!finish) {
    printf("Obluga kolejki\nD - dopisz N klientow zwyklych do kolejki\n");
    printf("U - dopisz N klientow uprzywilejowanych do kolejki\n");
    printf("O - obsluz N klientow\nQ - wyjscie\n");
    printf("Opcja: ");
    bool isVIP = false;
    switch (getchar()) {
      case 'U':
          isVIP = true;
      case 'D': {
          int k = sprawdz_scanf("Podaj ile osob chcesz dopisac\n");
          for (int i = 0; i < k; ++i) {
            int osid = sprawdz_scanf("Podaj numer osoby:\n");
            printf("Przed dodaniem\n");
            dodaj_osobe(nowa_osoba(osid, isVIP), queue);
          }
          wyswietl(queue);
        break;
      }
      case 'O': {
          int ile_usunac = sprawdz_scanf("Podaj ile osob chcesz obsluzyc:\n");
          for (int i = 0; i < ile_usunac; ++i)
            usun_osobe(queue);
        break;
      }
      case 'Q':
        finish = true;
        break;
      default:
        printf("Nie ma takiej opcji!\n");
        while(getchar()!='\n');
        break;
    }
  }
}

int main()
{
    menu();
    return 0;
}
