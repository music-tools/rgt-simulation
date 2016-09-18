#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int randTonic(int x);

void insertAt(int pos,char element,char* string);

void removeAt(int pos,char* string);

void printRandDyn();

int isANote(char elem);

void transposeOne(char* chordProg);



int main(void)
{
	int y;
	srand (time(NULL));

	//Part 1.1:Scales - Arpeggios
	printf("-------------------------------------------------------------------\n");
	printf("			PART 1.1-SCALES						   \n");
	printf("-------------------------------------------------------------------\n");
	//Scales
	int i=0;
	char c;
	while ((c=getchar()!='Z')&&(i!=5))
	{
		randTonic(y); //print Tonic

		int typeOfScale=rand()%4;
		switch (typeOfScale)
		{
			case 0:
				{
					printf(" Natural Minor Scale (2 octaves,2 positions) ");
					break;
				}
			case 1:
				{
                    printf(" Major Scale (2 octaves,2 positions) ");
					break;
				}
			case 2:
				{
                    printf(" Pentatonic Major Scale (2 octaves,2 positions) ");
					break;
				}
			case 3:
				{
                    printf(" Blues Scale (2 octaves,2 positions) ");
					break;
				}

		}
		i++;
	}
	//Arpeggios(1 octave)
	printf("-------------------------------------------------------------------\n");
	printf("			PART 1.2-ARPEGGIOS(two octaves)						   \n");
	printf("-------------------------------------------------------------------\n");
	i=0;
	while ((c=getchar()!='Z')&&(i!=5))
	{
	    randTonic(y); //print Tonic

	    int typeOfArpeggio=rand()%3;
	    switch (typeOfArpeggio)
	    {
			case 0:
				{
					printf(" major 7th");
					break;
				}
			case 1:
				{
                    printf(" dominant 7th");
					break;
				}
			case 2:
				{
                    printf(" minor 7th");
					break;
				}
		}
		i++;
	}


	//Part 2:Chords
	printf("-------------------------------------------------------------------\n");
	printf("			PART 2-CHORDS(only barre)							   \n");
	printf("-------------------------------------------------------------------\n");
	i=0;
	while ((c=getchar()!='Z')&&(i!=10))
	{
	    randTonic(y); //print Tonic

	    int typeOfChord=rand()%5;
	    switch (typeOfChord)
	    {
			case 0:
				{
					printf(" major");
					break;
				}
			case 1:
				{
                    printf(" minor");
					break;
				}
			case 2:
				{
                    printf(" minor 7th");
					break;
				}
			case 3:
				{
                    printf(" dominant 7th");
					break;
				}
			case 4:
				{
                    printf(" major 7th");
					break;
				}
		}
		i++;
	}
}
	

int randTonic(int x)
{
	int y;
    x=rand()%12; //14 different notes
	switch (x)
		{
		case 0:
			{
				printf("B");
				break;
			}
		case 1:
			{
                printf("C");
                break;
			}
		case 2:
			{
				y=rand()%2;
				if (y==0) { printf("Db"); }
				else { printf("C#"); }
                break;
			}
		case 3:
			{
                printf("D");
                break;
			}
		case 4:
			{
                y=rand()%2;
				if (y==0) { printf("Eb"); }
				else { printf("D#"); }
                break;
			}
		case 5:
			{
                printf("E");
                break;
			}
		case 6:
			{
                printf("F");
                break;
			}
		case 7:
			{
                y=rand()%2;
				if (y==0) { printf("Gb"); }
				else { printf("F#"); }
                break;
			}
		case 8:
			{
                printf("G");
                break;
			}
		case 9:
			{
                y=rand()%2;
				if (y==0) { printf("Ab"); }
				else { printf("G#"); }
                break;
			}
		case 10:
			{
                printf("A");
                break;
			}
		case 11:
			{
                y=rand()%2;
				if (y==0) { printf("Bb"); }
				else { printf("A#"); }
                break;
			}
		}
		return 1;
}
