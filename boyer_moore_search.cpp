#include "boyer_moore_search.h"

void create_bad_character_table(std::string_view needles, int* bad_character_table) {
    for (int i = 0; i < 128; ++i) {
        bad_character_table[i] = -1;
    }
    for (int i = 0; i < needles.size(); ++i) {
        bad_character_table[needles[i]] = i;
    }
}

void create_good_suffix_table(std::string_view needles, int* good_suffix_table, bool* is_prefix) {
    int needle_size = (int)needles.size();
    for (int i = 0; i < needle_size; ++i) {
        is_prefix[i] = false;
        good_suffix_table[i] = -1;
    }

    for (int i = 0; i < needle_size - 1; ++i) {
        int j = i;
        int k = 0;
        while (j >= 0 && needles[j] == needles[needle_size - 1 - k]) {
            --j;
            ++k;
            good_suffix_table[k] = j + 1;
        }
        if (j == -1) {
            is_prefix[k] = true;
        }
    }
}

int get_move_length(int *good_suffix_table, const bool *is_prefix, int index, int size) {
    int length = size - index - 1;
    if (good_suffix_table[length] != -1) {
        return index - good_suffix_table[length] + 1;
    }
    for (int i = index + 2; i < size; ++i) {
        if (is_prefix[size - i]) {
            return i;
        }
    }
    return size;
}

void boyer_moore_search2(std::string_view needles, std::string_view haystacks) {
    int needle_size = (int)needles.size();
    int haystack_size = (int)haystacks.size();
    int bad_character_table[128];
    int* good_suffix_table = (int*)malloc(sizeof(int) * needle_size);
    bool* is_prefix = (bool*)malloc(sizeof(bool) * needle_size);

    create_bad_character_table(needles, bad_character_table);
    create_good_suffix_table(needles, good_suffix_table, is_prefix);

    int i = 0;
    while (i <= haystack_size - needle_size) {
        int j;
        for (j = needle_size - 1; j >= 0; --j) {
            if (needles[j] != haystacks[i + j]) {
                break;
            }
        }
        if (j < 0) {
            break;
        }
        else {
            int bc_shift = j - bad_character_table[haystacks[i + j]];
            int gs_shift = 0;
            if (j < needle_size - 1) {
                gs_shift = get_move_length(good_suffix_table, is_prefix, j, needle_size);
            }
            i += std::max(bc_shift, gs_shift);
        }
    }
    free(good_suffix_table);
    free(is_prefix);
}