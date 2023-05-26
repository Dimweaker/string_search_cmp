#include <random>
#include <ctime>

#ifndef BM_CREATE_TOOLS_H
#define BM_CREATE_TOOLS_H

#define G_RANDOM 0
#define G_SAME_CHARACTERS 1
#define G_AAB 2
#define G_ABB 3
#define MIN_CHAR 65
#define MAX_CHAR 68

char* create_haystacks(std::size_t size_of_haystacks, int type = G_RANDOM);
char* generate_needles(const char* haystacks, std::size_t size_of_needles, int type = G_RANDOM);
#endif //BM_CREATE_TOOLS_H
