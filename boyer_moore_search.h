#include <string_view>
#include <iostream>
#ifndef BM_BOYER_MOORE_SEARCH2_H
#define BM_BOYER_MOORE_SEARCH2_H
void create_bad_character_table(std::string_view needles, int* bad_character_table);
void create_good_suffix_table(std::string_view needles, int* good_suffix_table, bool* is_prefix);
int get_move_length(int* good_suffix_table, const bool* is_prefix, int index, int size);
void boyer_moore_search2(std::string_view needles, std::string_view haystacks);

#endif //BM_BOYER_MOORE_SEARCH2_H
