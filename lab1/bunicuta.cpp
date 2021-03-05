#include <iostream>

using namespace std;

// n forme
// 4 tipuri de forme

// functii pentru a calcula gem si frisca pentru fiecare forma

//
//struct FormaCerc {
//    float raza;
//    float inaltime;
//};
//
//struct FormaDreptunghi {
//    float latura_mica;
//    float latura_mare;
//    float inaltime;
//};
//
//struct FormaPatrat {
//    float latura;
//    float inaltime;
//};
//
//struct FormaTriunghi {
//    float cateta_mica;
//    float cateta_mare;
//    float inaltime;
//};

struct FormaGenerala {
    float arie;
    float inaltime;
    int tipForma;
    bool esteFolositaInComanda;
};

int main() {
    FormaGenerala formeGenerala[100];
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        int tipForma;
        cin>> tipForma;
        if(tipForma == 1) {
            float raza, inaltime;
            cin>> raza >> inaltime;
            formeGenerala[i].tipForma = tipForma;
            formeGenerala[i].arie = 3.14f * raza * raza;
            formeGenerala[i].inaltime = inaltime;
            formeGenerala[i].esteFolositaInComanda = true;
        }
        else if(tipForma ==2){
            float latura_mica, latura_mare, inaltime;
            cin >> latura_mica >> latura_mare >> inaltime;
            formeGenerala[i].tipForma = tipForma;
            formeGenerala[i].arie = latura_mica * latura_mare;
            formeGenerala[i].inaltime = inaltime;
            formeGenerala[i].esteFolositaInComanda = true;
        }
        else if(tipForma ==3) {
            float latura, inaltime;
            cin >> latura >> inaltime;
            formeGenerala[i].tipForma = tipForma;
            formeGenerala[i].arie = latura * latura;
            formeGenerala[i].inaltime = inaltime;
            formeGenerala[i].esteFolositaInComanda = true;
        }
        else if(tipForma ==4) {
            float cateta_mica, cateta_mare, inaltime;
            cin >> cateta_mica >> cateta_mare>>inaltime;
            formeGenerala[i].tipForma = tipForma;
            formeGenerala[i].arie = cateta_mica * cateta_mare / 2;
            formeGenerala[i].inaltime = inaltime;
            formeGenerala[i].esteFolositaInComanda = true;
        }
    }

    int tipComanda = 0;
    cin >> tipComanda;
    while(tipComanda != 4) {
        if(tipComanda ==1) {
            //ADD
            int tipForma;
            cin>> tipForma;
            n++;
            if(tipForma == 1) {
                float raza, inaltime;
                cin>> raza >> inaltime;
                formeGenerala[n].tipForma = tipForma;
                formeGenerala[n].arie = 3.14f * raza * raza;
                formeGenerala[n].inaltime = inaltime;
                formeGenerala[n].esteFolositaInComanda = true;
            }
            else if(tipForma ==2){
                float latura_mica, latura_mare, inaltime;
                cin >> latura_mica >> latura_mare >> inaltime;
                formeGenerala[n].tipForma = tipForma;
                formeGenerala[n].arie = latura_mica * latura_mare;
                formeGenerala[n].inaltime = inaltime;
                formeGenerala[n].esteFolositaInComanda = true;
            }
            else if(tipForma ==3) {
                float latura, inaltime;
                cin >> latura >> inaltime;
                formeGenerala[n].tipForma = tipForma;
                formeGenerala[n].arie = latura * latura;
                formeGenerala[n].inaltime = inaltime;
                formeGenerala[n].esteFolositaInComanda = true;
            }
            else if(tipForma ==4) {
                float cateta_mica, cateta_mare, inaltime;
                cin >> cateta_mica >> cateta_mare>>inaltime;
                formeGenerala[n].tipForma = tipForma;
                formeGenerala[n].arie = cateta_mica * cateta_mare / 2;
                formeGenerala[n].inaltime = inaltime;
                formeGenerala[n].esteFolositaInComanda = true;
            }
            cout<< formeGenerala[n].arie * formeGenerala[n].inaltime * 2;
            cout<< formeGenerala[n].arie * formeGenerala[n].inaltime;
        }
        else if(tipComanda ==2) {
            //REMOVE
            int index;
            cin >> index;
            formeGenerala[index].esteFolositaInComanda = false;
        }
        else if(tipComanda ==3) {
            //TOTAL
            float sumaGem = 0;
            float sumFrisca = 0;
            for(int i=1; i<=n;i++) {
                if(formeGenerala[i].esteFolositaInComanda) {
                    float volum = formeGenerala[i].arie * formeGenerala[i].inaltime;
                    sumaGem = sumaGem + volum * 2;
                    sumFrisca = sumFrisca + volum;
                }
            }
            cout << sumaGem << ' ' << sumFrisca;
        }
        cin >> tipComanda;
    }

    return 0;
}
