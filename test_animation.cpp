#include <bits/stdc++.h>
#include <windows.h>
#include <unistd.h>
#define ll long long

using namespace std;

void solve() {
    ll max = 0, it = 1;
    cout << "\n";
    while(max != 19) {
        system("cls");
        cout << "       LOADING\n";
        cout << "--------------------";
        cout << "\n";
        cout << "|";
        for(ll j = 0; j < it-1; j++) {
            cout << char(35);
        }

        for(ll j = 0; j < 18 - max; j++)
            cout << " ";

        cout << "|";
        cout << "\n";
        cout << "--------------------";
        max++;
        it++;
        Sleep(200);
    }
}

int main() {   
    cout << "se face plata....."; 
    solve();

    return 0;
}
