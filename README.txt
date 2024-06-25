SPACE RIDER

Instruktion för att bygga och testa:
Spelet är utvecklat i Windows med Visual Studio Code. Programmet kompileras med en
makefil som ligger i rotkatalogen tillsammans med de andra mapparna. I include ligger
alla header-filer och i src ligger alla cpp-filer, inklusive main. I resources hittar man
ljudfiler, bildfiler och fonter under respektive underkatalog. Dessa behövs givetvis för att
köra spelet.


Spelet:
Spelet är en klassisk modell som består av ett rymdskepp (spelaren) som färdas från
vänster till höger medans fiendeskepp kommer motsatt håll och skjuter mot spelaren.
Spelarens skepp förflyttas med piltangenterna och skjuter med blanksteg. Spelaren har
tre liv som räknas ner varje gång den blir träffad av antingen fiendeskott eller kollision
med fiendeskepp. En poängtavla finns också som räknar hur många fiendeskepp
spelaren skjutit ner. En poäng ges per nedskjutet fiendeskepp. När tre liv förbrukats är
spelet slut och man erbjuds att starta om eller att stänga ner spelet.
Målet är att få så många poäng som möjligt.
