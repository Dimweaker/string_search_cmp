#include <algorithm>
#include <random>
#include <ctime>
#include <cstring>
#include <string_view>
#include "boyer_moore_search.h"

#ifndef BM_SEARCH_TOOLS_H
#define BM_SEARCH_TOOLS_H

void naive_search(std::string_view needles, std::string_view haystacks);
void boyer_moore_search(std::string_view needles, std::string_view haystacks);
void boyer_moore_horspool_search(std::string_view needles, std::string_view haystacks);
void strstr_search(char* needles, char* haystacks);
void kmp_search(std::string_view needles, std::string_view haystacks);
void naive_search2(std::string_view needles, std::string_view haystacks);

#endif //BM_SEARCH_TOOLS_H
