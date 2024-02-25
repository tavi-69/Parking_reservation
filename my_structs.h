#include <iostream> 
#include <map>
#include <list>

#define ll long long

struct car_time{
    ll hour;
    ll minutes;
};

struct parking_area{
    //15min-1h
    struct orange{
        std::list<std::string> ID {"ID-001", "ID-002", "ID-003"};
        std::map<std::string, ll> ID_status;
        ll max_capacity = 3; // 20 cars
        ll curr_capacity = 0;
        ll hour_price = 20;
        ll super_price = 50; //between 09:00 - 11:00  (540 - 660)
    };
    //15min-3h
    struct purple{
        std::list<std::string> ID {"ID-004", "ID-005"};
        std::map<std::string, ll> ID_status;
        ll max_capacity = 3; // 30 cars
        ll curr_capacity = 0;
        ll hour_price = 30;
        ll super_price = 80; //between 00:00 - 07:00 (0 - 420)
    };
    //15min-24-h
    struct blue{
        std::list<std::string> ID {"ID-006", "ID-007"};
        std::map<std::string, ll> ID_status;
        ll max_capacity = 2; // 50 cars
        ll curr_capacity = 0;
        ll hour_price = 50;
        ll super_price = 100; //between 00:00 - 12:00 (0 - 720)
    };
};