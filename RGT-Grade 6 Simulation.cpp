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
		
		int typeOfScale=rand()%8;
		switch (typeOfScale)
		{
			case 0:
				{
					printf(" Natural Minor Scale (1 octave,5 positions) ");
					break;
				}
			case 1:
				{
                    printf(" Major Scale (1 octave,5 positions) ");
					break;
				}
			case 2:
				{
                    printf(" Dorian  Scale (2 octaves,1 position) ");
					break;
				}
			case 3:
				{
                    printf(" Mixolydian Scale (2 octaves,1 position) ");
					break;
				}
			case 4:
				{
                    printf(" Chromatic Scale (2 octaves,1 position) ");
					break;
				}
			case 5:
				{
                    printf(" Major Scale in 8ths (1 octave,1 position) ");
					break;
				}
			case 6:
				{
                    printf(" Pentatonic Minor Scale in 8ths (1 octave,1 position) ");
					break;
				}
			case 7:
				{
                    printf(" Major Scale in 3rds (1 octave,1 position) ");
					break;
				}
			
		}
		i++;
	}
	//Arpeggios(1 octave)
	printf("-------------------------------------------------------------------\n");
	printf("			PART 1.2-ARPEGGIOS						   \n");
	printf("-------------------------------------------------------------------\n");
	i=0;
	while ((c=getchar()!='Z')&&(i!=5))
	{
	    randTonic(y); //print Tonic
	
	    int typeOfArpeggio=rand()%5;
	    switch (typeOfArpeggio)
	    {
			case 0:
				{
					printf(" augmented 5th");
					break;
				}
			case 1:
				{
                    printf(" diminished 7th");
					break;
				}
			case 2:
				{
                    printf(" minor 9th");
					break;
				}
			case 3:
				{
                    printf(" dominant 9th");
					break;
				}
			case 4:
				{
                    printf(" major 9th");
					break;
				}
		}
		i++;
	}
	
	
	//Part 2:Chords
	printf("-------------------------------------------------------------------\n");
	printf("			PART 2-CHORDS							   \n");
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
					printf(" augmented 5th");
					break;
				}
			case 1:
				{
                    printf(" diminished 7th");
					break;
				}
			case 2:
				{
                    printf(" minor 9th");
					break;
				}
			case 3:
				{
                    printf(" dominant 9th");
					break;
				}
			case 4:
				{
                    printf(" major 9th");
					break;
				}
		}
		i++;
	}
	
	//Part 3:Rhythm Playing
	printf("-------------------------------------------------------------------\n");
	printf("			PART 3-RHYTHM PLAYING					   \n");
	printf("-------------------------------------------------------------------\n");
	int x=1,temp,time;
	char count[10]="i";
	char* timeSignature=(char*)malloc(10);
	char tempo[20];
	FILE* filePtr;
	char* chordProg=(char*)malloc(1000);
	int linesNo=0;
	int selectedLine;
	
	
	
	while ((c=getchar()!='Z')&&(x!=9))
	{
		time=rand()%4;
		switch (time)
		{
			case 0:
			{
				strcpy(timeSignature,"3/4");
				break;
			}
			case 1:
			{
                strcpy(timeSignature,"4/4");
				break;
			}
			case 2:
			{
                strcpy(timeSignature,"6/8");
				break;
			}
			case 3:
			{
                strcpy(timeSignature,"12/8");
				break;
			}
			
		}
	
	
	
		temp=rand()%11;
		switch (temp)
		{
			case 0:
			{
				strcpy(tempo,"Slow\n");
				break;
			}
			case 1:
			{
                strcpy(tempo,"Not too slow\n");
				break;
			}
			case 2:
			{
                strcpy(tempo,"Moderate tempo\n");
				break;
			}
			case 3:
			{
                strcpy(tempo,"Fast\n");
				break;
			}
			case 4:
			{
                strcpy(tempo,"Bright and Rhythmical\n");
				break;
			}
			case 5:
			{
                strcpy(tempo,"Slowly with expression\n");
				break;
			}
			case 6:
			{
                strcpy(tempo,"Lively with movement\n");
				break;
			}
			case 7:
			{
                strcpy(tempo,"Moderate relaxed tempo\n");
				break;
			}
			case 8:
			{
                strcpy(tempo,"Slowly with Expression\n");
				break;
			}
			case 9:
			{
                strcpy(tempo,"Brightly with movement\n");
				break;
			}
			case 10:
			{
                strcpy(tempo,"Slow ballad\n");
				break;
			}

		}
		if (x==4) {strcpy(count,"iv");}
		if (x==5) {strcpy(count,"v");}
		printf("(%s)%s  \n",count,tempo);
		printf("%s  ",timeSignature);
	
	
		filePtr=fopen("ChordProgressions.txt","r");
		if (!filePtr) {printf("Error at opening txt! \n");}

		//Count lines
		
		while (fgets(chordProg,1000,filePtr)!=NULL)
		{
			linesNo++;
		}
		
		
		
		
		fclose(filePtr);
		filePtr=fopen("ChordProgressions.txt","r");
		if (!filePtr) {printf("Error at opening txt! \n");}
	
		selectedLine=(rand()%(linesNo-1))+1;
		
		for (int j =1; j<=linesNo; j++)
		{
        	fgets(chordProg,1000,filePtr);
			if (j==selectedLine)
			{
				int r=rand()%11;
				while (r>0)
				{
                    transposeOne(chordProg);
                    r--;
				}
				//change line every 4 bars
				int countBars=0,l=0;
				while (chordProg[l]!='\0')
				{
					if (chordProg[l]=='|') {countBars++;}
					printf("%c",chordProg[l]);
					if (countBars==5)
					{
						if (timeSignature[0]=='1') {printf("\n    ");}
                        else {printf("\n     ");}
						countBars=1;
						//printRandDyn();
						if ((chordProg[l-1]!='|')&&(chordProg[l-1]!=':')&&(chordProg[l+1]!='|')) {printf("|");}
					}
					l++;
				}
				//printf("%s \n",chordProg);
			}
		}
		x++;
		strcat(count,"i");
	}
	
	
	
	
	
	//Part 4:Lead Playing
	printf("-------------------------------------------------------------------\n");
	printf("			PART 4-LEAD PLAYING						       \n");
	printf("-------------------------------------------------------------------\n");
	
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
void insertAt(int pos,char element,char* string)
{
	int i=0,j;
	while (string[i]!='\0')
	{i++;}
	for (j=i; j>=pos; j--)
	{
		string[j+1]=string[j];
	}
	string[pos]=element;
}

void removeAt(int pos,char* string)
{
	int i=pos;
	while (string[i]!='\0')
	{
		string[i]=string[i+1];
		i++;
	}
}

void printRandDyn()//for 4 bars
{
    int dyn,i;
    dyn=rand()%4;
	switch (dyn)
	{
		case 0: {printf("      p");break;}
		case 1: {printf("     mp");break;}
		case 2: {printf("     mf");break;}
		case 3: {printf("      f");break;}
		default: {printf("      g");}
	}
	for (i=0;i<3;i++)
	{
        dyn=rand()%4;
		switch (dyn)
		{
			case 0: {printf("            p");break;}
			case 1: {printf("           mp");break;}
			case 2: {printf("           mf");break;}
			case 3: {printf("            f");break;}
			default: {printf("            g");}
		}
	}
	printf("\n     ");
}

int isANote(char elem)
{
    char notes[8]="ABCDEFG";
    int j;
    for (j=0;j<=6;j++)
	{
		if (elem==notes[j]) {return j;}
    }
    return -1;
}

void transposeOne(char* chordProgression)
{
    char notes[8]="ABCDEFG";
	int i=0,j=0;
	while (chordProgression[i]!='\0')
	{
		j=isANote(chordProgression[i]);
		if (j!=-1)//is a note
		{
			if ((chordProgression[i+1]!='#')&&(chordProgression[i+1]!='b')) //pure note
			{
				if (j==1){chordProgression[i]='C';}
				else if (j==4){chordProgression[i]='F';}
				else {insertAt(i+1,'#',chordProgression);}
			}
			else if (chordProgression[i+1]=='#')//sharp note
			{
				if (j==6){chordProgression[i]='A';}
				else{chordProgression[i]=notes[j+1];}
				removeAt(i+1,chordProgression);
			}
			else if (chordProgression[i+1]=='b')//flat note
			{
				removeAt(i+1,chordProgression);
			}
		}
		i++;
	}
}
