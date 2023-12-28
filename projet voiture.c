#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 200
typedef struct {
    int car_id;
    char brand[50];
    char model[50];
    char status;}Car;
typedef struct {
    int rental_id;
    int car_id;
    char renter_name[50];
    char rent_date[20];
    char return_date[20];} Rental;
Car cars[m];
Rental rentals[m];
int numCars=0;
int numRentals=0;
void ajoutvoiture(char brand[],char model[]){
   if (numCars < m) {
        cars[numCars].car_id = numCars + 1;
        strcpy(cars[numCars].brand, brand);
        strcpy(cars[numCars].model, model);
        cars[numCars].status = 'A';
        numCars++;
        printf("voiture ajoutee avec succee.\n");
        printf("votre code est:%d\n",cars[numCars-1].car_id);
    } else {
        printf("la stockage est maximum.\n");
    }
}
void Descript(int car_id) {
    if (car_id >= 1 && car_id <= numCars) {
        printf("Car ID: %d\n", cars[car_id - 1].car_id);
        printf("Brand: %s\n", cars[car_id - 1].brand);
        printf("Model: %s\n", cars[car_id - 1].model);
        printf("Status: %c\n", cars[car_id - 1].status);
    } else {
        printf("le code est invalide.\n");
    }
}
void voiturepanne(int car_id) {
    if (car_id >= 1 && car_id <= numCars) {
        cars[car_id - 1].status = 'U';
        printf("la voiture est envoyee au mecanicien.\n");
    } else {
        printf("le code est invalide.\n");
    }
}
void changervoiture(int car_id, char newBrand[], char newModel[], char newStatus) {
    if (car_id >= 1 && car_id <= numCars) {
        strcpy(cars[car_id - 1].brand, newBrand);
        strcpy(cars[car_id - 1].model, newModel);
        cars[car_id - 1].status = newStatus;
        printf("les informations sont changees avec succee.\n");
    } else {
        printf("le code est invalide.\n");
    }
}
void histoirerent() {
    for (int i = 0; i < numRentals; i++) {
        printf("Rental ID: %d\n", rentals[i].rental_id);
        printf("Car ID: %d\n", rentals[i].car_id);
        printf("Renter: %s\n", rentals[i].renter_name);
        printf("Rent Date: %s\n", rentals[i].rent_date);
        printf("Return Date: %s\n\n", rentals[i].return_date);
    }
}
void returnvoiture(int rental_id, char return_date[]) {
    if (rental_id >= 1 && rental_id <= numRentals) {
        cars[rentals[rental_id - 1].car_id - 1].status = 'A';
        strcpy(rentals[rental_id - 1].return_date, return_date);
        printf("voiture retourner avec succee.\n");
    } else {
        printf("le code est invalide.\n");
    }
}
void rentvoiture(int car_id, char renter_name[], char rent_date[]) {
    if (car_id >= 1 && car_id <= numCars && cars[car_id - 1].status == 'A') {
        cars[car_id - 1].status = 'R';
        rentals[numRentals].rental_id = numRentals + 1;
        rentals[numRentals].car_id = car_id;
        strcpy(rentals[numRentals].renter_name, renter_name);
        strcpy(rentals[numRentals].rent_date, rent_date);
        numRentals++;
        printf("voiture rentee avec succee.\n");
    } else {
        printf("code est invalide or la voiture n'est pas disponible.\n");
    }
}
void valable() {
    int availableCars = 0;
    int rentedCars = 0;
    int maintenanceCars = 0;
    for (int i = 0; i < numCars; i++) {
        switch (cars[i].status) {
            case 'A':
                availableCars++;
                break;
            case 'R':
                rentedCars++;
                break;
            case 'U':
                maintenanceCars++;
                break;
            default:
                break;
        }
    }
    printf("voiture valable: %d\n", availableCars);
    printf("voiture en rent: %d\n", rentedCars);
    printf("voiture en panne: %d\n", maintenanceCars);
}
int main() {
   /* ajoutvoiture("Toyota","Camry");
    ajoutvoiture("Honda","Civic");
    rentvoiture(1,"chiheb","2023-01-01");
    rentvoiture(2,"chiheb","2023-02-01");
    returnvoiture(1,"2023-01-10");*/
    /*si vous voulez une exemple existant*/


    printf("Bonjour cher client.\n");
    printf("voulez vous:\n");
    printf("1.renter une voiture.\n");
    printf("2.retourner une voiture.\n");
    printf("3.mettre une annonce.\n");
    int j;
    scanf("%d",&j);

 if (j==1){
    valable();
    histoirerent();
    printf("donner le code de voiture,votre nom et la date:\n");
    int id;
    char nom[20];
    char date[20];
    scanf("%d%s%s",&id,&nom,&date);
    Descript(id);
    rentvoiture(id,nom,date);
 }
 else if (j==2){
     printf("donner le code du location,votre nom et la date:\n");
    int id;
    char nom[20];
    char date[20];
    scanf("%d%s%s",&id,&nom,&date);
    returnvoiture(id,date);

 }
 else if(j==3){
    printf("voulez vous:\n");
    printf("1.changer votre annonce.\n");
    printf("2.faire nouvelle annonce.\n");
    printf("3.fixer votre voiture.\n");
    int k;
    scanf("%d",&k);
    if (k==1){
        int id;
        char brand[50];
        char model[50];
        char status;
        printf("donner le code, le nouveau brand,model et status");
        scanf("%d%s%s%c",&id,&brand,&model,&status);
        changervoiture(id,brand,model,status);


    }
   else if (k==2){
        char brand[50];
        char model[50];
        printf("donner le brand et model");
        scanf("%s%s",&brand,&model);
        ajoutvoiture(brand,model);
    }
    else if(k==3){
        int id;
        printf("donner code");
        scanf("%d",&id);
        voiturepanne(id);
    }
 }


return 0;
}

