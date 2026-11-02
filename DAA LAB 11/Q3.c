#include <stdio.h>
#include <string.h>
#define MAXN 100005
#define HASH_SIZE 262147

// Store all dictionary words
char words[MAXN][11];

// Hash table stores word indices
int hashTable[HASH_SIZE];

// Distance from starting word and target word
int distA[MAXN];
int distB[MAXN];

// Hash function
unsigned long long hashWord(char word[]){
    unsigned long long hash = 0;

    for (int i = 0; word[i] != '\0'; i++){
        hash = hash * 31 + word[i];
    }

    return hash % HASH_SIZE;
}

// Insert a word into the hash table
void insertWord(int index){
    unsigned long long pos = hashWord(words[index]);

    while (hashTable[pos] != -1){
        pos = (pos + 1) % HASH_SIZE;
    }

    hashTable[pos] = index;
}

// Find a word in the dictionary
int findWord(char word[]){
    unsigned long long pos = hashWord(word);
    unsigned long long start = pos;

    while (hashTable[pos] != -1){
        int index = hashTable[pos];

        if (strcmp(words[index], word) == 0)
            return index;

        pos = (pos + 1) % HASH_SIZE;

        if (pos == start)
            break;
    }

    return -1;
}

// Expand one complete BFS level
int expandBFS(
    int current[],
    int *currentSize,
    int next[],
    int *nextSize,
    int distanceHere[],
    int distanceOther[],
    int L){
    *nextSize = 0;

    int best = -1;

    for (int i = 0; i < *currentSize; i++){
        int u = current[i];

        char temp[11];
        strcpy(temp, words[u]);

        // Change one character at a time
        for (int j = 0; j < L; j++){
            char original = temp[j];

            for (char ch = 'a'; ch <= 'z'; ch++){
                if (ch == original)
                    continue;

                temp[j] = ch;

                int v = findWord(temp);

                if (v == -1)
                    continue;

                if (distanceHere[v] == -1){
                    distanceHere[v] = distanceHere[u] + 1;

                    next[(*nextSize)++] = v;
                }

                // Check whether both searches have met
                if (distanceOther[v] != -1){
                    int total = distanceHere[v] +
                                distanceOther[v];

                    if (best == -1 || total < best)
                        best = total;
                }
            }

            temp[j] = original;
        }
    }

    return best;
}

int main(){
    int N, L;

    char A[11], B[11];

    printf("Enter number of dictionary words: ");
    scanf("%d", &N);

    if (N <= 0 || N >= MAXN){
        printf("Invalid dictionary size.\n");
        return 0;
    }

    printf("Enter word length: ");
    scanf("%d", &L);

    if (L <= 0 || L > 10){
        printf("Invalid word length.\n");
        return 0;
    }

    for (int i = 0; i < HASH_SIZE; i++)
        hashTable[i] = -1;

    printf("Enter dictionary words:\n");

    for (int i = 0; i < N; i++){
        scanf("%10s", words[i]);

        if (strlen(words[i]) != L){
            printf("Invalid word length.\n");
            return 0;
        }

        insertWord(i);
    }

    printf("Enter starting word: ");
    scanf("%10s", A);

    printf("Enter target word: ");
    scanf("%10s", B);

    if (strlen(A) != L || strlen(B) != L){
        printf("Invalid word length.\n");
        return 0;
    }

    // Target must exist in dictionary
    int target = findWord(B);

    if (target == -1){
        printf("No valid transformation exists.\n");
        return 0;
    }

    // Find starting word
    int start = findWord(A);

    // Starting word may be outside dictionary
    if (start == -1){
        start = N;
        strcpy(words[start], A);
        insertWord(start);
    }

    if (strcmp(A, B) == 0){
        printf("Minimum transformations = 0\n");
        return 0;
    }

    // Initialize distance arrays
    for (int i = 0; i <= N; i++){
        distA[i] = -1;
        distB[i] = -1;
    }

    // Two BFS frontiers
    int frontA[MAXN], frontB[MAXN];
    int nextA[MAXN], nextB[MAXN];

    int sizeA = 1;
    int sizeB = 1;

    frontA[0] = start;
    frontB[0] = target;

    distA[start] = 0;
    distB[target] = 0;

    int answer = -1;

    // Bidirectional BFS
    while (sizeA > 0 && sizeB > 0){
        int nextSize = 0;

        if (sizeA <= sizeB){
            answer = expandBFS(
                frontA, &sizeA,
                nextA, &nextSize,
                distA, distB, L
            );

            if (answer != -1)
                break;

            sizeA = nextSize;

            for (int i = 0; i < sizeA; i++)
                frontA[i] = nextA[i];
        }
        else{
            answer = expandBFS(
                frontB, &sizeB,
                nextB, &nextSize,
                distB, distA, L
            );

            if (answer != -1)
                break;

            sizeB = nextSize;

            for (int i = 0; i < sizeB; i++)
                frontB[i] = nextB[i];
        }
    }

    if (answer == -1)
        printf("No valid transformation exists.\n");
    else
        printf("Minimum transformations = %d\n", answer);

    return 0;
}