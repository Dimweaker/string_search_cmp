#include <iostream>
#include "search_tools.h"
#include "clock_tool.h"


int main() {
    std::size_t haystack_size = 1000000;
    std::size_t needle_size = 1000;
    unsigned trial_times = 10;


    std::cout << "abbbbb string" << std::endl;
    std::cout << "haystack size: " << haystack_size << std::endl;
    std::cout << "needle size: " << needle_size << std::endl;
    std::cout << "trial times: " << trial_times << std::endl;
    std::cout << "total time: " << std::endl;

    std::cout << "Boyer-Moore search(Standard): " << trial(boyer_moore_search, haystack_size, needle_size, trial_times, G_ABB) << std::endl;
    std::cout << "Boyer-Moore-Horspool search(Standard): " << trial(boyer_moore_horspool_search, haystack_size, needle_size, trial_times, G_ABB) << std::endl;
    std::cout << "Naive search(Standard): " << trial(naive_search, haystack_size, needle_size, trial_times, G_ABB) << std::endl;
    std::cout << "strstr search(Standard): " << trial(strstr_search, haystack_size, needle_size, trial_times, G_ABB) << std::endl;
    std::cout << "KMP search(Mine): " << trial(kmp_search, haystack_size, needle_size, trial_times, G_ABB) << std::endl;
    std::cout << "Boyer-Moore search(Mine): " << trial(boyer_moore_search2, haystack_size, needle_size, trial_times, G_ABB) << std::endl;
    std::cout << "Naive search(Mine): " << trial(naive_search2, haystack_size, needle_size, trial_times, G_ABB) << std::endl;
    return 0;


}