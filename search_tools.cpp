#include "search_tools.h"

void naive_search(std::string_view needles, std::string_view haystacks) {
    std::search(haystacks.begin(), haystacks.end(), needles.begin(), needles.end());
}

void boyer_moore_search(std::string_view needles, std::string_view haystacks) {
    std::boyer_moore_searcher searcher(needles.begin(), needles.end());
    std::search(haystacks.begin(), haystacks.end(), searcher);
}

void boyer_moore_horspool_search(std::string_view needles, std::string_view haystacks) {
    std::boyer_moore_horspool_searcher searcher(needles.begin(), needles.end());
    std::search(haystacks.begin(), haystacks.end(), searcher);
}

void strstr_search(char* needles, char* haystacks) {
    std::strstr(haystacks, needles);
}

void kmp_search(std::string_view needles, std::string_view haystacks) {
    auto* pi = new unsigned int[needles.size()];
    pi[0] = 0;
    unsigned int k = 0;
    for (unsigned int i = 1; i < needles.size(); ++i) {
        while (k > 0 && needles[k] != needles[i]) {
            k = pi[k - 1];
        }
        if (needles[k] == needles[i]) {
            ++k;
        }
        pi[i] = k;
    }
    k = 0;
    for (char haystack : haystacks) {
        while (k > 0 && needles[k] != haystack) {
            k = pi[k - 1];
        }
        if (needles[k] == haystack) {
            ++k;
        }
        if (k == needles.size()) {
            k = pi[k - 1];
        }
    }

    delete[] pi;

}

void naive_search2(std::string_view needles, std::string_view haystacks) {
    std::size_t i, j;
    for (i = 0; i < haystacks.size(); i += j + 1) {
        for (j = 0; j < needles.size(); ++j) {
            if (i + j >= haystacks.size() || needles[j] != haystacks[i + j]) {
                break;
            }
        }
        if (j == needles.size()) {
            break;
        }
    }
}



