# vu-hashfunction

BlockChain kurso pirmoji užduotis.

Sukurkite Jūsų (t.y. pabandykite neieškoti hash funkcijos realizacijos pavyzdžių internete) maišos funkciją (hash kodų generatorių), kuris
pasižymėtų šiais hash funkcijoms keliamais reikalavimais:

1. Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl. string).

2. Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas (pageidautina 256 bit'ų ilgio, t.y., 64 simbolių
hex'as).

3. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.

4. Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input'o reikšmei yra apskaičiuojamas greitai - efektyviai.

5. Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o).

6. Maišos funkcija yra atspari "kolizijai" (angl. collision resistance), t.y., praktiškai neįmanoma surasti tokių dviejų skirtingų argumentų
, kad jiems gautume tą patį hash'ą:

7. Bent minimaliai pakeitus įvedimą, pvz.vietoj "Lietuva" pateikus "lietuva", maišos funkcijos rezultatas-kodas turi skirtis iš esmės, t.y.,
tenkinamas taip vadinamas lavinos efektas (angl. Avalanche effect). Žemiau esančioje lentelėje iliustruota tai naudojant SHA256:

https://prnt.sc/v0e2y0

# Kaip veikia programa?

Programa veikia tokiu principu, kad stringas pakeiciamas i ascii value ir tada atliekamos skirtingos operacijos, kurios apkeitineja sio stringo simbolius. Veliau gautas hashas yra pakeiciamas i hexidecimal value ir idedamas i stringstreama. Toliau vykdomas ciklas, kuris padeda hashui but ne ilgesniam kaip 64 simboliu. **hashing** funkcijos rezultatas yra musu 64 simboliu hashas.

# Pseudo kodas

set starting value to 8

for every symbol in text
    change string in to ASCII value number
    multiply value2 by itself and add it to the value
    divide value by value2 and subract it from value
    shift value bits by 5 positions in to left side
    divide value by value2, substract it from value + 14 and then multiply by value2/4, finnaly substract all this from value
    
shift value bits by 2 positions in to the right side

create a stringstream

turn value in to hexadecimal number and put it in stringstream

make a copy of stringstream

while length of stringstream isn't 64
    for every symbol in strinstream
        multiply every symbol by itself and then multiply it by value square
        create an empty stringstream
        turn every symbol in to hexadecimal value
        put changed values in to stringstream and add it to the hashOut string
    if length of new string is longer than 64
        substract it to 64
    
# Kaip naudoti programa?

1. Paleidus programa gauname opcijas pasirinkti, ar inputa ives pats user, ar norime skaityti is failo, kuris ivedamas kaip cmd argumentas, ar norime patikrinti koliziju kieki su random stringais, arba atlikti testa.

2. 1 - ivedimas ranka ir gauname is karto hasha 64 simboliu ilgio.

3. 0 - skaitymas su failu, kuris perduodamas per cmd.

4. 2 - random stringu collisions testas.

5. 3 - atlikti testa.

# "Testai"

Testas I - konstitucijos eiluciu hashinimas - pavyko. Rezultatas atsiranda "results.txt" faile.

https://prnt.sc/uzzwq6

Zemiau esanciuose testuose random stringu count yra 100000, o ilgis 5.

                                |
                                V
                 
Testas II - collision'u testas su random simboliu stringais - tikriausiai pavyko. Rezultatas yra collisionu kiekis, kuris isvedamas **cout** pagalba.

https://prnt.sc/uzzy0b 

Vykdymo laikas: 5.642s

Testas III - Išveda minimalią, maksimalią ir vidurkines "skirtingumo" reikšmes naudojant 5 simboliu ilgumo stringus, kuriu vienas simbolis skiriasi kiekvienoje poroje.

https://prnt.sc/v0e83f

Min diff: 8.59375

Max diff: 40.8203

Average diff: 27.9595

Vykdymo laikas: 9.695s
