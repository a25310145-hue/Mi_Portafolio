#include <iostream>
#include <stdio.h>
using namespace std;

/* -------- CLASE LAVADORA -------- */
class Lavadora{
	private:
		string marca;
		string modelo;
		string numeroSerie;
		float capacidad;

	public:
		Lavadora();
		void setMarca(string m);
		string getMarca();

		void setModelo(string m);
		string getModelo();

		void setNumeroSerie(string n);
		string getNumeroSerie();

		void setCapacidad(float c);
		float getCapacidad();
};

// DEFINICIONES FUERA

Lavadora::Lavadora(){
	marca="";
	modelo="";
	numeroSerie="";
	capacidad=0;
}

void Lavadora::setMarca(string m){
	this->marca = m;
}
string Lavadora::getMarca(){
	return this->marca;
}

void Lavadora::setModelo(string m){
	this->modelo = m;
}
string Lavadora::getModelo(){
	return this->modelo;
}

void Lavadora::setNumeroSerie(string n){
	this->numeroSerie = n;
}
string Lavadora::getNumeroSerie(){
	return this->numeroSerie;
}

void Lavadora::setCapacidad(float c){
	this->capacidad = c;
}
float Lavadora::getCapacidad(){
	return this->capacidad;
}


/* -------- CLASE REVISTA -------- */
class Revista{
	private:
		string articulo;
		string autor;
		int volumen;
		int numero;
		string fechaPublicacion;

	public: Revista(){
		articulo="";
		autor="";
		volumen=0;
		numero=0;
		fechaPublicacion="";
	}

	public: void setArticulo(string a){ articulo=a; }
	public: string getArticulo(){ return articulo; }

	public: void setAutor(string a){ autor=a; }
	public: string getAutor(){ return autor; }

	public: void setVolumen(int v){ volumen=v; }
	public: int getVolumen(){ return volumen; }

	public: void setNumero(int n){ numero=n; }
	public: int getNumero(){ return numero; }

	public: void setFechaPublicacion(string f){ fechaPublicacion=f; }
	public: string getFechaPublicacion(){ return fechaPublicacion; }
};


/* -------- MAIN -------- */
int main(int argc, char** argv) {

	Lavadora lav;              // objeto normal
	Revista *rev = new Revista(); // apuntador

	int opcion, clase;

	do{
		cout << "\n------ MENU ------\n";
		cout << "1. Capturar\n";
		cout << "2. Mostrar\n";
		cout << "3. Salir\n";
		cin >> opcion;

		if(opcion == 1 || opcion == 2){
			cout << "\n1. Lavadora\n";
			cout << "2. Revista\n";
			cin >> clase;
		}

		switch(opcion){

		case 1: // CAPTURAR
			if(clase == 1){
				string marca, modelo, serie;
				float capacidad;

				cout << "Marca: ";
				cin >> marca;
				cout << "Modelo: ";
				cin >> modelo;
				cout << "Numero de serie: ";
				cin >> serie;
				cout << "Capacidad: ";
				cin >> capacidad;

				lav.setMarca(marca);
				lav.setModelo(modelo);
				lav.setNumeroSerie(serie);
				lav.setCapacidad(capacidad);

			}else{
				string articulo, autor, fecha;
				int volumen, numero;

				cout << "Articulo: ";
				cin >> articulo;
				cout << "Autor: ";
				cin >> autor;
				cout << "Volumen: ";
				cin >> volumen;
				cout << "Numero: ";
				cin >> numero;
				cout << "Fecha: ";
				cin >> fecha;

				rev->setArticulo(articulo);
				rev->setAutor(autor);
				rev->setVolumen(volumen);
				rev->setNumero(numero);
				rev->setFechaPublicacion(fecha);
			}
			break;

		case 2: // MOSTRAR
			if(clase == 1){
				cout << "\n--- LAVADORA ---\n";
				cout << "Marca: " << lav.getMarca() << endl;
				cout << "Modelo: " << lav.getModelo() << endl;
				cout << "Serie: " << lav.getNumeroSerie() << endl;
				cout << "Capacidad: " << lav.getCapacidad() << endl;

			}else{
				cout << "\n--- REVISTA ---\n";
				cout << "Articulo: " << rev->getArticulo() << endl;
				cout << "Autor: " << rev->getAutor() << endl;
				cout << "Volumen: " << rev->getVolumen() << endl;
				cout << "Numero: " << rev->getNumero() << endl;
				cout << "Fecha: " << rev->getFechaPublicacion() << endl;
			}
			break;

		case 3:
			cout << "Saliendo...\n";
			break;

		default:
			cout << "Opcion invalida\n";
		}

	}while(opcion != 3);

	delete rev;
	return 0;
}