#include "create_tools.h"

char* create_haystacks(std::size_t size_of_haystacks, int type) {
    char* haystacks = new char[size_of_haystacks];
    std::default_random_engine generator((unsigned int)time(nullptr));
    std::uniform_int_distribution<int> distribution(MIN_CHAR, MAX_CHAR);
    char c = (char)distribution(generator);
    switch (type) {
        case G_RANDOM:
            for (std::size_t i = 0; i < size_of_haystacks; ++i) {
                haystacks[i] = (char)distribution(generator);
            }
            break;
        case G_SAME_CHARACTERS:
            for (std::size_t i = 0; i < size_of_haystacks; ++i) {
                haystacks[i] = c;
            }
            break;
        case G_AAB:
            for (std::size_t i = 0; i < size_of_haystacks; ++i) {
                haystacks[i] = 'A';
            }
            break;
        case G_ABB:
            for (std::size_t i = 0; i < size_of_haystacks; ++i) {
                haystacks[i] = 'B';
            }
            break;
        default:
            break;
    }
    return haystacks;
}

char* generate_needles(const char* haystacks, std::size_t size_of_needles, int type) {
    char* needles = new char[size_of_needles];
    std::default_random_engine generator((unsigned int)time(nullptr));
    std::uniform_int_distribution<int> distribution(MIN_CHAR, MAX_CHAR);
    char c = (char)distribution(generator);
    switch (type) {
        case G_RANDOM:
            for (std::size_t i = 0; i < size_of_needles; ++i) {
                needles[i] = (char)distribution(generator);
            }
            break;
        case G_SAME_CHARACTERS:
            for (std::size_t i = 0; i < size_of_needles; ++i) {
                needles[i] = c;
            }
            break;
        case G_AAB:
            for (std::size_t i = 0; i < size_of_needles - 1; ++i) {
                needles[i] = 'A';
            }
            needles[size_of_needles - 1] = 'B';
            break;
        case G_ABB:
            needles[0] = 'A';
            for (std::size_t i = 1; i < size_of_needles; ++i) {
                needles[i] = 'B';
            }
            break;
        default:
            break;
    }
    return needles;
}