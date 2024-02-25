#include <bits/stdc++.h>
#include "parking_check.h"

using namespace std;

int main()
{   
    ll leave = true, time;
    initialize_parking_lots_free();
    while(leave) {

        check_time(&current_time);

        verify_and_extend_orange();
        verify_and_extend_purple();
        verify_and_extend_blue();

        inseration(time);
        p_check(time);

        system("cls");
        continue_simulation(&leave);
    }
    return 0;
}
