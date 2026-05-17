# Sistema Gestionale per la Manutenzione Condominiale
Progetto realizzato per l'esame di Programmazione e Strutture Dati presso l'Università degli Studi di Salerno (Anno Accademico 2025-2026).
Team di Sviluppo (Classe PEU-Z):
- Urciuolo Andrea
- Verosimile Alessandro
- Sorbo Samuele

## Descrizione del Progetto
Il software è un sistema gestionale concepito per ottimizzare la pianificazione e il tracciamento degli interventi di manutenzione all'interno di complessi condominiali. Il sistema permette di raccogliere le richieste di intervento dei condomini, organizzarle in base alla loro urgenza e assegnarle ai tecnici disponibili, monitorando lo stato di avanzamento dei lavori ed evitando conflitti di pianificazione temporale.

## Guida all'Utilizzo del Software
**_Nota di Compatibilità_**: Il sistema, incluso il file Makefile, è stato sviluppato e testato esclusivamente per sistemi operativi Windows. Non si garantisce il corretto funzionamento o la corretta compilazione su piattaforme Linux o macOS.
### Avvio del Programma
Apri il terminale di sistema, posizionati nella cartella principale del progetto ed esegui l'applicazione passando uno dei tre parametri operativi richiesti:
```bash
cd Manutenzione Condominio_PSD
.\manutenzione [parametro]
```
**Parametri di Avvio consentiti**:
* --exe : Modalità Standard. Avvia l'applicazione normalmente tramite interfaccia a riga di comando (CLI) guidata da menu testuali.
* --dev : Modalità Sviluppo. Popola automaticamente la memoria all'avvio con un set di dati di test (100 richieste, 100 tecnici e 20 interventi) per velocizzare i test manuali.
* --test : Modalità Testing. Avvia esclusivamente l'esecuzione delle test suite mostrando a schermo lo stato delle strutture dati allocate per il debugging.
