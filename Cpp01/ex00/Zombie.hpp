#include <iostream>

/*
constructor -> bir nesne oluşunca çağırılan özel fonksiyondur(initalize)
gerekli başlatma durumlarını bu şekilde ayarlayabiliriz

destructor -> bir nesne sonlanırken otomatik çağılırın (free)
çıkış durumunu yazdırmak için kullanılabilir
*/
class   Zombie
{
    private:
        std::string name;
    public:
        ~Zombie();
        Zombie(std::string);
        void announce();
};
Zombie *newZombie(std::string name);
void randomChump(std::string name);
