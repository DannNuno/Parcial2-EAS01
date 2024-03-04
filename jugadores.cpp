#include <iostream>
#include <string>
#include <cstdlib> // Función rand().
#include <ctime>   // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador
{
public:
    int vida;
    int ataque;
    string nombre;

    Jugador *ult_ataque;

    Jugador();
    Jugador(int hp, int atq, string nom);

    void atacar(Jugador atacante, Jugador *atacado);
};

int main()
{
    srand(time(0)); // Seed para generar valores aleatorios

    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque.
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina.
        No importa quien ataca primero.
    */
    Jugador p1(10, 4, "player 1");
    Jugador p2(14, 3, "player 2");

    while (p1.vida > 0 && p2.vida > 0)
    {
        if (p1.vida > 0)
        {
            p1.atacar(p1, &p2);
        }
        if (p2.vida > 0)
        {
            p2.atacar(p2, &p1);
        }
    }
    if (p1.vida > 0)
    {
        cout << "ganador: " << p1.nombre << endl;
    }
    if (p2.vida > 0)
    {
        cout << "ganador: " << p2.nombre << endl;
    }

    return 0;
}

Jugador::Jugador()
{
    vida = 100;
    ataque = 5;
    nombre = "No definido";
}

Jugador::Jugador(int hp, int atq, string nom)
{
    if (hp <= 200 && hp >= 0)
    {
        vida = hp;
    }
    else
    {
        if (hp > 200)
        {
            vida = 200;
        }
        if (hp < 0)
        {
            vida = 1;
        }
    }
    if (atq <= 20 && atq >= 0)
    {
        ataque = atq;
    }
    else
    {
        if (atq > 20)
        {
            ataque = 20;
        }
        if (atq < 0)
        {
            ataque = 1;
        }
    }
    nombre = nom;
    /*
        Asignar los parámetros recibidos a las propiedades del objeto.
        No se pueden asignar valores negativos a hp y attack.
        Máximo 200 hp y 20 attack
    */
}

void Jugador::atacar(Jugador atacante, Jugador *atacado /* Agregar parámetros para atacar a otro Jugador */)
{
    int x = rand() % 1000;

    if (x > 200)
    {
        atacado->vida = atacado->vida - atacante.ataque;
        cout << this->nombre << " atacó a " << atacado->nombre << " e hizo " << this->ataque << " de daño, vida restante de " << atacado->nombre << " = " << atacado->vida << endl;
    }
    else
    {
        cout << this->nombre << " atacó a " << atacado->nombre << " pero fallo, vida restante de " << atacado->nombre << " = " << atacado->vida << endl;
    }

    atacado->ult_ataque = &atacante;
}

/*
    El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
    Existe un 20% de probabilidad de que el ataque falle y no haga daño.
    Se debe mostrar lo que pasó en cada ataque:
    nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
    nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
    El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
*/
/*
Nota:
    int x = rand() % 1000; asigna un valor aleatorio entre 0 y 999 a x;
    Puedes usar esto para la probabilidad del ataque.
  */
