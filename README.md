# Pirmas-Projektas
## V.04
C++ programa skirta išvesti galutinius balus norimam studentų skaičiui.

Šioje versijoje nauja: 
- Naudojamas ne tik vector bet ir list tipo konteineris studentų duomenims saugoti
- Atliekama programos veikimo greičio (spartos) analizė vector ir list konteineriams:
    - duomenų nuskaitymui iš failų
    - studentų grupavimui į dvi grupes/kategorijas (Geresnio balo (>=5) ir žemesnio balo (<5) )

### Spartos analizė
- AMD Ryzen 7 4800U with Radeon Graphics 1.80 GHz procesorius
- 16,0 GB RAM
- 1 TB SSD

|        |             | 1000        | 10000       | 100000      | 1000000    | 10000000  |
|--------|-------------|-------------|-------------|-------------|------------|-----------|
| Vector | Nuskaitymas | 0.0009076 s | 0.0480109 s | 0.417809 s  | 2.51257 s  | 22.9082 s |
|        | Grupavimas  | 0.0003572 s | 0.0190066 s | 0.338207 s  | 2.97468 s  | 32.4886 s |
| List   | Nuskaitymas | 0.0009997 s | 0.0380274 s | 0.437175 s  | 2.74462 s  | 23.7884 s |
|        | Grupavimas  | 0.0002076 s | 0.0100214 s | 0.162039 s  | 1.24929 s  | 12.3308 s |

### Naudojimas:
Paleidus programą bus prašoma:
- Pasirinkti ar norite generuoti failą
Jei pasirenkate generuoti failą prašoma:
- Įvesti kiek pažymių generuoti studentams
Jei pasirenkate negeneruoti failo prašoma:
- Įvesti studentų skaičių 
- Įvesti studento vardą bei pavardę
- Pasirinkti ar pažymiai bus įvedami naudotojo ar sugeneruota programos
    - Suvesti norimus pažymius baigus įvedant '0'bei įvesti egzamino rezutatą
    - Įvesti norimo sugeneruoti pažymių skaičių
- Pasirinkti ar galutinį balą skaičiuoti pagal vidurkį ar medianą

### Reikalavimai įvedimui:
- Įvedant studentų skaičių, pažymių skaičių, egzamino balą nepriimamos raidės ar simbolių reikšmės
- Nepriimami kiti atsakymai nei pateikia dviejų pasirinkimų klausimas 
    - Leidžiama tik 'g' ar 'n' renkantis duomenis imti iš failo/be failo
    - Leidžiama tik 'v' ar 'm' renkantis vidurkį/medianą
    - Leidžiama tik 'a' ar 'p' renkantis naudotojo/atsitiktinį pažymių suvedimą

### Rezultato pavyzdys:
- Ivedus pažymius rankomis
<img width="253" alt="image" src="https://user-images.githubusercontent.com/113300842/195715872-0b732e41-bbe9-495c-9c1b-ef1e6eda8270.png">
- Greičio analizė generuojant failą v.03 versijoje tik su vektoriais
<img width="353" alt="image" src="https://user-images.githubusercontent.com/113300842/195781990-b280cf2b-9496-40f9-a0a5-23003cd3f300.png">









