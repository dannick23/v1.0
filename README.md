# v1.0
v0.2 testavimo specifikos: 

kursiokai1.txt - 1 000 eil. po 8 elementus. 33.6KB
kursiokai2.txt - 10 000 eil. po 8 elementus. 355KB
kursiokai3.txt - 100 000 eil. po 8 elementus. 3.65MB
kursiokai4.txt - 1 000 000 eil. po 8 elementus. 38.5MB
kursiokai5.txt - 10 000 000 eil. po 8 elementus.  404MB
Buvo naudojama 1 gija ryzen 5 2600 procesoriaus, generavimo metu ji buvo pilnai utilizuojama(aprox 8% CPU)
Imanoma tolimesne optimizacija naudojant daugiau negu 1 gija.

Laikai per kuriuos generuojami failai buvo: 
generation of file kursiokai1.txt started
generation of file kursiokai1.txt ended, time elapsed: 0.0368046s
generation of file kursiokai2.txt started
generation of file kursiokai2.txt ended, time elapsed: 0.374132s
generation of file kursiokai3.txt started
generation of file kursiokai3.txt ended, time elapsed: 3.75611s
generation of file kursiokai4.txt started
generation of file kursiokai4.txt ended, time elapsed: 37.7959s
generation of file kursiokai5.txt started
generation of file kursiokai5.txt ended, time elapsed: 373.319s

vector test output(baseline):
read of file kursiokai1.txt start
read of filekursiokai1.txtend, elapsed time: 0.0622527s
read of file kursiokai2.txt start
read of filekursiokai2.txtend, elapsed time: 0.631633s
read of file kursiokai3.txt start
read of filekursiokai3.txtend, elapsed time: 6.68215s
read of file kursiokai4.txt start
read of filekursiokai4.txtend, elapsed time: 70.4769s
read of file kursiokai5.txt start
read of filekursiokai5.txtend, elapsed time: 638.035s
Sort of students by avg grades start
sort of students by avg grades end, elapsed time: 450.419s
--------------------------------------------------------------------------------------------------------------------
list test output:
read of file kursiokai1.txt start
read of filekursiokai1.txtend, elapsed time: 0.0478161s
read of file kursiokai2.txt start
read of filekursiokai2.txtend, elapsed time: 0.542275s
read of file kursiokai3.txt start
read of filekursiokai3.txtend, elapsed time: 4.81959s
read of file kursiokai4.txt start
read of filekursiokai4.txtend, elapsed time: 48.548s
read of file kursiokai5.txt start
read of filekursiokai5.txtend, elapsed time: 490.365s
Sort of students by avg grades start
sort of students by avg grades end, elapsed time: 425.044s
--------------------------------------------------------------------------------------------------------------------
deque test output:
read of file kursiokai1.txt start
read of filekursiokai1.txtend, elapsed time: 0.0529919s
read of file kursiokai2.txt start
read of filekursiokai2.txtend, elapsed time: 0.496673s
read of file kursiokai3.txt start
read of filekursiokai3.txtend, elapsed time: 4.96847s
read of file kursiokai4.txt start
read of filekursiokai4.txtend, elapsed time: 50.38s
read of file kursiokai5.txt start
read of filekursiokai5.txtend, elapsed time: 508.478s
Sort of students by avg grades start
sort of students by avg grades end, elapsed time: 427.574s

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

v1.0 testavimo specifikos:
siuo metu as isvedamo rezultato nededu i joki konteineri, as tikrinu naudojantis bool metodu kuris variantas tas studentas yra
ir atitinkamai nusiunciu jo duomenis i faila.tolimesniam testavimui naudosiu "kursiokai4.txt" faila, nes man paprasciausiai neuzteks operatyvios atminties
kiekio atlikti pirmaja strategija.

Pirma baseline specifiku:
generation of file kursiokai4.txt started
generation of file kursiokai4.txt ended, time elapsed: 37.6412s
read of file kursiokai4.txt start
read of file kursiokai4.txt end, elapsed time: 63.3513s
--------------------------------------------------------------------------------------------------------------------
Programa naudoja 451MB patalpintiem duomenim vektoriuje is failo.
Talpinant i 2 naujus vektorius(vargsiuku/kieteku):
Sort of students by avg grades start
sort of students by avg grades end, elapsed time: 37.1705s
write file vargsiukai.txt started
write file vargsiukai.txt ended, elapsed time: 16.0716s
write file kietekai.txt started
write file kietekai.txt ended, elapsed time: 22.5876s
programa dabar naudoja 999MB operatyvios atminties.
--------------------------------------------------------------------------------------------------------------------
Talpinant i 2 naujus list(vargsiuku/kieteku):
Programa naudoja 1014MB patalpintiem duomenim liste is failo.
Sort of students by avg grades start
sort of students by avg grades end, elapsed time: 11.0478s
write file vargsiukai.txt started
write file vargsiukai.txt ended, elapsed time: 15.7713s
write file kietekai.txt started
write file kietekai.txt ended, elapsed time: 22.4769s
programa dabar naudoja 2GB operatyvios atminties.
--------------------------------------------------------------------------------------------------------------------
Programa naudoja 656MB patalpintiem duomenim deque is failo.
Sort of students by avg grades start
sort of students by avg grades end, elapsed time: 10.5376s
write file vargsiukai.txt started
write file vargsiukai.txt ended, elapsed time: 16.0861s
write file kietekai.txt started
write file kietekai.txt ended, elapsed time: 23.0556s
programa dabar naudoja 1.3GB operatyvios atminties.
Dabar persiorientuojame i antra strategija.
Antra strategija neveikia, bandant istrinti betkuriame konteinery objekta meta C2679 klaida.
