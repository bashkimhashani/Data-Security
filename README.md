Universiteti Prishtinës 
Fakulteti i Inxhinierisë Elektrike dhe Kompjuterike
Siguria e të dhënave 
Grupi 19 - Albena Mehmeti, Arijana Braha, Bashkim Hashani, Dua Gashi
Sulmimi i kodit te Cezarit duke mesuar frekuencat e shkronjave nga ndonje tekst fajll.


Përshkrimi
Ky program në C++ zbaton një sulm ndaj algoritmit të Cezarit (Caesar Cipher) duke përdorur analizë të frekuencës së shkronjave për të identifikuar çelësin më të mundshëm të enkriptimit dhe për të dekriptuar automatikisht një mesazh të koduar.

Si funksionon?
Programi përbëhet nga disa funksione kryesore që punojnë së bashku për të:

1. Lexuar përmbajtjen e dy skedarëve tekstualë:
   - training.txt – një tekst "normal" i përdorur për të krijuar një model të frekuencës së shkronjave në gjuhën natyrore.
   - secret.txt – përmban mesazhin e enkriptuar që duam ta dekriptojmë.

2. Llogaritur frekuencat e shkronjave nga tekstet:
   - Llogarit përqindjen e secilës shkronjë nga a deri në z.

3. Provuar çdo çelës të mundshëm të Cezarit (0-25):
   - Për secilin çelës, dekripton mesazhin e enkriptuar.
   - Krahason frekuencat e shkronjave të mesazhit të dekriptuar me ato të modelit (training.txt).
   - Gjen çelësin që prodhon ndryshimin më të vogël në frekuencë.

4. Shfaq çelësin më të mundshëm dhe mesazhin e dekriptuar.

Funksionet kryesore

- lexoTekstin(filename)
  Lexon tërë përmbajtjen e një skedari dhe e kthen në një varg të vogëluar (lowercase).

- llogaritFrekuencat(text, freq[])
  Llogarit frekuencën e secilës shkronjë (a–z) në tekst dhe i ruan ato në një array të llojit double.

- dekriptoCezar(text, key)
  Dekodimi i mesazhit të enkriptuar me një çelës të caktuar Cezari.

- ndryshimiTotal(f1, f2)
  Krahason dy modele frekuencash dhe kthen shumën e dallimeve absolute.

- sulmoCezarin(trainingFile, encryptedFile)
  Funksioni kryesor që i bashkon të gjitha veprimet dhe shtyp rezultatin final në ekran.

Version me input nga përdoruesi (komentuar në kodin origjinal)
Në fund të kodit është një version alternativ që i jep përdoruesit mundësinë të zgjedhë nëse do të:

1. Përdorë mesazhin ekzistues në secret.txt.
2. Shkruajë një mesazh të ri të enkriptuar që pastaj do të ruhet dhe dekriptohet.

Ky version përfshin përdorimin e ofstream për të shkruar në skedar dhe është i përshtatshëm për përdorim interaktiv.
