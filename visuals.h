#include <iostream>
#include <unistd.h>

#define ll long long

void little_loading () {
    std::cout << ".";
    Sleep(550);
    std::cout << ".";
    Sleep(550);
    std::cout << ".";
    Sleep(550);
    std::cout << ".";
    Sleep(550);
    std::cout << ".";
    Sleep(550);
    std::cout << ".";
}

void show_time (ll current_time) {
    ll hour = current_time / 60;
    ll minutes = current_time % 60;
    std::cout << "The current time is: ";
    if(hour < 10)
        std::cout << "0" << hour << ":";
    else
        std::cout << hour << ":";
    if(minutes < 10)
        std::cout << "0" << minutes << "\n";
    else
        std::cout << minutes << "\n";
}

void check_time(ll *current_time) {
    if(*current_time > 1439)
        *current_time = *current_time % 1440;
}
