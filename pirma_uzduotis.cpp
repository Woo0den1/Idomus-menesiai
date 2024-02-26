#include <iostream> // Prijungiame biblioteką, kuri atsakinga už kiekvienos eilutės veikimą
#include <string> // Pridedame biblioteką, kad galėtume naudoti string tipo kintamuosius

using namespace std; // Ši eilutė leidžia nerašyti std:: prieš funkcijas

// Funkcija, kuri apskaičiuoja, kiekvieno mėnesio kelintadienį jis prasideda
int kelintadienis(int menuo, int metai) {
    if (menuo == 1) { // Jei mėnuo yra sausis, perkeliame jį į praėjusius metus
        menuo += 12;
        metai--;
    }
    int puse1 = metai / 100; // Įvedame pusės metų kintamajį, padaliname metus per pusę, funkcijos naudojimui
    int puse2 = metai % 100; // Dešimčių liekana //formulė, skirta surasti kelintadienis buvo ivesta data
    int kelinta = (1 + (13 * (menuo + 1)) / 5 + puse2 + (puse2 / 4) + (puse1 / 4) + (5 * puse1)) % 7;
    return kelinta; //Grąžiname atsakymą
}

int main() { // Pagrindinė programos funkcija

    setlocale(LC_ALL, "Lithuanian"); // Išvedimui naudojame lietuvių kalbą

    cout << "Menesio, kuris turi 5 penktadienius, sestadienius ir sekmadienius, paieska" << endl; // Užduoties pavadinimas
    cout << "----------------------------------" << endl; // Užduotis atskiriama nuo atsakymų
    cout << "Iveskite nuo kelintu metu pradeti: "; // Vartotojo prašoma įvesti, nuo kelintų metų jis nori tikrinti informciją
    int prad_metai;
    cin >> prad_metai; //Įvedamas pradinių metų kintamasis, kuriam priskiriama vartotojo įrašyta reikšmė
    cout << "Iveskite kuriais metais baigti: "; // Vartotojo prašoma įvesti metus, kuriais jis nori užbaigti skaičiavimus
    int baig_metai;
    cin >> baig_metai; // Įvedamas baigiamųjų metų kintamasis, kuriam priskiriama vartotojo įrašyta reikšmė

    int menesiai[7] = {1, 3, 5, 7, 8, 10, 12};  // Mėnesiai, kurie turi 31 dieną
    string pavadinimai[7] = {"Sausis", "Kovas", "Geguze", "Liepa", "Rugpjutis", "Spalis", "Gruodis"};  // Masyvui priskiriami mėnesių pavadinimai

    // Ciklas, kuris apskaičiuoja, kada buvo "Įdomūs mėnesiai"
    for (int i = 0; i < baig_metai - prad_metai; i++) { // Ciklas kartosis tiek kartų, kiek vartotojas nori, kad apskaičiuotų metų
        for (int g = 0; g < 7; g++) { // Ciklas cikle, kuris pereina per kiekvieną iš galimų mėnesių
            if (kelintadienis(menesiai[g], prad_metai + i) == 6) { // Iškviečiama formulė, kuri patikrina mėnesius
                cout << endl << prad_metai + i << " " << pavadinimai[g];  // Išvedamas atsakymas
            }
        }
    }
    return 0;
}
