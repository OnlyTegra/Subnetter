# Subnetter

**Subnetter** è un programma scritto in C++ che permette di analizzare un indirizzo IPv4 e suddividerlo in sottoreti di uguale dimensione (**FLSM - Fixed Length Subnet Mask**).

Il progetto utilizza una rappresentazione numerica degli indirizzi IP (`uint32_t`) per semplificare le operazioni di subnetting.

Il progetto è a scopo didattico (sia per imparare meglio il subnetting che il linguaggio c++) perciò possono esserci bug!

---

## 📌 Funzionalità

- Parsing di indirizzi IPv4 (`A.B.C.D`)
- Supporto CIDR (es. `/24`)
- Calcolo della subnet mask
- Conversione IP ↔ numero (`uint32_t`)
- Suddivisione della rete in subnet uguali (FLSM)
- Utility di stampa degli indirizzi IP
- Operazioni aritmetiche sugli IP

---

## 🛠️ Struttura del progetto

Il progetto è composto da due classi principali:

### 🔹 `ipAddress`
Gestisce completamente un indirizzo IP.
- Parsing da stringa
- Conversione numero ↔ stringa
- Calcolo subnet mask
- Stampa IP con e senza CIDR
- Accesso al valore numerico
- Operazioni interne sugli IP

---

### 🔹 `subnet`
Gestisce la suddivisione della rete.
- Riceve un IP di partenza
- Divide la rete in `nReti` sottoreti uguali
- Restituisce il risultato formattato

---

### Esempio di utilizzo

```cpp
#include "ipAddress.h"
#include "subnet.h"
#include <iostream>

int main()
{
    ipAddress ip("192.168.1.0", 24);

    std::cout << "IP: " << ip.print() << std::endl;
    std::cout << "Subnet Mask: " << ip.getSubnetMask() << std::endl;

    subnet s(ip);

    std::cout << s.execute(4) << std::endl;

    return 0;
}
```
