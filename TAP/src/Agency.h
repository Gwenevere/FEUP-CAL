
#ifndef SRC_AGENCY_H_
#define SRC_AGENCY_H_

#include "City.h"
#include "Client.h"
#include "Coordinates.h"
#include "Date.h"
#include "Graph.h"
#include "Hotel.h"
#include "Trip.h"
#include <fstream>
#include <sstream>
#include <vector>


class Agency {
private:
	Graph<City> graph;
	vector<Client*> clientes;
	vector<Trip*> trips;

public:
	Agency();
	virtual ~Agency();
	void readFromFiles();
	Graph<City> getGraph();
	void printShortestPath(const City origin, const City destiny);

	//ADD METHODS
	void addClients(Client* cliente);
	void addTrips(Trip* viagem);

	//GET METHODS
	vector<Client*> getClientes() { return clientes; }
	vector<Trip*> getTrips() { return trips; }

	//MENUS
	void introMenu();
	void menuCliente();
	void menuTrip();
	void menuAlojamento();
	void menuDeslocamento();

	void adicionaCliente();
	void removeCliente();

	void adicionaTrip();
	void removeTrip();
};

#endif /* SRC_AGENCY_H_ */