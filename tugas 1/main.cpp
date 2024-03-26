#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan status karakter
struct CharacterStatus {
    int hp;
    int mana;
    int damage;
    string equipped_sword;
};

// Struktur untuk menyimpan informasi item
struct Item {
    string name;
    string type;
    int effect;
};

// Fungsi untuk menampilkan status karakter
void displayCharacterStatus(CharacterStatus character) {
    cout << "Character Status:" << endl;
    cout << "HP: " << character.hp << endl;
    cout << "Mana: " << character.mana << endl;
    cout << "Damage: " << character.damage << endl;
    cout << "Equipped Sword: " << character.equipped_sword << endl;
}

// Fungsi untuk menggunakan item
void useItem(CharacterStatus &character, Item &item) {
    if (item.type == "hp_potion") {
        character.hp += item.effect;
        cout << "HP Potion digunakan. HP bertambah sebesar " << item.effect << endl;
        // Mengurangi stok item
        item.effect = 0; // Mengosongkan efek untuk menandakan item telah digunakan
    } else {
        cout << "Item tidak dapat digunakan." << endl;
    }
}

int main() {
    // Input status karakter
    CharacterStatus player;
    cout << "Masukkan status karakter:" << endl;
    cout << "HP: ";
    cin >> player.hp;
    cout << "Mana: ";
    cin >> player.mana;
    cout << "Damage: ";
    cin >> player.damage;
    cout << "Equipped Sword: ";
    cin >> player.equipped_sword;

    // Item
    Item hp_potion = {"HP Potion", "hp_potion", 50};

    // Menampilkan status awal karakter
    displayCharacterStatus(player);

    // Menampilkan item dan statusnya
    cout << "\nItem:" << endl;
    cout << "Name: " << hp_potion.name << endl;
    cout << "Type: " << hp_potion.type << endl;
    cout << "Effect: " << hp_potion.effect << " HP" << endl;

    // Menggunakan item
    useItem(player, hp_potion);

    // Menampilkan status setelah menggunakan item
    cout << "\nStatus setelah menggunakan item:" << endl;
    displayCharacterStatus(player);

    return 0;
}
