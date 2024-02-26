#include <iostream> // prijungiame biblioteką, kuri atsakinga už kiekvienos eilutės veikimą

using namespace std; // ši eilutė leidžia nerašyti std:: prieš funkcijas

// Funkcija, kuri patikrina, ar mėnuo turi 31 dieną
bool turi31Diena(int menuo) {
    int menesiaiSu31Diena[] = {1, 3, 5, 7, 8, 10, 12}; // Mėnesiai, turintys 31 dieną

    for (int i = 0; i < 7; i++) { // Ciklas per mėnesius su 31 diena
        if (menuo == menesiaiSu31Diena[i]) { // Tikriname, ar nurodytas mėnuo yra vienas iš masyvo elementų
            return true; // Jei taip, grąžiname true
        }
    }
    return false; // Grąžiname false, jei nėra tokio mėnesio
}

// Funkcija, kuri skaičiuoja savaitės dieną
int Matematika(int menuo, int metai) { // Funkcijos apibrėžimas, kuri skaičiuoja savaitės dieną
    if (menuo == 1) {
        menuo += 12;
        metai--;
    }
    int amzius = metai / 100; // Skaičiuojame amžių
    int metaiSimtmetyje = metai % 100; // Skaičiuojame metus šimtmečiuose

    int savDiena = (1 + (13 * (menuo + 1)) / 5 + metaiSimtmetyje + (metaiSimtmetyje / 4) + (amzius / 4) + (5 * amzius)) % 7; // Skaičiuojame savaitės dieną

    return savDiena; // Grąžiname savaitės dieną
}

// Funkcija, kuri suranda metus, kai nurodytas mėnuo turi 5 penktadienius, šeštadienius ir sekmadienius
void rasti_Metus_Su_dienomis(int pradziosMetai, int pabaigosMetai, int menuo) { // Funkcijos apibrėžimas, kuri ieško metų, kai nurodytas mėnuo turi 5 penktadienius, šeštadienius ir sekmadienius
    if (!turi31Diena(menuo)) { // Tikriname, ar nurodytas mėnuo turi 31 dieną
        cout << "Šis mėnuo negali turėti šių savybių." << endl; // Jei ne, išvedame pranešimą ir nutraukiame funkciją
        return;
    }

    int paskutiniaiMetai = -1; // Kintamasis, kuriame saugosime paskutinį rastą metus

    // Ieškoti pirmų metų, kai sąlyga yra patenkinta
    for (int i = pradziosMetai; i < pabaigosMetai; i++) { // Einame per visus metus nuo pradžios iki pabaigos
        if (Matematika(menuo, i) == 6) { // Tikriname, ar šeštadienis pagal Zellerio konvergenciją
            cout << i << endl; // Jei taip, išvedame metus
            paskutiniaiMetai = i; // Atnaujiname paskutinius rastus metus
            break; // Nutraukiame ciklą, nes radome pirmą metų, kai sąlyga yra patenkinta
        }
    }

    // Ieškoti kitų metų, kai sąlyga yra patenkinta
    for (int i = paskutiniaiMetai + 1; i < pabaigosMetai; i++) { // Tęsiame paiešką nuo paskutinio rasto metų + 1
        if (Matematika(menuo, i) == 6) { // Tikriname, ar šeštadienis pagal Zellerio konvergenciją
            cout << i << " (" << i - paskutiniaiMetai << " metų skirtumas)" << endl; // Jei taip, išvedame metus ir skirtumą nuo paskutinio rasto metų
            paskutiniaiMetai = i; // Atnaujiname paskutinius rastus metus
        }
    }
}

int main() {
    setlocale(LC_ALL, "Lithuanian"); // Nustatome lietuvių kalbą, kad konsolėje išvestas tekstas būtų lietuviškas

    cout << "Ieškoma mėnesio, kuris turi 5 penktadienius, šeštadienius ir sekmadienius." << endl; // Informacinis pranešimas
    cout << "Šis programa nustatys, kiek kartų jūsų nurodytas mėnuo pasikartoja tarp nurodytų metų." << endl; // Informacinis pranešimas
    cout << "------------------------------------------------------" << endl; // Atskiriamoji linija

    cout << "Įveskite pradinius metus: "; // Prašymas įvesti pradinius metus
    int pradziosMetai; // Kintamasis, kuriame saugosime pradinius metus
    cin >> pradziosMetai; // Įvedame pradinius metus

    cout << "Įveskite pabaigos metus: "; // Prašymas įvesti pabaigos metus
    int pabaigosMetai; // Kintamasis, kuriame saugosime pabaigos metus
    cin >> pabaigosMetai; // Įvedame pabaigos metus

    cout << "Įveskite ieškomo mėnesio numerį: "; // Prašymas įvesti ieškomo mėnesio numerį
    int menuo; // Kintamasis, kuriame saugosime ieškomo mėnesio numerį
    cin >> menuo; // Įvedame ieškomo mėnesio numerį

    rasti_Metus_Su_dienomis(pradziosMetai, pabaigosMetai, menuo); // Kviečiame funkciją, kuri suranda metus, kai nurodytas mėnuo turi 5 penktadienius, šeštadienius ir sekmadienius

    return 0; // Grąžiname nulį, nurodydami, kad programa baigė darbą sėkmingai
}
