#include "parking_colors.h"

#define text_red    "\x1b[1;31m"
#define reset       "\x1b[0m"

void inseration (ll &time) {
    system("cls");
    show_time(current_time);
    extra_pay_hours(current_time);
    std::cout << "How long do you want to park your car for:\n(0h - 24h) Hours: ";
    //std::cin >> car.hour; 
    if(!(std::cin >> car.hour)) {
        clear_invalid_input();
        car.hour = 100;
    }
    std::cout << "(15min, 30min, 45min) Minutes: ";
    if(!(std::cin >> car.minutes)) {
        clear_invalid_input();
        car.minutes = 59;
    }
    
    time = car.hour * 60 + car.minutes;
}

void p_check (ll &time) {
    while(time <= 0) {
        system("cls");
        if(time == 0)
            std::cout << text_red "!!!!YOU CANNOT PARK FOR 0 MINUTES NOW PARK AND GIVE ME YOUR MONEY!!!!\n";
        else
            std::cout << text_red "!!!!YOU CANNOT PARK FOR NEGATIVE MINUTES NOW PARK AND GIVE ME YOUR MONEY!!!!\n";
        little_loading();
        std::cout << reset;
        inseration(time);
    }
    if(time <= 60) {
        system("cls");
        parking_orange(time);
        std::cout << "\n";
    }
    else if(time <= 180) {
        system("cls");
        parking_purple(time);
        std::cout << "\n";
    }
    else {
        system("cls");
        parking_blue(time);
        std::cout << "\n";
    }
}

void exit () {
    system("cls");
            std::cout << "how long do you want to skip time? (Minutes)\n";
            std::cout << "---> ";
            std::cin >> skip_time;
            while(skip_time <= 0) {
                if(skip_time == 0) {
                    std::cout << text_red "you cannot skip time for 0 MINUTES";
                    little_loading();
                    system("cls");
                    std::cout << "NOW LET'S TRY AGAIN";
                }
                else if(skip_time < 0){
                    std::cout << text_red "YOU CANNOT REWIND TIMEE!!";
                    little_loading();
                    system("cls");
                    std::cout << "NOW LET'S TRY AGAIN";
                }
                little_loading();
                std::cout << reset;
                exit();
            }
            current_time += skip_time;
            system("cls");
}

void continue_simulation(ll *leave) {
    system("cls");
    std::cout << "Do you want to continue the simulation (1) or stop it (0): ";
    std::cin >> *leave;
    if(*leave)
        exit();
    else
        return;
}
