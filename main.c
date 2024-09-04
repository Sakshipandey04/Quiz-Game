/*Quiz Game*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_QUESTIONS 5

typedef struct{
    char question[256];
    char options [4][64];
    int correct_option;
}Questions;

void displayQuestion(Questions q)
{
    printf("%s\n", q.question);
    for(int i=0; i<4; i++){
        printf("%d . %s\n", i+1,q.options[i]);
    
    }
    
    
}
int checkAnswer(Questions q, int user_answer){
    return (user_answer == q.correct_option);
}
int main(){
    srand (time(NULL));
    Questions original_questions[MAX_QUESTIONS]= {
        {"Which one is greatest among following?",
        {"3/5", "5/3", "2/7", "6/7"},
        2 },
        { "How many legs does a spider have?",
        { "6", "5", "8", "10"}, 
        3},
        {"What is the largest mammal in the world?",
        { "Elephant", "Giraffe", "Hippoptamous", "Blue Whale"},
        4},
        {"How many continents are there on Earth?" ,
        { "7", "8", "5", "6"  },
        1},
        { "Which ocean is largest on the Earth?",
        { "Atlantic", "Pacific", "Indian", "Arctic" },
        2 }
    };
    Questions questions[MAX_QUESTIONS];
    memcpy(questions, original_questions,
            sizeof(original_questions));
    
    int num_questions = MAX_QUESTIONS;
    int score=0;
    printf("Yay! Here's your Quiz Game!\n");
    for(int i=0; i <MAX_QUESTIONS; i++){
        int random_index = rand() % num_questions;
        Questions current_question = questions[random_index];
        displayQuestion(current_question);
        
        int user_answer;
        printf("Enter your answer (1-4)");
        scanf("%d\n", &user_answer);
        if (user_answer >=1 && user_answer<= 4) {
            if(checkAnswer(current_question,
                user_answer)){
                    printf("Correct!\n");
                    score++;
                }
            else {
                printf("Incorrect, The Correct answer is" "%d. %s\n",
                current_question.correct_option, current_question.options
                [current_question.correct_option -1]);
            }
        }
        else {
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
        questions[random_index] = questions[num_questions-1];
        num_questions--;
    }
       printf("Well Done Champ!!! Quiz Completed!! Your"
       "score : %d/ %d\n", score, MAX_QUESTIONS);
       
    return 0;
}