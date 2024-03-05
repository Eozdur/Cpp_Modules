#include "Harl.hpp"

int main()
{
    Harl new_harl;
    new_harl.complain("DEBUG");
    new_harl.complain("INFO");
    new_harl.complain("WARNING");
    new_harl.complain("ERROR");
    new_harl.complain("qwewqewqew");
    new_harl.complain("    ");
    new_harl.complain("");
}