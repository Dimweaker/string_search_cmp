#include <iostream>
#include <ctime>
#include "create_tools.h"
#include "search_tools.h"

#ifndef BM_CLOCK_TOOL_H
#define BM_CLOCK_TOOL_H
template <typename my_string>
double search_time(void (*search)(my_string, my_string), my_string needles, my_string haystacks) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    search(needles, haystacks);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

template <typename my_string>
double trial(void (*search)(my_string, my_string),
             std::size_t haystack_size, std::size_t needle_size,
             unsigned trial_times, int type_flag);

template <>
double trial<char*>(void (*search)(char*, char*),
                    std::size_t haystack_size, std::size_t needle_size,
                    unsigned trial_times, int type_flag) {
    double total_time = 0;
    for (unsigned i = 0; i < trial_times; ++i) {
        char* haystacks = create_haystacks(haystack_size, type_flag);
        char* needles = generate_needles(haystacks, needle_size, type_flag);
        total_time += search_time(search, needles, haystacks);
        delete[] haystacks;
        delete[] needles;
    }
    return total_time;
}

template <>
double trial<std::string_view>(void (*search)(std::string_view, std::string_view),
                               std::size_t haystack_size, std::size_t needle_size,
                               unsigned trial_times, int type_flag) {
    double total_time = 0;
    for (unsigned i = 0; i < trial_times; ++i) {
        char* haystacks = create_haystacks(haystack_size, type_flag);
        char* needles = generate_needles(haystacks, needle_size, type_flag);
        std::string_view haystacks_view(haystacks, haystack_size);
        std::string_view needles_view(needles, needle_size);
        total_time += search_time(search, needles_view, haystacks_view);
        delete[] haystacks;
        delete[] needles;
    }
    return total_time;
}

#endif //BM_CLOCK_TOOL_H
