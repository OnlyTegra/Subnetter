# Subnetter

Subnetter è un semplice programma scritto in C++ che permette di analizzare e suddividere una rete IP in sottoreti di uguale dimensione (FLSM - Fixed Length Subnet Mask).


---

## 📌 Funzionalità

- Parsing di indirizzi IPv4 (formato `A.B.C.D`)
- Supporto per CIDR (es. `/24`)
- Calcolo della subnet mask 
- Suddivisione della rete in subnet di dimensione uguale (da implementare)
- Validazione base degli indirizzi IP (da completare)

---

## 🛠️ Struttura del progetto

Il progetto è basato su una classe principale:

- `ipAddress`
  - Gestione dell’indirizzo IP
  - Parsing da stringa
  - Calcolo subnet mask
  - Utility di stampa e conversione

---

## 🚀 Esempio di utilizzo

```cpp
ipAddress ip("192.168.1.0", 24);

std::cout << ip.print() << std::endl;
std::cout << ip.getSubnetMask() << std::endl;
