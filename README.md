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

https://prnt.sc/uzzub4)https://prnt.sc/uzzub4

Testas I - konstitucijos eiluciu hashinimas - pavyko. Rezultatas atsiranda "results.txt" faile.

https://prnt.sc/uzzwq6

Zemiau esanciuose testuose random stringu count yra 100000, o ilgis 5.

                                |
                                V
                 
Testas II - collision'u testas su random simboliu stringais - tikriausiai pavyko. Rezultatas yra collisionu kiekis, kuris isvedamas **cout** pagalba.

https://prnt.sc/uzzy0b

Testas III - Išveda minimalią, maksimalią ir vidurkines "skirtingumo" reikšmes naudojant 5 simboliu ilgumo stringus, kuriu vienas simbolis skiriasi kiekvienoje poroje.

https://prnt.sc/uzzyu3
