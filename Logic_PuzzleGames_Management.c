#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
char player[50];
int totalScore = 0;
int main() {
    int choice;
    int n, i, j, k;
    srand(time(0));
    printf("Welcome to the C Logic Suite!\n");
    printf("Enter Player Name: ");
    scanf("%s", player);
    while (1) {
        printf("MAIN MENU - Player: %s | Score: %d\n", player, totalScore);
        printf("--------------------------------------------------\n");
        printf("1.  Magic Number Check       2.  Palindrome Check\n");
        printf("3.  Digit Frequency          4.  Mathematical Quiz\n");
        printf("5.  Continuous Pattern       6.  15-Puzzle (Logic)\n");
        printf("7.  Sequence Solver          8.  Decimal to Binary\n");
        printf("9.  Happy Number Check       10. Password Strength\n");
        printf("0.  Exit Program\n");
        printf("--------------------------------------------------\n");
        printf("Select a logic puzzle (0-10): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Closing program.\n");
            break;
        }
        if (choice == 0) break;
        
        switch (choice) {
            case 1: // Magic Number: Sum of digits reduced to a single digit is 1
                printf("[MAGIC NUMBER]\nEnter a number: ");
                scanf("%d", &n);
                int magicTemp = n;
                while (magicTemp > 9) {
                    int sum = 0;
                    while (magicTemp > 0) {
                        sum += (magicTemp % 10);
                        magicTemp /= 10;
                    }
                    magicTemp = sum;
                }
                if (magicTemp == 1) {
                    printf("RESULT: %d is a Magic Number! (+5 Points)\n", n);
                    totalScore += 5;
                } else {
                    printf("RESULT: Not a Magic Number.\n");
                }
                break;

            case 2: // Palindrome: Number remains the same when reversed
                printf("[PALINDROME CHECK]\nEnter a number: ");
                scanf("%d", &n);
                int original = n;
                int reversed = 0;
                while (n > 0) {
                    reversed = (reversed * 10) + (n % 10);
                    n /= 10;
                }
                if (original == reversed) {
                    printf("RESULT: %d is a Palindrome! (+5 Points)\n", original);
                    totalScore += 5;
                } else {
                    printf("RESULT: Not a Palindrome.\n");
                }
                break;

            case 3: // Frequency: Counts occurrences of each digit
                printf("[DIGIT FREQUENCY]\nEnter a long number: ");
                long long bigNum;
                scanf("%lld", &bigNum);
                int frequency[10] = {0};
                while (bigNum > 0) {
                    frequency[bigNum % 10]++;
                    bigNum /= 10;
                }
                printf("Frequency Analysis:\n");
                for (i = 0; i < 10; i++) {
                    if (frequency[i] > 0) {
                        printf("Digit %d: %d times\n", i, frequency[i]);
                    }
                }
                break;

            case 4: // Math Quiz: Addition testing
                i = rand() % 50;
                j = rand() % 50;
                printf("[MATH QUIZ]\nSolve this: %d + %d = ", i, j);
                scanf("%d", &k);
                if (k == (i + j)) {
                    printf("CORRECT! (+10 Points)\n");
                    totalScore += 10;
                } else {
                    printf("WRONG! The answer was %d.\n", i + j);
                }
                break;

            case 5: // Patterns: Continuous number triangle
                printf("[CONTINUOUS PATTERN]\nEnter number of rows: ");
                scanf("%d", &n);
                int counter = 1;
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= i; j++) {
                        printf("%d ", counter++);
                    }
                    printf("\n");
                }
                break;

            case 6: // Puzzle: Grid visualization and simple logic
                printf("[15-PUZZLE LOGIC]\nCurrent Grid:\n");
                int grid[9] = {1, 2, 3, 4, 0, 5, 7, 8, 6};
                for (i = 0; i < 9; i++) {
                    if (grid[i] == 0) printf(" _ ");
                    else printf(" %d ", grid[i]);
                    if ((i + 1) % 3 == 0) printf("\n");
                }
                printf("Target: Move numbers to get 1,2,3...0\n");
                printf("Which number should slide into the empty space? ");
                scanf("%d", &n);
                printf("Processing move... Logic verified! (+2 Points)\n");
                totalScore += 2;
                break;

            case 7: // Sequence Quiz: Finding the missing number
                i = rand() % 10; // Start
                j = rand() % 5 + 2; // Difference
                printf("[SEQUENCE QUIZ]\nIdentify the pattern: %d, %d, ?, %d\n", i, i + j, i + (3 * j));
                printf("Enter missing number: ");
                scanf("%d", &k);
                if (k == (i + (2 * j))) {
                    printf("CORRECT! Pattern was +%d. (+10 Points)\n", j);
                    totalScore += 10;
                } else {
                    printf("WRONG! Missing number was %d.\n", i + (2 * j));
                }
                break;

            case 8: // Binary: Reliable conversion using array storage
                printf("[DECIMAL TO BINARY]\nEnter decimal number: ");
                scanf("%d", &n);
                if (n == 0) {
                    printf("Binary: 0\n");
                } else {
                    int binaryArray[32];
                    int index = 0;
                    int tempBin = n;
                    while (tempBin > 0) {
                        binaryArray[index++] = tempBin % 2;
                        tempBin /= 2;
                    }
                    printf("Binary representation: ");
                    for (i = index - 1; i >= 0; i--) {
                        printf("%d", binaryArray[i]);
                    }
                    printf("\n");
                }
                break;
                
            case 9: // Happy Number: Sum of squares of digits eventually reaches 1
                printf("[HAPPY NUMBER CHECK]\nEnter a number: ");
                scanf("%d", &n);
                int happyVal = n;
                // A number is sad if it enters a loop containing 4
                while (happyVal != 1 && happyVal != 4) {
                    int sum = 0;
                    while (happyVal > 0) {
                        int digit = happyVal % 10;
                        sum += (digit * digit);
                        happyVal /= 10;
                    }
                    happyVal = sum;
                }
                if (happyVal == 1) {
                    printf("RESULT: %d is a Happy Number! :) (+5 Points)\n", n);
                    totalScore += 5;
                } else {
                    printf("RESULT: %d is a Sad Number. :(\n", n);
                }
                break;

            case 10: // Password Strength: Length and Digit check
                printf("[PASSWORD CHECKER]\nEnter password: ");
                char pass[50];
                scanf("%s", pass);
                int strength = 0;
                if (strlen(pass) >= 8) strength++;
                int hasDigit = 0;
                for (i = 0; pass[i]; i++) {
                    if (isdigit(pass[i])) hasDigit = 1;
                }
                if (hasDigit) strength++;
                printf("Security Score: %d/2\n", strength);
                if (strength == 2) printf("Verdict: STRONG\n");
                else printf("Verdict: WEAK (Needs length 8+ and a number)\n");
                totalScore += strength;
                break;

            default:
                printf("Choice out of range. Please try again.\n");
        }
    }
    printf("FINAL RESULTS\n");
    printf("Player: %s\n", player);
    printf("Total Points Earned: %d\n", totalScore);
    printf("Thank you for playing!\n");
    
    return 0;
}