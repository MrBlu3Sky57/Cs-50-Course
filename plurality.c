#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

 // Type for candidates that gives them a name and their number of votes
    typedef struct
    {
        char *name;
        int votes;
    }
    candidate;


bool *votes(int num_votes, candidate *candidates, int num_candidates);
void merge_sort(int start_index, int end_index, candidate *candidates);
int binary_search (candidate *sorted_candidates, int num_candidates, char *target);
void print_winner(bool *winners, int num_candidates, candidate *candidates);

int main(int argc, char **argv)
{
    int num_candidates = argc - 1;
    candidate candidates[num_candidates];

    // Set each candidate's name and initial vote count
    for (int i = 0; i < num_candidates; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Sort list of candidates
    merge_sort(0, num_candidates, candidates);

    int num_votes;

    printf("Number of voters: ");
    scanf("%i", &num_votes);

    bool *winners = votes(num_votes, candidates, num_candidates);

    print_winner(winners, num_candidates, candidates);
}

bool *votes(int num_votes, candidate *candidates, int num_candidates)
{
    int best_votes = 0;
    bool *winners;

    // Get votes
    for (int i = 0; i < num_votes; i++)
    {
        int index;
        do
        {
            char input[50];

            printf("Vote: ");
            scanf("%s", input);

            index = binary_search(candidates, num_candidates, input);

            if (index == -1)
            {
                printf("Invalid vote.\n");
            }

            else
            {
                candidates[index].votes++;

                if (candidates[index].votes > best_votes)
                {
                    winners = malloc(sizeof(bool) * num_candidates);

                    winners[index] = true;
                    best_votes = candidates[index].votes;
                }

                else if (candidates[index].votes == best_votes)
                {
                    winners[index] = true;
                }
            }
        }
        while(index == -1);
    }
    return winners;
}

void merge(int start_index, int mid_index, int final_index, candidate *candidates)
{
    int i, j, k;
    int len_left = mid_index - start_index + 1;
    int len_right = final_index - mid_index;

    candidate temp_left[len_left], temp_right[len_right];

    // Copy data to temp arrays
    for (int l = 0; l < len_left; l++)
    {
        temp_left[l] = candidates[start_index + l];
    }

    for (int r = 0; r < len_right; r++)
    {
        temp_right[r] = candidates[mid_index + 1 + r];
    }

    i = 0;
    j = 0;
    k = start_index;

    // Merge sorted sub arrays
    while (i < len_left && j < len_right)
    {
        if (strcmp(temp_left[i].name, temp_right[j].name) <= 0)
        {
            candidates[k] = temp_left[i];
            i++;
        }

        else
        {
            candidates[k] = temp_right[j];
            j++;
        }
        k++;
    }

    //Copy remaining elements (if any)
    while (i < len_left)
    {
        candidates[k] = temp_left[i];
        i++;
        k++;
    }

    while (j < len_right)
    {
        candidates[k] = temp_right[j];
        j++;
        k++;
    }


}

void merge_sort(int start_index, int end_index, candidate *candidates)
{
    if (start_index < end_index)
    {
        int mid_index = (start_index + end_index) / 2;

        merge_sort(start_index, mid_index, candidates);
        merge_sort(mid_index + 1, end_index, candidates);

        merge(start_index, mid_index, end_index, candidates);
    }
}

// Returns index of element. If element does not exist returns -1
int binary_search (candidate *sorted_candidates, int num_candidates, char *target)
{
    int first_index = 0;
    int final_index = num_candidates - 1;

    while (first_index != final_index)
    {
        int middle = (first_index + final_index + 1) / 2;

        if (strcmp(sorted_candidates[middle].name, target) == 0)
        {
            return middle;
        }

        else if (strcmp(sorted_candidates[middle].name, target) < 0)
        {
            first_index = middle + 1;
        }

        else
        {
            final_index = middle - 1;
        }
    }

    if (strcmp(sorted_candidates[first_index].name, target) == 0)
    {
        return first_index;
    }
    return -1;
}

void print_winner(bool *winners, int num_candidates, candidate *candidates)
{
    for (int i = 0; i < num_candidates; i++)
    {
        if (winners[i] == true)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

