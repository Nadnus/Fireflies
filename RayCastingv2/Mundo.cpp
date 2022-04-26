//
// Created by hgallegos on 1/04/2022.
//

#include "Mundo.h"

void Mundo::escenario1() {
    cam.init(60,10, 600, 400,
             vec3(20,40, 80),
             vec3(0,0,0),
             vec3(0,1,0));
    cam.calcular_vectores();
    Luz luz, luz2,luz3,luz4;
    vec3 vidrio = (1,1,1);
    vec3 amarillo = (1,1,0);
    vec3 firefly1 = vec3(20,20,20);
    vec3 firefly2 = vec3(10,10,10);
    vec3 firefly3 = vec3(-10,15,15);

    luz.set(firefly2,vidrio);
    luz2.set(firefly1, vidrio);
    luz3.set(vec3(0,100,0),vidrio);
    luz4.set(firefly3,vidrio);
    luces.emplace_back(&luz);
    luces.emplace_back(&luz2);
    luces.emplace_back(&luz3);
    luces.emplace_back(&luz4);

    Esfera *esf1 = new Esfera;
    esf1->cen = firefly1; //reminder, la luz no va para abajo
    esf1->rad = 2;
    //esf1->color = vec3(250,250,210);
    esf1->color = amarillo;
    esf1->kd = 15; //no fucking idea
    esf1->ke = 15; //more = brighter
    esf1->n = 16; //curvey light
    esf1->ior =5;
    vec_objetos.emplace_back(esf1);

    Esfera *esf2 = new Esfera;
    esf2->cen = firefly2;
    esf2->rad = 2;
    esf2->color = amarillo;
    esf2->kd = 15;
    esf2->ke = 15;
    esf2->n = 16;
    esf2->ior = 15;
    vec_objetos.emplace_back(esf2);

    Esfera *esf5 = new Esfera;
    esf5->cen = firefly3;
    esf5->rad = 2;
    esf5->color = amarillo;
    esf5->kd = 15;
    esf5->ke = 15;
    esf5->n = 16;
    esf5->ior = 15;
    vec_objetos.emplace_back(esf5);

    Esfera *esf3 = new Esfera;
    esf3->cen = vec3(0,20,0);
    esf3->rad = 2;
    esf3->color = vec3(0,0,1);
    esf3->kd = 0.8;
    esf3->ke = 0.4;
    //esf3->kr = 0.9;
    esf3->n = 8;
    //vec_objetos.emplace_back(esf3);

    Plano *plano = new Plano;
    plano->n = vec3(0,1,0);
    plano->n.normalize();
    plano->d = 0;
    plano->color = vec3(1,1,1);
    plano->kd = 0.9;
    plano->ke = 0;
    vec_objetos.emplace_back(plano);

    Cilindro *cil1 = new Cilindro;
    cil1->color = vec3(0,0,0);
    cil1->pa = vec3(0,30,20);
    cil1->pb = vec3(0,0,20);
    cil1->ra = 25;
    cil1->kd = 0;
    cil1->ke = 0.4;
    //cil1->n = 6;
    cil1->ior = 1;
    vec_objetos.emplace_back(cil1);

    Cilindro *cil3 = new Cilindro;
    cil3->color = vec3(0,0,0);
    cil3->pa = vec3(0,29,20);
    cil3->pb = vec3(0,0,20);
    cil3->ra = 29;
    cil3->kd = 0;
    cil3->ke = 0.4;
    //cil1->n = 6;
    cil3->ior = 1;
    //vec_objetos.emplace_back(cil3);

    Cilindro *cil2 = new Cilindro;
    cil2->color = vec3(0,0,0);
    cil2->pa = vec3(0,35,20);
    cil2->pb = vec3(0,30,20);
    cil2->ra = 25;
    cil2->kd = 15;
    cil2->ke = 15;
    cil2->n = 6;
    cil2->ior = 0;
    vec_objetos.emplace_back(cil2);

    Esfera *esf4 = new Esfera;
    esf4->cen = vec3(5,20,20);
    esf4->rad = 2;
    esf4->color = vec3(1,1,1);
    esf4->kd = 0.9;
    esf4->ke = 0.9;
    //esf4->kr = 0.9;
    esf4->n = 16;
    //vec_objetos.emplace_back(esf4);

    cam.Renderizar( luces, vec_objetos );
}