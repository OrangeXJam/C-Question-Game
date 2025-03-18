///////////////////////////////////////Part 1/////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
///////////////////////////////////////Part 2/////////////////////////////////////////////////////
struct Question_Format {
    char Questions[100];
    char Answers[100];
};
////////////////////////////////////////////Part 3////////////////////////////////////////////////
void Destiny(int user_score, int Question_Number)
{
    if (user_score == 265)
    {
        printf("%d/%d Perfect! You've fully reclaimed your knowledge. You are victorious :D\n", user_score, Question_Number);
    }
    else if (user_score < 261 && user_score > 236)
    {
        printf("%d/%d Wow! You're almost there! You're on the brink of victory! :D\n", user_score, Question_Number);
    }
    else if (user_score < 235 && user_score > 210)
    {
        printf("%d/%d Good, but not great! You can do better! :)\n", user_score, Question_Number);
    }
    else if (user_score < 209 && user_score > 158)
    {
        printf("%d/%d Good performance, but not enough still. Keep pushing and you will get there :)\n", user_score, Question_Number);
    }
    else if (user_score < 157 && user_score > 132)
    {
        printf("%d/%d Close one, you need to focus more >:)\n", user_score, Question_Number);
    }
    else if (user_score < 131 && user_score > 106)
    {
        printf("%d/%d You are wounded. Stand back and heal yourself - O -\n", user_score, Question_Number);
    }
    else if (user_score < 105 && user_score > 81)
    {
        printf("%d/%d You barely got out of there alive :O\n", user_score, Question_Number);
    }
    else if (user_score < 81 && user_score > 56)
    {
        printf("%d/%d You are not ready. You need more training -_- \n", user_score, Question_Number);
    }
    else if (user_score < 56 && user_score >= 0)
    {
        printf("%d/%d You fell under the Raven's mind-control curse :X\n", user_score, Question_Number);
    }
}

////////////////////////////////////////////Part 4//////////////////////////////////////////////////
void shuffle_questions(struct Question_Format Questions[], int Question_Number)
{
    srand(time(NULL));
    for(int i = Question_Number; i >= 0; i--)
    {
        int j = rand() % Question_Number;
        struct Question_Format temp = Questions[i];
        Questions[i] = Questions[j];
        Questions[j] = temp;
    }
}
////////////////////////////////////////////Part 5//////////////////////////////////////////////////
int main()
{
    char Try_Again = 'Y';
    do
    {
    int user_score = 0, Question_Number = 0, number_of_questions = 0;
    struct Question_Format Questions[300];
    char user_answer[100], program_ender[] = "end game", Try_Again_2 = 'L', read_or_not = 'S';
    bool answered = true;
//////////////////////////////////////////////Part 6///////////////////////////////////////////////
    FILE *Database = fopen("Question.txt", "r");
    if(Database == NULL)
    {
        printf("This File Does not exist");
        return 1;
    }
    while(fscanf(Database, "%99[^,],%99[^\n]\n",Questions[Question_Number].Questions, Questions[Question_Number].Answers) == 2)
    {
        Question_Number++;
    }
    fclose(Database);
    shuffle_questions(Questions, Question_Number);
///////////////////////////////////////////////Part 7//////////////////////////////////////////////
    printf("Do you want to read the story ? Y/N\n");
    scanf(" %c",&read_or_not);
    if(read_or_not == 'Y' || read_or_not == 'y')
    {
        printf("You were a knowledgeable scholar; you had answers for questions that no one even thought of.\nBut as your knowledge circle widened, so did your enemies' numbers.\nOne of them being\nThe Obsidian Raven!\nHe hunts in the shadows, so when you were expanding your knowledge late at night in the library while everyone was sleeping,\nhe took the chance and struck you.\nWith his powerful curse, he was able to steal all your knowledge.\nThe knowledge he could not steal was who you were.\nNow, the only way to get your knowledge back is to earn it from him again by answering all of his questions, which he will ask using all of the knowledge he stole.\nGood luck, traveler :)\n");
        sleep(35);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    if(read_or_not == 'N' || read_or_not == 'n') 
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    for(int i = 0; i < Question_Number; i++)
    {
        time_t start_time = time(NULL);
        printf("%s\n",Questions[i].Questions);
        while (difftime(time(NULL), start_time) <= 60)
        {
            printf("\rYou have %d seconds left", 60 - (int)(difftime(time(NULL), start_time)));
            fflush(stdout);
            if(_kbhit())
            {
                printf("\n");
                fgets(user_answer, sizeof(user_answer), stdin);
                answered = true;
                break;
            }
            Sleep(100);
        }
        printf("\n");
            if(answered == false)
            {
                printf("Too Slow, FOCUS\n");
                continue;
            }
///////////////////////////////////////////////Part 8///////////////////////////////////////////////
            if( user_answer == NULL)
                {
                    printf("Unknown Error\n");
                    return 1;
                }
                else
                {
                    for(int i = 0; i < strlen(user_answer); i++)
                    {
                        user_answer[i] = tolower(user_answer[i]);
                    }
                        user_answer[strcspn(user_answer, "\n")] = '\0';
                        if(strcmp(user_answer, program_ender) == 0)
                        {
                            printf("Are you sure you can face the Consequences Y/N\n");
                            scanf(" %c",&Try_Again_2);
                            getchar();
                            if(Try_Again_2 == 'N' || Try_Again_2 == 'n')
                            {
                                break;
                            }
                            else if(Try_Again_2 == 'Y' || Try_Again_2 == 'y')
                            {
                                Destiny(user_score, Question_Number);
                                sleep(5);
                                exit(0);
                            }
                        }
////////////////////////////////////////////Part 9//////////////////////////////////////////////////
                            else
                            {
                                if(strcmp(user_answer, Questions[i].Answers) == 0)
                                {
                                    printf("NICE HIT >:D\n");
                                    user_score++;
                                }
                                    else
                                    {
                                        printf("OUCH >:O\n");
                                    }
                            }
                }
    }
/////////////////////////////////////////////Part 10///////////////////////////////////////////////
    printf("Do you think you are ready for him this time Y/N ?\n");
    scanf(" %c",&Try_Again);
    if(Try_Again == 'N')
    {
        printf("Don't Worry, We will get him next time travler\n");
        sleep(5);
    }
    getchar();
    } while(Try_Again == 'Y' || Try_Again == 'y');
    return 0;
}
/////////////////////////////////////////////End///////////////////////////////////////////////////