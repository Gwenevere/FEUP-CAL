#include <iostream>
#include "Agency.h"
#include "Client.h"
#include<limits.h>
#include "Date.h"

using namespace std;

void Agency::introMenu() {

	int opcao;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Bem vindo a nossa agencia de viagens!                    |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
	cout << "+----------------------------------------------------------+ \n";
	cout << "| 1 - Gest�o de Clientes                                   |\n";
	cout << "| 2 - Gest�o de Viagens                                    |\n";
	cout << "| 3 - Sugestao de Alojamento                               |\n";
	cout << "| 4 - Sugest�o de M�todo de Deslocamento				    |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> opcao;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
		cout << "Pressione Enter para voltar ao menu" << endl;
		cin.get();
	}

	switch (opcao) {

	case 0:
		return;
		break;

	case 1:
		menuCliente();
		cin.get();
		cin.get();
		break;

	case 2:
		menuTrip();
		cin.get();
		cin.get();
		break;

	case 3:
		cin.get();
		cin.get();
		break;


		break;

	default:
		cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";


	}

}

void Agency::menuCliente() {


	int opcaocliente;
	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com os clientes             |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+ \n";
		cout << "| 1 - Adicionar Cliente                                    |\n";
		cout << "| 2 - Apagar Cliente					                    |\n";
		cout << "| 3 - Ver Viagem de Cliente Pretendido                     |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";

		cin >> opcaocliente;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}
		switch (opcaocliente) {

		case 0:
			return;
			break;

		case 1:
			adicionaCliente();
			cin.get();
			cin.get();
			break;
		
		case 2:	
			removeCliente();
			cin.get();
			cin.get();
			break;
	case 3:
			pesquisaViagemCliente();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";


		}

	}
}


void Agency::adicionaCliente() {

	
	string nomeCliente;
	int telemovel;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o seu nome?                                       |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nomeCliente);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual o seu numero de telemovel?                          |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> telemovel;

	Client * novocliente = new Client(nomeCliente, telemovel);
	addClients(novocliente);
}

void Agency::removeCliente() {
		
	string clienteremover;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o cliente a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, clienteremover);

	for (unsigned int i = 0; i < getClientes().size(); i++)
	{
		if (getClientes()[i]->getName() == clienteremover)
			clientes.erase(clientes.begin() + i);
	}
	cout << endl << "O cliente foi removido com sucesso" << endl;
	cout << "Pressione Enter para regressar" << endl;
	cin.get();
	return;


}

void Agency::pesquisaViagemCliente() {

	string clientName;

	cout << "+-------------------------------------------------------------------+\n";
	cout << "|Qual � o cliente sobre o qual pretende ver informa��es da Viagem : |\n";
	cout << "+-------------------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, clientName);

	for(unsigned int i = 0; i < getClientes().size(); i++){

		if(getClientes()[i]->getName() == clientName){ //there's a warning here, i dont know how to remove it

			cout << clientName <<"\n";
			cout << "Date of Departure : " << getClientes()[i]->getTrip().getDepartureDate().getString() << "\n";
			cout << "From : " << getClientes()[i]->getTrip().getFlights()[0]->getOrigin().getName() << "\n";
			cout << "To : " << getClientes()[i]->getTrip().getFlights()[1]->getOrigin().getName() << "\n";
			cout << "Date of Departure : " << getClientes()[i]->getTrip().getArrivalDate().getString() << "\n";
			cout << "Staying at : " << getClientes()[i]->getTrip().getHotel().getName() << "\n";
			cout << " Cost :" << getClientes()[i]->getTrip().getCost() << "\n";
			cout << " Distance : " << getClientes()[i]->getTrip().getDistance() << "\n";
		}
	}
}

void Agency::menuTrip(){

int opcaotrip;

while (true) {
	cout << "+----------------------------------------------------------+\n";
	cout << "| Escolha o que pretende fazer com a viagem                |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Adicionar Viagem                                     |\n";
	cout << "| 2 - Apagar Viagem					                    |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> opcaotrip;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
		cout << "Pressione Enter para voltar ao menu" << endl;
		cin.get();
	}

	switch (opcaotrip) {

	case 0:
		return;
		break;

	case 1:
		adicionaTrip();
		cin.get();
		cin.get();
		break;

	case 2:
		removeTrip();
		cin.get();
		cin.get();
		break;

	default:
		cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";


	}

}
}

void Agency::adicionaTrip() {


	string dataInicio;
	string dataFim;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual � a data de inicio da viagem?  (Formato: dd/mm/aa)  |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> dataInicio;
	Date *dataInicial = new Date(dataInicio);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual � a data de fim da viagem?  (Formato: dd/mm/aa)     |\n";
	cout << "+----------------------------------------------------------+\n";

	cin >> dataFim;
	Date *dataFinal = new Date(dataFim);

	Trip * novaTrip = new Trip(*dataInicial, *dataFinal);
	addTrips(novaTrip);
}


void Agency::removeTrip() {

	string tripremover;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a viagem a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, tripremover);

	for (unsigned int i = 0; i < getTrips().size(); i++)
	{
		if (getTrips()[i]->getID() == stoi(tripremover))
			trips.erase(trips.begin() + i);
	}
	cout << endl << "A viagem foi removida com sucesso" << endl;
	cout << "Pressione Enter para regressar" << endl;
	cin.get();
	return;


}
