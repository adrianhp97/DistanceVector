# Distance Vector
Distance Vector Implementation

## Overview

1. [Install prerequisites](#prerequisites)

    Before installing project make sure the following prerequisites have been met.

2. [Project Tree](#project-tree)

    Directory structure of this project

3. [Install and running the project](#installing)

    We’ll download the code from its repository on GitHub.

4. [How it works](#how-it-works)

	How node representation and how to send information

5. [Answers](#answers)

	Answer for questions in specification

6. [Pembagian kerja](#authors)

    See men behind the project and their contribution

---

### Prerequisites

What things you need to install the software and how to install them

Installed :
- `GNU Make` (https://www.gnu.org/software/make/)
- `g++` (https://gcc.gnu.org/)
---

### Project tree

```sh
.
├── Makefile
├── README.md
├── data
└── src
```
---

### Installing

This project is intended to run on Linux/Mac workspace.

```
git clone https://github.com/adrianhp97/DistanceVector.git
cd DistanceVector
make
```

### Running
```
./DistanceVector
```
---

### How it works
Node disimulasikan dengan array of struct TableRow, struct TableRow terdiri dari integer distance dan nexthop. Setiap TableRow memiliki array untuk merepresentasikan routing table. Indeks array adalah nomor simpul.
Proses pengiriman pesan:
1. Menerima input skenario pengiriman pesan dari user
2. Jika node pengirim memiliki distance = 1 dengan penerima, maka lanjutkan, jika tidak = 1, maka abaikan
3. Melakukan looping pada array TableRow di array, jika distance tidak sama dengan -1, 1, dan 0, maka lanjutkan proses.
4. Jika distance TableRow dari indeks pengirim memiliki nilai lebih kecil dari distance-1 indeks penerima, maka nilai distance indeks pengirim diisi ke distance indeks penerima. Nexthop pada TableRow penerima diisi dengan pengirim.
5. Jika distance TableRow pengirim memiliki nilai sama dengan distance-1 TableRow penerima dan indeks pengirim lebih kecil dari nexthop di tabel penerima, maka nexthop di tabel penerima diisi dengan indeks pengirim.

### Answers
1. Pada distance vector, setiap router mengirimkan informasi dari list router yang diketahui dan jaraknya kepada router tentangganya. Setiap router hanya mengetahui informasi dari router bertetangga dengannya.
Pada link state, setiap router memberikan informasi dan interfacenya kepada network yang terhubung. Baik router yang bertetangga, maupun router yang terdapat di network. Setiap router mengetahui semua topologi network sampai ke setiap routernya dan keterhubungannya.
Pada network kecil dimana jumlah router lebih kecil dari 100, maka routing protocol lebih bagus untuk digunakan. Sedangkan untuk network dengan skala besar, maka link state routing protocol lebih bagus untuk digunakan.
2. Pada saat ini yang lebih banyak digunakan adalah link-state di mana implementasinya adalah OSPF. Lebih populer dari EIGRP/distance vector karena EIGRP merupakan solusi dari Cisco sehingga tidak tersedia luas kepada semua vendor. Sedangkan OSPF adalah routing protocol open standard yang di support oleh kebanyakan vendor yang ada saat ini.

---
## Pembagian kerja

* **Winarto [13515061]** - [yowinarto](https://github.com/yowinarto)
Struct TableRow, check node validity, check send info condition, pengiriman informasi
* **Ray Andrew [13515073]** - [rayandrews](https://github.com/rayandrews)
Input node dari user, check edge validity, check send info condition, pengiriman informasi
* **Adrian Hartarto Pramudita [13515091]** - [nathanchrs](https://github.com/adrianhp97)
Save input ke node, check scenario validity, check send info condition, pengiriman informasi
