#include <iostream>
#include "Repository.h"
#include "Service.h"
#include "UI.h"
#include "all_tests.h"
int main() {
    all_tests();
    Repository repo("vehicles.txt");
    Service service(repo);
    UI console(service);
    console.run_menu();
    return 0;
}
