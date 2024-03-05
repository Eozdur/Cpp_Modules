#include "ClapTrap.hpp"

int main(){
    Claptrap c;
    Claptrap a("Timur");
    Claptrap b("Emre");
    Claptrap d(b);
    Claptrap f;
    f = a;
    int i = 0;

    b.takeDamage(30);
    b.beRepaired(10);

    d.attack("ismail");
    f.attack("yıldırım");
    std::cout << std::endl;
    c.attack("caner");
    c.attack("Caner");
    c.takeDamage(50);
    c.beRepaired(10);
    a.beRepaired(10);
    a.beRepaired(30);
	std::cout << std::endl;
    while(i < 10)
    {
    a.attack("Bayezid");
    i++;
    }
}