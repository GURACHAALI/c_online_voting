#include <stdio.h>

struct Candidate {
  char name[50];
  char symbol;
  int votes;
};

void castVote(struct Candidate candidates[], int numCandidates);
void displayResults(struct Candidate candidates[], int numCandidates);

int main() {
  int numCandidates;

  printf("Enter the number of candidates: ");
  scanf("%d", &numCandidates);

  struct Candidate candidates[numCandidates];

  for (int i = 0; i < numCandidates; i++) {
    printf("Enter name for candidate %d: ", i + 1);
    scanf("%s", candidates[i].name);

    printf("Enter symbol for candidate %d: ", i + 1);
    scanf(" %c", &candidates[i].symbol);

    candidates[i].votes = 0;
  }

  int choice;
  do {
    printf("\n---- Voting Menu ----\n");
    printf("1. Cast Vote\n");
    printf("2. Display Results\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        castVote(candidates, numCandidates);
        break;
      case 2:
        displayResults(candidates, numCandidates);
        break;
      case 0:
        break;
      default:
        printf("Invalid choice. Please enter a valid option.\n");
    }
  } while (choice != 0);

  return 0;
}

void castVote(struct Candidate candidates[], int numCandidates) {
  int candidateChoice;

  printf("\n---- Candidates ----\n");
  for (int i = 0; i < numCandidates; i++) {
    printf("%d. %s (Symbol: %c)\n", i + 1, candidates[i].name, candidates[i].symbol);
  }

  printf("\nEnter your vote (candidate number): ");
  scanf("%d", &candidateChoice);

  if (candidateChoice >= 1 && candidateChoice <= numCandidates) {
    candidates[candidateChoice - 1].votes++;
    printf("Your vote has been cast successfully.\n");
  } else {
    printf("Invalid candidate choice. Please enter a valid candidate number.\n");
  }
}

void displayResults(struct Candidate candidates[], int numCandidates) {
  printf("\n---- Voting Results ----\n");
  for (int i = 0; i < numCandidates; i++) {
    printf("%s (Symbol: %c) - Votes: %d\n", candidates[i].name, candidates[i].symbol, candidates[i].votes);
  }
}
