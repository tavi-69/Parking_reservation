#include <unistd.h>
#include <windows.h>
#include "visuals.h"
#include "definitions.h"
#include "clear_ivalid_input.h"

#define ll long long
#define text_black  "\x1b[30m"
#define text_green  "\x1b[32m"
#define text_red    "\x1b[1;31m"
#define text_orange "\x1b[38;5;208m"
#define text_purple "\x1b[35m"
#define text_blue   "\x1b[34m"
#define reset       "\x1b[0m"



void loading () {
    ll max = 0, it = 1, time;
    std::cout << "\n";
    while(max != 19) {
        system("cls");
        std::cout << text_blue "     PROCESSING\n" reset;
        std::cout << text_black "--------------------" reset;
        std::cout << "\n";
        std::cout << text_black "|" reset;
        for(ll j = 0; j < it-1; j++) {
            if(max == 18)
                std::cout << text_green "#" reset;
            else
                std::cout << "#";
        }

        for(ll j = 0; j < 18 - max; j++)
            std::cout << " ";

        std::cout << text_black "|" reset;
        std::cout << "\n";
        std::cout << text_black "--------------------" reset;
        max++;
        it++;
        Sleep(200);
    }

    Sleep(500);
    system("cls");
    std::cout << text_green "The payment was succesfull" reset;
    little_loading();    
}


void initialize_parking_lots_free (){
    //setting all parking places with 0 (available)
    for(const auto& it: orange_area.ID)
        orange_area.ID_status[it] = 0;

    for(const auto& it: purple_area.ID)
        purple_area.ID_status[it] = 0;

    for(const auto& it: blue_area.ID)
        blue_area.ID_status[it] = 0;
}

void extend_time_input () {
    std::cout << "Enter the time you want to extend your stay:\n";
    std::cout << "(0h - 24h)\nHours: ";
    std::cin >> car.hour;
    std::cout << "(15min, 30min, 45min)\nMinutes: ";
    std::cin >> car.minutes;
}

void parking_blue (ll time) {
    for(const auto& it: blue_area.ID)
            if(blue_area.ID_status[it] == 0){
                std::cout << "your parking spot is: " << it << "\n";
                blue_area.ID_status[it] = time;
                break;
            }
    blue_area.curr_capacity++;
    //only if parking lot is full
    if(blue_area.curr_capacity > blue_area.max_capacity){
        blue_area.curr_capacity--;
        std::cout << "There are no more parking spots, please come back later, Have a good day!";
        little_loading();
        return;            
    }

    ll price = blue_area.hour_price * car.hour + blue_area.hour_price * car.minutes/60;
    if(current_time >= 0 && current_time <= 720) {
        ll extra_price = blue_area.super_price * car.hour + blue_area.super_price * car.minutes/60;
        std::cout << "You will have to pay " << extra_price << "$";
        std::cout << "\n";
        std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
        ll pay;
        std::cin >> pay;
        if(pay)
            loading();
        else{
            blue_area.curr_capacity--;
            for(const auto& it: blue_area.ID)
                if(blue_area.ID_status[it] == time){
                    std::cout << "your parking spot is: " << it << "\n";
                    blue_area.ID_status[it] = 0;
                    break;
            }
            system("cls");
            return;
        }
    }
    else {
        std::cout << "You will have to pay " << price << "$";
        std::cout << "\n";
        std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
        ll pay;
        std::cin >> pay;
        if(pay)
            loading();
        else{
            system("cls");
            return;
        }
    }
}
void parking_purple (ll time){
    for(const auto& it: purple_area.ID)
            if(purple_area.ID_status[it] == 0){
                std::cout << "your parking spot is: " << it << "\n";
                purple_area.ID_status[it] = time;
                break;
            }
    purple_area.curr_capacity++;
    //only if parking lot is full
    if(purple_area.curr_capacity > purple_area.max_capacity){
        purple_area.curr_capacity--;
        parking_blue(time);
        return;
    }

    ll price = purple_area.hour_price * car.hour + purple_area.hour_price * car.minutes/60;
    if(current_time >= 0 && current_time <= 420) {
        ll extra_price = purple_area.super_price * car.hour + purple_area.super_price * car.minutes/60;
        std::cout << "You will have to pay " << extra_price << "$";
        std::cout << "\n";
        std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
        ll pay;
        std::cin >> pay;
        if(pay)
            loading();
        else{
            purple_area.curr_capacity--;
            for(const auto& it: purple_area.ID)
                if(purple_area.ID_status[it] == time){
                    std::cout << "your parking spot is: " << it << "\n";
                    purple_area.ID_status[it] = 0;
                    break;
            }
            system("cls");
            return;
        }
    }
    else {
        std::cout << "You will have to pay " << price << "$";
        std::cout << "\n";
        std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
        ll pay;
        std::cin >> pay;
        if(pay)
            loading();
        else{
            system("cls");
            return;
        }
    }
}
void parking_orange (ll time){
    for(const auto& it: orange_area.ID)
            if(orange_area.ID_status[it] == 0){
                std::cout << "your parking spot is: " << it << "\n";
                orange_area.ID_status[it] = time;
                break;
            }
    
    orange_area.curr_capacity++;
    //only if parking lot is full
    if(orange_area.curr_capacity > orange_area.max_capacity){
        orange_area.curr_capacity--;
        parking_purple(time);
        return;
    }

    ll price = orange_area.hour_price * car.hour + orange_area.hour_price * car.minutes/60;
    if(current_time >= 540 && current_time <= 660) {
        ll extra_price = orange_area.super_price * car.hour + orange_area.super_price * car.minutes/60;
        std::cout << "You will have to pay " << extra_price << "$";
        std::cout << "\n";
        std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
        ll pay;
        std::cin >> pay;
        if(pay)
            loading();
        else{
            orange_area.curr_capacity--;
            for(const auto& it: orange_area.ID)
                if(orange_area.ID_status[it] == time){
                    std::cout << "your parking spot is: " << it << "\n";
                    orange_area.ID_status[it] = 0;
                    break;
            }
            system("cls");
            return;
        }
    }
    else {
        std::cout << "You will have to pay " << price << "$";
        std::cout << "\n";
        std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
        ll pay;
        std::cin >> pay;
        if(pay)
            loading();
        else{
            system("cls");
            return;
        }
    }   
}

void verify_and_extend_blue () {
    for(const auto& it: blue_area.ID) {
        if(blue_area.ID_status[it] != 0){
            blue_area.ID_status[it] -= skip_time;
            if(blue_area.ID_status[it] == 10) {
                ll response;
                std::cout << "The parking spot with the ID: " << it << " has only 10 minutes left\n";
                std::cout << "Do you want to extend your stay?\n" << "0 - NO\n1 - YES\n->";
                std::cin >> response;
                if(response) {
                    system("cls");
                    extend_time_input();
                    ll price = blue_area.hour_price * car.hour + blue_area.hour_price * car.minutes/60;
                    std::cout << "You will have to pay " << price << "$";
                    ll extend_time = car.hour * 60 + car.minutes;
                    blue_area.ID_status[it] += extend_time;
                    std::cout << "\n";
                    std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
                    ll pay;
                    std::cin >> pay;
                    if(pay)
                        loading();
                    else{
                        system("cls");
                        return;
                    }
                }
                else
                    system("cls");
            }
        }
    }
}

void verify_and_extend_orange () {
        for(const auto& it: orange_area.ID) {
        if(orange_area.ID_status[it] != 0){
            orange_area.ID_status[it] -= skip_time;
            if(orange_area.ID_status[it] == 10) {
                ll response;
                std::cout << "The parking spot with the ID: " << it << " has only 10 minutes left\n";
                std::cout << "Do you want to extend your stay?\n" << "0 - NO\n1 - YES\n->";
                std::cin >> response;
                if(response) {
                    system("cls");
                    extend_time_input();
                    ll price = orange_area.hour_price * car.hour + orange_area.hour_price * car.minutes/60;
                    std::cout << "You will have to pay " << price << "$";
                    ll extend_time = car.hour * 60 + car.minutes;
                    orange_area.ID_status[it] += extend_time;
                    std::cout << "\n";
                    std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
                    ll pay;
                    std::cin >> pay;
                    if(pay)
                        loading();
                    else{
                        system("cls");
                        return;
                    }
                }
                else
                    system("cls");
            }
        }
    }
}

void verify_and_extend_purple() {
    for(const auto& it: purple_area.ID) {
        if(purple_area.ID_status[it] != 0){
            purple_area.ID_status[it] -= skip_time;
            if(purple_area.ID_status[it] == 10) {
                ll response;
                std::cout << "The parking spot with the ID: " << it << " has only 10 minutes left\n";
                std::cout << "Do you want to extend your stay?\n" << "0 - NO\n1 - YES\n->";
                std::cin >> response;
                if(response) {
                    system("cls");
                    extend_time_input();
                    ll price = purple_area.hour_price * car.hour + purple_area.hour_price * car.minutes/60;
                    std::cout << "You will have to pay " << price << "$";
                    ll extend_time = car.hour * 60 + car.minutes;
                    purple_area.ID_status[it] += extend_time;
                    std::cout << "\n";
                    std::cout << "\n\nDo you want to pay?\n--(1)YES\n--(0)NO\n--> ";
                    ll pay;
                    std::cin >> pay;
                    if(pay)
                        loading();
                    else{
                        system("cls");
                        return;
                    }
                }
                else
                    system("cls");
            }
        }
    }
}
void extra_pay_hours (ll current_time) {
    if(current_time >= 540 && current_time <= 660) {
        std::cout << text_orange "!!! THE ORANGE PARKING LOT IS AT EXTRA PRICE AT THIS HOUR !!!  " reset << "(" << orange_area.super_price << "$)\n";
    }
    if(current_time >= 0 && current_time <= 420) {
        std::cout << text_purple "!!! THE PURPLE PARKING LOT IS AT EXTRA PRICE AT THIS HOUR !!!  " reset << "(" << purple_area.super_price << "$)\n";
    }
    if(current_time >= 0 && current_time <= 720) {
        std::cout << text_blue "!!! THE BLUE PARKING LOT IS AT EXTRA PRICE AT THIS HOUR !!!  " reset << "(" << blue_area.super_price << "$)\n";
    }
}