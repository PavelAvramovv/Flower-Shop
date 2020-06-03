#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FLOWER_NAME_LENGTH 100
#define COUNTRY_LENGTH 80

struct Flower
{
	char name[FLOWER_NAME_LENGTH];
	double price;
	char country[COUNTRY_LENGTH];

};

void inputFlower(Flower* pFlower)
{
	printf("Enter flower name: ");
	scanf_s("%s", &pFlower->name, FLOWER_NAME_LENGTH);

	printf("Enter flower price: ");
	scanf_s("%lf", &pFlower->price);

	printf("Enter flower country: ");
	scanf_s("%s", &pFlower->country, COUNTRY_LENGTH);
}

void outputFlower(const Flower* pFlower)
{
	printf_s("%s", pFlower->name);

	printf_s("%lf", pFlower->price);

	printf_s("%s", pFlower->country);
}

void searchFlower(Flower allFlowers[], int size, char* countryName)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(allFlowers[i].country, countryName) == 0)
			outputFlower(&allFlowers[i]);
	}
}

int main()
{
	int size = 0;
	printf("Enter number of flowers: ");
	scanf_s("%d", &size);

	Flower* pAllFlowers = (Flower*)malloc(size * sizeof(Flower));

	for (Flower* pFlower = pAllFlowers; pFlower != pAllFlowers + size; pFlower++)
	{
		inputFlower(pFlower);
	}

	for (Flower* pFlower = pAllFlowers; pFlower != pAllFlowers + size; pFlower++)
	{
		outputFlower(pFlower);
	}

	char searchedCountry[COUNTRY_LENGTH];
	printf("Enter searched flower by country: ");
	scanf_s("%s", &searchedCountry, COUNTRY_LENGTH);
	printf("Searched flower by country: ");
	searchFlower(pAllFlowers, size, &searchedCountry[0]);

	free(pAllFlowers);

	return 0;
}