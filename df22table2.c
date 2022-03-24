const float df22table_freq[9] = {0.100000000000f,0.200000000000f,0.300000000000f,0.400000000000f,0.500000000000f,0.600000000000f,0.700000000000f,0.800000000000f,0.900000000000f};
const float df22table_bessel[9][1][6] = {
{{0.019305318724f,0.038610637448f,0.019305318724f,1.000000000000f,-1.500542894132f,0.577764169029f}},
{{0.063279764058f,0.126559528116f,0.063279764058f,1.000000000000f,-1.072229528601f,0.325348584833f}},
{{0.121194770421f,0.242389540841f,0.121194770421f,1.000000000000f,-0.691256187260f,0.176035268942f}},
{{0.189451685995f,0.378903371989f,0.189451685995f,1.000000000000f,-0.338901478669f,0.096708222647f}},
{{0.267949192431f,0.535898384862f,0.267949192431f,1.000000000000f,-0.000000000000f,0.071796769724f}},
{{0.358902425329f,0.717804850658f,0.358902425329f,1.000000000000f,0.338901478669f,0.096708222647f}},
{{0.466822864050f,0.933645728101f,0.466822864050f,1.000000000000f,0.691256187260f,0.176035268942f}},
{{0.599394528358f,1.198789056717f,0.599394528358f,1.000000000000f,1.072229528601f,0.325348584833f}},
{{0.769576765790f,1.539153531580f,0.769576765790f,1.000000000000f,1.500542894132f,0.577764169029f}}};
const float df22table_cheby[9][1][6] = {
{{0.014286648845f,0.028573297690f,0.014286648845f,1.000000000000f,-1.706250842052f,0.778194143174f}},
{{0.051200217732f,0.102400435464f,0.051200217732f,1.000000000000f,-1.354689523249f,0.612518544017f}},
{{0.104563347833f,0.209126695666f,0.104563347833f,1.000000000000f,-0.968825188510f,0.495375011426f}},
{{0.170974493340f,0.341948986680f,0.170974493340f,1.000000000000f,-0.560360829840f,0.421337367577f}},
{{0.248881151051f,0.497762302102f,0.248881151051f,1.000000000000f,-0.134714783352f,0.388006005651f}},
{{0.337882868606f,0.675765737211f,0.337882868606f,1.000000000000f,0.305123373382f,0.396353944608f}},
{{0.438119512855f,0.876239025710f,0.438119512855f,1.000000000000f,0.755164936179f,0.451074216365f}},
{{0.549483254469f,1.098966508937f,0.549483254469f,1.000000000000f,1.206055092889f,0.560978636736f}},
{{0.670228843119f,1.340457686237f,0.670228843119f,1.000000000000f,1.636102704580f,0.738969784697f}}};
const float df22table_butter[9][1][6] = {
{{0.020083365564f,0.040166731128f,0.020083365564f,1.000000000000f,-1.561018075801f,0.641351538058f}},
{{0.067455273889f,0.134910547778f,0.067455273889f,1.000000000000f,-1.142980502540f,0.412801598096f}},
{{0.131106439917f,0.262212879833f,0.131106439917f,1.000000000000f,-0.747789178259f,0.272214937925f}},
{{0.206572083826f,0.413144167652f,0.206572083826f,1.000000000000f,-0.369527377351f,0.195815712656f}},
{{0.292893218813f,0.585786437627f,0.292893218813f,1.000000000000f,-0.000000000000f,0.171572875254f}},
{{0.391335772502f,0.782671545004f,0.391335772502f,1.000000000000f,0.369527377351f,0.195815712656f}},
{{0.505001029046f,1.010002058092f,0.505001029046f,1.000000000000f,0.747789178259f,0.272214937925f}},
{{0.638945525159f,1.277891050318f,0.638945525159f,1.000000000000f,1.142980502540f,0.412801598096f}},
{{0.800592403465f,1.601184806929f,0.800592403465f,1.000000000000f,1.561018075801f,0.641351538058f}}};