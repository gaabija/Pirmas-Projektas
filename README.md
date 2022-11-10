# Pirmas-Projektas
C++ programa skirta išvesti galutinius balus norimam studentų skaičiui.
## v1.0
Šioje versijoje nauja: 
- paruošta cmake CMakeLists.txt įdiegimo instrukcija
- optimizuoti algoritmai vektoriaus studentų dalijimo procedūrai
- išmatuota programos veikimo sparta priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:
     - 1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "zemesnioBalo" ir "geresnioBalo". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (zemesnioBalo).
    - 2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "zemesnioBalo". Tokiu būdu, jei studentas yra žemesnio balo, jį turime įkelti į naująjį "zemesnioBalo" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik geresnio balo.
    
|              | N      | 1000 | 10000       | 100000      | 1000000    | 10000000  |
|--------------|--------|------|-------------|-------------|------------|-----------|
| 1 strategija | Vector | 0 s  | 0.0029944 s | 0.0297454 s | 0.339064 s | 3.68693 s |
|              | List   | 0 s  | 0.0029997 s | 0.0320471 s | 0.348483 s | 4.02268 s |
| 2 strategija | Vector | 0 s  | 0.0031922 s | 0.0339141 s | 0.387087 s | 3.64011 s |
|              | List   | 0 s  | 0.003989 s  | 0.0433154 s | 0.414128 s | 4.09393 s |

### Naudojimas:
Paleidus programą bus prašoma:
- Pasirinkti ar norite dirbti su failu

Jei pasirenkate dirbti su failu prašoma:
- Pasirinkti ar galutinį balą skaičiuoti pagal vidurkį ar medianą
- Ivesti studentu skaičių
- Pasirinkti ar failą nuskaityti ar sugeneruoti

Jei pasirinkote generuoti failą:
- Įvesti kiek pažymių generuoti studentams
Jei pasirenkate negeneruoti failo, jis nuskaitomas.

Jei pasirenkate nedirbti su failu prašoma:
- Įvesti studentų skaičių 
- Įvesti studento vardą bei pavardę
- Pasirinkti ar pažymiai bus įvedami naudotojo ar sugeneruota programos
    - Suvesti norimus pažymius baigus įvedant '0' bei įvesti egzamino rezutatą
    - Įvesti norimo sugeneruoti pažymių skaičių

### Reikalavimai įvedimui:
- Įvedant studentų skaičių, pažymių skaičių, egzamino balą nepriimamos raidės ar simbolių reikšmės
- Nepriimami kiti atsakymai nei pateikia dviejų pasirinkimų klausimas 
    - Leidžiama tik 'f' ar 'n' renkantis duomenis imti iš failo/be failo
    - Leidžiama tik 'g' ar 'n' renkantis faila generuoti ar nuskaityti
    - Leidžiama tik 'v' ar 'm' renkantis vidurkį/medianą
    - Leidžiama tik 'a' ar 'p' renkantis naudotojo/atsitiktinį pažymių suvedimą

## Versijos:

### v0.4
Šioje versijoje nauja: 
- Galimybė dirbti ne tik su vietoje generuojamu failu, bet ir su jau esančio failo nuskaitymu
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

### v0.3
Šioje versijoje nauja:
- Galimybė generuoti norimo dydžio studentų įrašų failus
- Studentų įrašai surūšiuojami pagal balą į dvi kategorijas ir išvedami į du skirtingus failus
- Atliekama programos veikimo greičio (spartos) analizė:
    - failų kūrimui
    - duomenų nuskaitymui iš failų
    - studentų rūšiavimui į dvi grupes/kategorijas
    - studentų išvedimui į du naujus failus
-Greičio analizė
   ![image](https://user-images.githubusercontent.com/113300842/200825524-5091cb1d-bc9a-4153-8146-c70ff02adeec.png)
### v0.2
v.01 papildytas galimybe duomenis imti iš nuskaitomo failo, pridėtas klaidos jei failas neatsidarė sugavimas, failas išskaidytas į .h bei .cpp failus, lengvesniam skaitomumui.
### v0.1
Galutinis balas skaičiuojamas pagal duotą formulę
![image](https://user-images.githubusercontent.com/113300842/200827710-621352fe-2d3f-4ea7-8ad5-f649ed2aaf2d.png)
(vietoj vidurkio gali būti imama ir mediana)
Šioje versijoje yra 2 .cpp failai - masyvo bei vektoriaus realizacijos studento namų darbų pažymiams saugoti.










