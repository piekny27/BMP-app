#include "pch.h"

struct FileHeader {
    short bfType;
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    int bfOffBits;
} File;

struct PictureHeader {
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
} Picture;

struct ColorsRGB {
    char R;
    char G;
    char B;
} Rgb;

int main(int arc, char * argv[]) 
{
    FILE* f = fopen(argv[1], "rb");

    if (f == nullptr)
    {
        printf("Nie mozna otworzyc pliku");
        return -1;
    }
    else
    {
        printf("Plik pomyslnie otworzony");
    }

    printf("\nINFORMACJE O BITMAPIE\n\n");

    fread(&File.bfType, sizeof(File.bfType), 1, f);
    printf("Typ: %x", File.bfType);

    fread(&File.bfSize, sizeof(File.bfSize), 1, f);
    printf("\nRozmiar pliku: %d bajtow", File.bfSize);

    fread(&File.bfReserved1, sizeof(File.bfReserved1), 1, f);
    printf("\nZarezerwowane1: %d", File.bfReserved1);

    fread(&File.bfReserved2, sizeof(File.bfReserved2), 1, f);
    printf("\nZarezerwowane2: %d", File.bfReserved2);

    fread(&File.bfOffBits, sizeof(File.bfOffBits), 1, f);
    printf("\nPozycja danych obrazkowych: %d", File.bfOffBits);

    printf("\n");

    fseek(f, 14, SEEK_SET);
    fread(&Picture.biSize, sizeof(Picture.biSize), 1, f);
    printf("\nWielkosc naglowka informacyjnego: %d", Picture.biSize);

    fread(&Picture.biWidth, sizeof(Picture.biWidth), 1, f);
    printf("\nSzerokosc: %d pikseli", Picture.biWidth);

    fread(&Picture.biHeight, sizeof(Picture.biHeight), 1, f);
    printf("\nWysokosc: %d pikseli", Picture.biHeight);

    fread(&Picture.biPlanes, sizeof(Picture.biPlanes), 1, f);
    printf("\nLiczba platow: %d", Picture.biPlanes);

    fread(&Picture.biBitCount, sizeof(Picture.biBitCount), 1, f);
    printf("\nLiczba bitow na piksel: %d (1, 4, 8, or 24)", Picture.biBitCount);

    fread(&Picture.biCompression, sizeof(Picture.biCompression), 1, f);
    printf("\nKompresja: %d (0=none, 1=RLE-8, 2=RLE-4)", Picture.biCompression);

    fread(&Picture.biSizeImage, sizeof(Picture.biSizeImage), 1, f);
    printf("\nRozmiar samego rysunku: %d", Picture.biSizeImage);

    fread(&Picture.biXPelsPerMeter, sizeof(Picture.biXPelsPerMeter), 1, f);
    printf("\nRozdzielczosc pozioma: %d", Picture.biXPelsPerMeter);

    fread(&Picture.biYPelsPerMeter, sizeof(Picture.biYPelsPerMeter), 1, f);
    printf("\nRozdzielczosc pionowa: %d", Picture.biYPelsPerMeter);

    fread(&Picture.biClrUsed, sizeof(Picture.biClrUsed), 1, f);
    printf("\nLiczba kolorow w palecie: %d", Picture.biClrUsed);

    fread(&Picture.biClrImportant, sizeof(Picture.biClrImportant), 1, f);
    printf("\nWazne kolory w palecie: %d", Picture.biClrImportant);

    printf("\n");
}