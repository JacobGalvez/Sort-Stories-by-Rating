#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
struct Website
{
    string title, url;
    int score;
};

int openAndReadFile(Website[]);
void sortByScore(Website[], int);
int findMode(Website[], int);
void displayMode(Website[],int ,int);

int main()
{
    const int MAXSIZE = 100;
    int numOfFiles;
    Website *story = nullptr;
    story = new Website [MAXSIZE];
    int mode;

    numOfFiles = openAndReadFile(story);
    sortByScore(story, numOfFiles);
    mode = findMode(story, numOfFiles);
    displayMode(story, numOfFiles, mode);

    delete[] story;

}

int openAndReadFile(Website *story)
{
    int filesRead;

    ifstream fin;
    fin.open("program3stories.txt");

    if (!fin)
        cout << "ERROR NO FILE OPENING" << endl;

    int i = 0;
    fin >> filesRead;
    while(!fin.eof())
    {
        fin.ignore();
        getline(fin, (story+i)->title);
        fin >> (story+i)->url;
        fin >> (story+i)->score;
        i++;
    }
  return filesRead;
}

void sortByScore(Website *story, int numOfFiles)
{
    Website temp;

    for (int i = 0; i < numOfFiles; i++)
    {
        for (int j = 1; j < numOfFiles - i; j++)
        {
            if ((story + (j-1))->score < (story + j)->score)
            {
                temp = *(story + (j-1));
                *(story + (j-1)) = *(story + j);
                *(story + j) = temp;
            }
        }
    }
}

int findMode(Website *story, int numOfFiles)
{
   int number = story->score;
   int mode = number;
   int counter = 1;
   int countMode = 1;

   for (int i = 1; i < numOfFiles; i++)
   {
       if ((story + i)->score == number)
       {
           ++counter;
       }
       else
       {
           if (counter > countMode)
           {
               countMode = counter;
               mode = number;
           }
           if(countMode == 1)
            mode = -1;

           counter = 1;
           number = ((story + i)->score);
           
       }
   }

   return mode;
}

void displayMode(Website *story, int numOfFiles, int mode)
{
  if (mode != -1)
  {
    cout << "Mode: " << mode << endl;
    cout << endl;
  }
  else
  {
    cout << "Mode: none" << endl;
    cout << endl;
  }

  for (int i = 0; i < numOfFiles; i++)
  {
    if ((story + i)->score == mode)
    {
      cout << (story + i)->title << endl;
      cout << (story + i)->url << endl;
      cout << endl;
    }
  }
  if (mode == -1)
  {
    openAndReadFile(story);
    for (int i = 0; i < 5; i++)
    {
      cout << (story + i)->title << endl;
      cout << (story + i)->url << endl;
      cout << endl;
    }
  }
}
