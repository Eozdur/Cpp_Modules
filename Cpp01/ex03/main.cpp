#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"

int main()    
{
    {
        Weapon club = Weapon("crude spiked club");//club adında silah classı oluştu ve weapon türü girğimiz değer oldu
        HumanA bob("Bob", club);//bob diye bir Humana classı oluştu ve içerisine bob isimi ve club'un silah türü girildi
        bob.attack();//attack çıktısı ekrana yazdırıldı
        club.setType("some other type of club");//silah türü değiştirildi
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club"); // club adlı bir silah sınıfı oluştu ve silah türü girildi
        HumanB jim("Jim");//jim adlı bir humanb classı oluştu ve name değişkeni jim oldu 
        jim.setWeapon(club);//jim'e silah verdik
        jim.attack();//attack çıktısı
        club.setType("some other type of club");//silah tipi değişti
        jim.attack();//çıktı
    }
    return 0;
}
